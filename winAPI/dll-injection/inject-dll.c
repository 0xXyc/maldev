#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    HANDLE processHandle;
    HANDLE threadHandle;
    PVOID remoteBuffer;
    LPCSTR dllPath = "C:\\testcode\\hello-world-x64.dll";
    SIZE_T dllPathLength = strlen(dllPath) + 1;
    PTHREAD_START_ROUTINE threatStartRoutineAddress;

    printf("Injecting DLL to PID: %i\n", atoi(argv[1]));

    processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, atoi(argv[1]));
    if(!processHandle)
    {
        printf("OpenProcess Failed: %d\n", GetLastError());
        return 0;
    }

    remoteBuffer = VirtualAllocEx(processHandle, NULL, dllPathLength, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if(!remoteBuffer)
    {
        printf("VirtualAllocEx Failed: %d\n", GetLastError());
        return 0;
    }

    if(!WriteProcessMemory(processHandle, remoteBuffer, dllPath, dllPathLength, NULL))
    {
        printf("WriteProcessMemory Failed: %d\n", GetLastError());
        return 0;
    }

    threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryA");
    threadHandle = CreateRemoteThread(processHandle, NULL, 0, threatStartRoutineAddress, remoteBuffer, 0, NULL);
    if(!threadHandle)
    {
        printf("Remote thread failed. %d\n", GetLastError());
        return 0;
    }

    printf("Success\n");

    CloseHandle(threadHandle);
    CloseHandle(processHandle);

    return 0;
}