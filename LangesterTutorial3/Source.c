//ntddk.h is typically used in windows kernel driver development
#include "ntddk.h"

#define SCANCODE_CTRL 0x1d
#define SCANCODE_ALT 0x38
#define SCANCODE_F11 0x57
#define SCANCODE_F12 0x58

//A conversion of scan codes to human readable key names (QWERTY Layout)
PCHAR keyNamesQWERTYStandard[] = {
    "0x00", //0x00
    "ESC", //0x01
    "1", //0x02
    "2", //0x03
    "3", //0x04
    "4", //0x05
    "5", //0x06
    "6", //0x07
    "7", //0x08
    "8", //0x09
    "9", //0x0a
    "0", //0x0b
    "MINUS", //0x0c
    "EQUAL", //0x0d
    "BACKSPACE", //0x0e
    "TAB", //0x0f
    "Q", //0x10
    "W", //0x11
    "E", //0x12
    "R", //0x13
    "T", //0x14
    "Y", //0x15
    "U", //0x16
    "I", //0x17
    "O", //0x18
    "P", //0x19
    "LEFT_BRACKET", //0x1a
    "RIGHT_BRACKET", //0x1b
    "RETURN", //0x1c
    "CTRL", //0x1d
    "A", //0x1e
    "S", //0x1f
    "D", //0x20
    "F", //0x21
    "G", //0x22
    "H", //0x23
    "J", //0x24
    "K", //0x25
    "L", //0x26
    "SEMICOLON", //0x27
    "APOSTROPHE", //0x28
    "GRAVE", //0x29
    "LEFT_SHIFT", //0x2a
    "0x2b", //0x2b
    "Z", //0x2c
    "X", //0x2d
    "C", //0x2e
    "V", //0x2f
    "B", //0x30
    "N", //0x31
    "M", //0x32
    "COMMA", //0x33
    "PERIOD", //0x34
    "SLASH", //0x35
    "RIGHT_SHIFT", //0x36
    "KP_ASTERISK", //0x37
    "ALT", //0x38
    "SPACEBAR", //0x39
    "CAPS_LOCK", //0x3a
    "F1", //0x3b
    "F2", //0x3c
    "F3", //0x3d
    "F4", //0x3e
    "F5", //0x3f
    "F6", //0x40
    "F7", //0x41
    "F8", //0x42
    "F9", //0x43
    "F10", //0x44
    "NUM_LOCK", //0x45
    "SCROLL_LOCK", //0x46
    "KP_7", //0x47
    "KP_8", //0x48
    "KP_9", //0x49
    "KP_MINUS", //0x4a
    "KP_4", //0x4b
    "KP_5", //0x4c
    "KP_6", //0x4d
    "KP_PLUS", //0x4e
    "KP_1", //0x4f
    "KP_2", //0x50
    "KP_3", //0x51
    "KP_0", //0x52
    "KP_PERIOD", //0x53
    "0x54", //0x54
    "0x55", //0x55
    "ISO_KEY", //0x56
    "F11", //0x57
    "F12" //0x58
};

