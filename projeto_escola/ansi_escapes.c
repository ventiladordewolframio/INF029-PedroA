#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>

#include "ansi_escapes.h"

#ifdef _WIN32
// Some old MinGW/CYGWIN distributions don't define this:
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

static HANDLE stdoutHandle;
static DWORD outModeInit;

void setupConsole(void) {
    // seta a saida do console windows para UTF-8, pq? pq não é assim por padrão por absolutamente motivo algum, e o trampo necessario pra fazer isso é desproporcional.
    SetConsoleOutputCP(CP_UTF8); // tudo isso culpa do windows

    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (stdoutHandle == INVALID_HANDLE_VALUE) {
        exit(GetLastError());
    }

    if (!GetConsoleMode(stdoutHandle, &outMode)) {
        exit(GetLastError());
    }

    outModeInit = outMode;

    // Enable ANSI escape codes,  dnv pq isso? pq nao ta habilitado por padrão. como funciona? nsei nao quero saber e tenho odio de quem sabe
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(stdoutHandle, outMode)) {
        exit(GetLastError());
    }
}

void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");

    // Reset console mode
    if (!SetConsoleMode(stdoutHandle, outModeInit)) {
        exit(GetLastError());
    }
}
#else
void setupConsole(void) {
    // This might also set the output to UTF-8 on non-Windows platforms if needed
    // But usually, it's already UTF-8 by default on Unix-like systems
}

void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");
}
#endif