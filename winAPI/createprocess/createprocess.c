#include <stdio.h>
#include <windows.h>

int createProcessF()

{

  STARTUPINFOW si = {0};
  PROCESS_INFORMATION pi = {0};

  int createProcess = CreateProcessW(L"C:\\WINDOWS\\system32\\notepad.exe",NULL, NULL, NULL, FALSE, BELOW_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);

  if (!createProcess)

  {

      printf("(-) Process creation has failed please try again.\n Error: %ld", GetLastError);

      return EXIT_FAILURE;

  }

else
  {

    printf("(+) Process was successfully created and started!\n PID: %ld", pi.dwProcessId);

    printf("\n\nProcess with PID:%ld has been started, goodbye.", pi.dwProcessId);

    return EXIT_SUCCESS;

  }

}

int main()

{

printf("Starting notepad.exe as a new process...\n\n");

int createProcess = createProcessF();

}