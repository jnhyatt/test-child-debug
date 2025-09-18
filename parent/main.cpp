#include <Windows.h>

int main() {
    DWORD written;
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "Spawning child process\n", 24, &written, NULL);

    STARTUPINFOA startupInfo {};
    PROCESS_INFORMATION processInfo {};
    CreateProcessA(NULL, "child.exe", NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo);

    Sleep(1000);

    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "Parent process exiting\n", 24, &written, NULL);
    
    return 0;
}