//A conversion of scan codes to human readable key names (Colemak Layout)
PCHAR keyNamesColemakStandard[] = {
    "0x00", //0x00
    "ESC", //0x01
    "1", //0x02
    "2", //0x03
    "3", //0x04
    "4", //0x05
    "5", //0x06
    "6", //0x07
    "7", //0x08
    "8", //0x09
    "9", //0x0a
    "0", //0x0b
    "MINUS", //0x0c
    "EQUAL", //0x0d
    "BACKSPACE", //0x0e
    "TAB", //0x0f
    "Q", //0x10
    "W", //0x11
    "F", //0x12
    "P", //0x13
    "G", //0x14
    "J", //0x15
    "L", //0x16
    "U", //0x17
    "Y", //0x18
    "SEMICOLON", //0x19
    "LEFT_BRACKET", //0x1a
    "RIGHT_BRACKET", //0x1b
    "RETURN", //0x1c
    "CTRL", //0x1d
    "A", //0x1e
    "R", //0x1f
    "S", //0x20
    "T", //0x21
    "D", //0x22
    "H", //0x23
    "N", //0x24
    "E", //0x25
    "I", //0x26
    "O", //0x27
    "APOSTROPHE", //0x28
    "GRAVE", //0x29
    "LEFT_SHIFT", //0x2a
    "US_BACKSLASH", //0x2b
    "Z", //0x2c
    "X", //0x2d
    "C", //0x2e
    "V", //0x2f
    "B", //0x30
    "K", //0x31
    "M", //0x32
    "COMMA", //0x33
    "PERIOD", //0x34
    "SLASH", //0x35
    "RIGHT_SHIFT", //0x36
    "KP_ASTERISK", //0x37
    "ALT", //0x38
    "SPACEBAR", //0x39
    "CAPS_LOCK", //0x3a
    "F1", //0x3b
    "F2", //0x3c
    "F3", //0x3d
    "F4", //0x3e
    "F5", //0x3f
    "F6", //0x40
    "F7", //0x41
    "F8", //0x42
    "F9", //0x43
    "F10", //0x44
    "NUM_LOCK", //0x45
    "SCROLL_LOCK", //0x46
    "KP_7", //0x47
    "KP_8", //0x48
    "KP_9", //0x49
    "KP_MINUS", //0x4a
    "KP_4", //0x4b
    "KP_5", //0x4c
    "KP_6", //0x4d
    "KP_PLUS", //0x4e
    "KP_1", //0x4f
    "KP_2", //0x50
    "KP_3", //0x51
    "KP_0", //0x52
    "KP_PERIOD", //0x53
    "0x54", //0x54
    "0x55", //0x55
    "ISO_KEY", //0x56
    "F11", //0x57
    "F12" //0x58
};

//A conversion of QWERTY scan codes to respective Colemak key presses.
PUSHORT keyMapQWERTYToColemak[] = {
    0x00, //0x00
    0x01, //ESC
    0x02, //1
    0x03, //2
    0x04, //3
    0x05, //4
    0x06, //5
    0x07, //6
    0x08, //7
    0x09, //8
    0x0a, //9
    0x0b, //0
    0x0c, //MINUS
    0x0d, //EQUAL
    0x0e, //BACKSPACE
    0x0f, //TAB
    0x10, //Q
    0x11, //W
    0x21, //F
    0x19, //P
    0x22, //G
    0x24, //J
    0x26, //L
    0x16, //U
    0x15, //Y
    0x27, //SEMICOLON
    0x1a, //LEFT_BRACKET
    0x1b, //RIGHT_BRACKET
    0x1c, //RETURN
    0x1d, //CTRL
    0x1e, //A
    0x13, //R
    0x1f, //S
    0x14, //T
    0x20, //D
    0x23, //H
    0x31, //N
    0x12, //E
    0x17, //I
    0x18, //O
    0x28, //APOSTROPHE
    0x29, //GRAVE
    0x2a, //LEFT_SHIFT
    0x2b, //US_BACKSLASH
    0x2c, //Z
    0x2d, //X
    0x2e, //C
    0x2f, //V
    0x30, //B
    0x25, //K
    0x32, //M
    0x33, //COMMA
    0x34, //PERIOD
    0x35, //SLASH
    0x36, //RIGHT_SHIFT
    0x37, //KP_ASTERISK
    0x38, //ALT
    0x39, //SPACEBAR
    0x3a, //CAPS_LOCK
    0x3b, //F1
    0x3c, //F2
    0x3d, //F3
    0x3e, //F4
    0x3f, //F5
    0x40, //F6
    0x41, //F7
    0x42, //F8
    0x43, //F9
    0x44, //F10
    0x45, //NUM_LOCK
    0x46, //SCROLL_LOCK
    0x47, //KP_7
    0x48, //KP_8
    0x49, //KP_9
    0x4a, //KP_MINUS
    0x4b, //KP_4
    0x4c, //KP_5
    0x4d, //KP_6
    0x4e, //KP_PLUS
    0x4f, //KP_1
    0x50, //KP_2
    0x51, //KP_3
    0x52, //KP_0
    0x53, //KP_PERIOD
    0x54, //0x54
    0x55, //0x55
    0x56, //ISO_KEY
    0x57, //F11
    0x58 //F12
};

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

