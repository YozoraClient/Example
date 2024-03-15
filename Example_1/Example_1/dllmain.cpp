#include <windows.h>
#include <iostream>

void start()
{
    if (!GetConsoleWindow())
    {
        AllocConsole();
        SetConsoleTitleA("Example 1 - Setting up Console");
        FILE* out;
        freopen_s(&out, "CONOUT$", "w", stdout);
        freopen_s(&out, "CONIN$", "r", stdin);
    }
    else {
        ShowWindow(GetConsoleWindow(), SW_SHOW);
    }
    
    std::cout << "Hello World!" << std::endl; 
}

BOOL APIENTRY DllMain(HMODULE module,DWORD callReason, LPVOID reserved)
{
    switch (callReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(module);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)start, module, 0, 0);
    }
    return TRUE;
}

