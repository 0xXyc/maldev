#include <windows.h>

int main(void)
{

    MessageBoxW(NULL, L"I just popped calc.exe in the background, or did I? ;)", L"Super malicious message box", MB_YESNOCANCEL);

    return EXIT_SUCCESS;

}