//Indicates whether Colemak mode is activated.
BOOLEAN colemakActivated = TRUE;
//Indicates whether key logging features are activated.
BOOLEAN loggingActivated = FALSE;

//Indicates whether CTRL key is being held.
BOOLEAN isCtrlHeld = FALSE;
//Indicates whether ALT key is being held.
BOOLEAN isAltHeld = FALSE;

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

//Logs supplied key buffer data to windbg.
VOID LogKeyBufferToWinDbg(PKEYBOARD_INPUT_DATA keyBuffer) {
    PCHAR keyFlagValues[4] = { "KEY_MAKE", "KEY_BREAK", "EXTENDED0", "EXTENDED1" };
    //If KEY_MAKE or KEY_BREAK flag is present, log the full info.
    if (keyBuffer->Flags < 2)
        DbgPrint("ReadWillComplete got scan code %x/%s (QWERTY: %s; Colemak:%s)\r\n",
            keyBuffer->MakeCode,
            keyFlagValues[keyBuffer->Flags],
            keyNamesQWERTYStandard[keyBuffer->MakeCode],
            keyNamesColemakStandard[keyBuffer->MakeCode]
        );
    else DbgPrint("ReadWillComplete got scan code %x/%s\r\n",
        keyBuffer->MakeCode,
        keyFlagValues[keyBuffer->Flags]);
}

VOID CheckHotkeys(PKEYBOARD_INPUT_DATA keyBuffer) {
    //If KEY_MAKE or KEY_BREAK flag is not present, stop execution.
    if (keyBuffer->Flags >= 2)
        return;
    //Check for CTRL key.
    if (keyBuffer->MakeCode == SCANCODE_CTRL) {
        isCtrlHeld = !keyBuffer->Flags;
        DbgPrint("Set isCtrlHeld to %d\r\n", isCtrlHeld);
    }
    //Check for ALT key.
    if (keyBuffer->MakeCode == SCANCODE_ALT) {
        isAltHeld = !keyBuffer->Flags;
        DbgPrint("Set isAltHeld to %d\r\n", isAltHeld);
    }
    //Check for special hotkeys. The respective key must have KEY_BREAK flag.
    if (keyBuffer->Flags != 1 || !isCtrlHeld || !isAltHeld)
        return;
    //Check for CTRL+ALT+F11
    if (keyBuffer->MakeCode == SCANCODE_F11) {
        loggingActivated = !loggingActivated;
        DbgPrint("Set loggingActivated to %d\r\n", loggingActivated);
    }
    //Check for CTRL+ALT+F12
    if (keyBuffer->MakeCode == SCANCODE_F12) {
        colemakActivated = !colemakActivated;
        DbgPrint("Set colemakActivated to %d\r\n", colemakActivated);
    }
}

//Called when the READ request's completion routine is to be executed.
NTSTATUS ReadWillComplete(PDEVICE_OBJECT DeviceObject, PIRP Irp, PVOID Context)
{
    //Get the keyboard's key input buffer.
    PKEYBOARD_INPUT_DATA keyBuffer = (PKEYBOARD_INPUT_DATA)Irp->AssociatedIrp.SystemBuffer;
    //Get the number of bytes being transferred in the buffer, then convert it to the number of items in array.
    int numberOfItemsInBuffer = Irp->IoStatus.Information / sizeof(KEYBOARD_INPUT_DATA);

    //If the read request was successful...
    if (Irp->IoStatus.Status == STATUS_SUCCESS) {
        //...loop through each buffered keypress being read...
        for (int i = 0; i < numberOfItemsInBuffer; i++) {
            //...log the acquired scan code and its flag value (usually either KEY_MAKE or KEY_BREAK)...
            LogKeyBufferToWinDbg(keyBuffer);
            //...check for modifier keys being pressed and their respective hotkeys...
            CheckHotkeys(keyBuffer);
            //...convert to Colemak if needed...
            if (colemakActivated)
                keyBuffer->MakeCode = keyMapQWERTYToColemak[keyBuffer->MakeCode];
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
