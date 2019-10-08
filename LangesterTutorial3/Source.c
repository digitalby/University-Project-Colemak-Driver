#include "ntddk.h" //Typically used in windows kernel driver development

//Similar to MAIN function. One argument is an object pointer, other is a string pointer.
//This is the driver's entry point. Every driver must have this function.
//The driver is treated like an object. It has many members like DriverInit, DriverStartIo, DriverUnload.

VOID DriverWillUnload(IN PDRIVER_OBJECT DriverObject) {
    DbgPrint("DriverUnload is being called.\r\n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath) 
{
    //Similar to printf.
    DbgPrint("DriverEntry is being called.\r\n");
    //Assign function pointer of unload behavior.
    //This function will be called when driver is unloaded.
    DriverObject->DriverUnload = DriverWillUnload; 

    return STATUS_SUCCESS;
}
