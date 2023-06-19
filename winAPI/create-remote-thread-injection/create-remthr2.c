#include <windows.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char argv)
{

    char messBox = MessageBoxW(NULL,L"This is a message box!", L"Hello!!", MB_YESNOCANCEL);

    return EXIT_SUCCESS;

    HANDLE processHandle;
    HANDLE remoteThread;
    PVOID rBuffer;

    processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, argv);
    rBuffer = VirtualAllocEx(processHandle, NULL, sizeof messBox, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(processHandle, rBuffer, &messBox, sizeof messBox, NULL);
    remoteThread = CreateRemoteThread(processHandle, NULL, 0, (LPTHREAD_START_ROUTINE)rBuffer, NULL, 0, NULL);
    CloseHandle(processHandle);

    return 0;

}