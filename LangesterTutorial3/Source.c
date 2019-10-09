#include "ntddk.h" //Typically used in windows kernel driver development

typedef struct {
    PDEVICE_OBJECT LowerKbdDevice;
} DEVICE_EXTENSION,*PDEVICE_EXTENSION;

//The data structure that defines one packet of keyboard data, as defined by Microsoft.
typedef struct _KEYBOARD_INPUT_DATA {
    USHORT UnitId;
    //The key's scan code.
    USHORT MakeCode;
    USHORT Flags;
    USHORT Reserved;
    ULONG ExtraInformation;
} KEYBOARD_INPUT_DATA, *PKEYBOARD_INPUT_DATA;

//The keyboard virtual device to be used for filtering.
PDEVICE_OBJECT keyboardDevice = NULL;
//Counter for the number of keys pending to be processed.
ULONG numberOfPendingKeys = 0;

//Called when the driver is being unloaded.
VOID DriverWillUnload(IN PDRIVER_OBJECT DriverObject)
{
    //Set the time period of 1 second for later use.
    LARGE_INTEGER interval = { 0 };
    interval.QuadPart = -10 * 1000 * 1000;
    DbgPrint("DriverUnload is being called.\r\n");
    PDEVICE_OBJECT DeviceObject = DriverObject->DeviceObject;
    //Perform detaching on the LowerKbdDevice.
    IoDetachDevice(((PDEVICE_EXTENSION)DeviceObject->DeviceExtension)->LowerKbdDevice);
    //Wait for all read IRPs to be completed, or else the driver will cause BSOD on unloading. (csrss)
    while (numberOfPendingKeys) {
        //Delay execution for the amount of time specified.
        KeDelayExecutionThread(KernelMode, FALSE, &interval);
    }
    //Delete the previously created keyboard device.
    IoDeleteDevice(keyboardDevice);
    DbgPrint("DriverUnload done.\r\n");
}

//When called, creates a virtual device. Its requests will be filtered by the driver.
NTSTATUS WillAttachDevice(PDRIVER_OBJECT DriverObject)
{
    //KeyboardClass0 is the default device for keyboards, specifically those using PS/2.
    UNICODE_STRING TargetDeviceName = RTL_CONSTANT_STRING(L"\\Device\\KeyboardClass0");
    DbgPrint("WillAttachDevice is being called.\r\n");
    //Attempt creating the device.
    NTSTATUS status = IoCreateDevice(DriverObject, sizeof(DEVICE_EXTENSION), NULL, FILE_DEVICE_KEYBOARD, 0, FALSE, &keyboardDevice);
    //If it failed...
    if (!NT_SUCCESS(status)) {
        //...log the error, then return the status code.
        DbgPrint("WillAttachDevice: IoCreateDevice failed!\r\n");
        return status;
    }

    //Buffered IO flag allows for propagating buffered READ and WRITE requests.
    keyboardDevice->Flags |= DO_BUFFERED_IO;
    //Device initializing finished. Clear the initialization flag.
    keyboardDevice->Flags &= ~DO_DEVICE_INITIALIZING;

    //Initialize a DEVICE_EXTENSION structure.
    RtlZeroMemory(keyboardDevice->DeviceExtension, sizeof(DEVICE_EXTENSION));

    //Attempt to attach the device.
    status = IoAttachDevice(keyboardDevice, &TargetDeviceName, &((PDEVICE_EXTENSION)keyboardDevice->DeviceExtension)->LowerKbdDevice);
    //If it failed...
    if (!NT_SUCCESS(status)) {
        //...delete the freshly created device, log the error, then return the status code.
        IoDeleteDevice(keyboardDevice);
        DbgPrint("WillAttachDevice: IoAttachDevice failed! Deleting device.\r\n");
        return status;
    }

    //At this point, device creation and attaching has been successful.
    return STATUS_SUCCESS;
}

//Called when the READ request's completion routine is to be executed.
NTSTATUS ReadWillComplete(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context)
{
    CHAR* keyFlagValues[4] = { "KEY_MAKE", "KEY_BREAK", "EXTENDED0", "EXTENDED1" };
    //Get the keyboard's key input buffer.
    PKEYBOARD_INPUT_DATA keyBuffer = (PKEYBOARD_INPUT_DATA)Irp->AssociatedIrp.SystemBuffer;
    //Get the number of bytes being transferred in the buffer, then convert it to the number of items in array.
    int numberOfItemsInBuffer = Irp->IoStatus.Information / sizeof(KEYBOARD_INPUT_DATA);

    //If the read request was successful...
    if (Irp->IoStatus.Status == STATUS_SUCCESS) {
        //...loop through each buffered keypress being read...
        for (int i = 0; i < numberOfItemsInBuffer; i++) {
            //...and log the acquired scan code and its flag value (usually either KEY_MAKE or KEY_BREAK).
            DbgPrint("ReadWillComplete got scan code %x (%s)\r\n", keyBuffer->MakeCode, keyFlagValues[keyBuffer->Flags]);
        }
    }

    //Handle any pending IRP requests.
    if (Irp->PendingReturned) {
        IoMarkIrpPending(Irp);
    }

    //Finished processing the keypress. Decrease the counter.
    numberOfPendingKeys--;

    //Return the IRP's status code.
    return Irp->IoStatus.Status;
}

//Handles IRP major read requests, in this case, from the keyboard.
NTSTATUS DispatchRead(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    //Copy the current IRP request to the next device in current device stack.
    IoCopyCurrentIrpStackLocationToNext(Irp);
    //Setup the completion routine for read requests.
    IoSetCompletionRoutine(Irp, ReadWillComplete, NULL, TRUE, TRUE, TRUE);
    //Increase the key counter.
    numberOfPendingKeys++;
    //Finally, call the modified IRP request on the lower device.
    return IoCallDriver(((PDEVICE_EXTENSION)keyboardDevice->DeviceExtension)->LowerKbdDevice, Irp);
}

//Handles IRP requests that should be passed as is.
NTSTATUS DispatchPass(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    //Copy the current IRP request to the next device in current device stack.
    IoCopyCurrentIrpStackLocationToNext(Irp);
    //Then call the passed IRP request on that device.
    return IoCallDriver(((PDEVICE_EXTENSION)keyboardDevice->DeviceExtension)->LowerKbdDevice, Irp);
}

//Similar to MAIN function. One argument is an object pointer, other is a string pointer.
//This is the driver's entry point. Every driver must have this function.
//The driver is treated like an object. It has many members like DriverInit, DriverStartIo, DriverUnload.
NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath) 
{
    //Similar to printf.
    DbgPrint("DriverEntry is being called.\r\n");

    //Now ready to setup IRP requests dispatch functions.

    //Setup passthrough dispatch requests function.
    for (int i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++) {
        DriverObject->MajorFunction[i] = DispatchPass;
    }

    //Setup READ dispatch request function.
    DriverObject->MajorFunction[IRP_MJ_READ] = DispatchRead;

    //Assign function pointer of unload behavior.
    //This function will be called when the driver is unloaded.
    DriverObject->DriverUnload = DriverWillUnload; 

    //Create and attach the driver's device.
    NTSTATUS status = WillAttachDevice(DriverObject);
    //If it failed...
    if (!NT_SUCCESS(status)) {
        //...log an error.
        DbgPrint("WillAttachDevice failed.\r\n");
    }
    else {
        //Otherwise, log successful execution.
        DbgPrint("WillAttachDevice executed successfully.\r\n");
    }

    return status;
}
