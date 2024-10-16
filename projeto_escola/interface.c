#include <stdio.h>
#include "ansi_escapes.h"

// ANSI colors
// |    red \x1b[0;31m
// |  green \x1b[0;32m
// | yellow \x1b[0;33m
// |   cyan \x1b[0;36m
// |  blank \x1b[0;0m

int interfaceCad();
int interfaceRel();

int main() {
    setupConsole();

    puts("\x1b[0;36m _____      _             __                 _____              _       \x1b[0;0m");
    puts("\x1b[0;36m|_   _|    | |           / _|               |  ___|            | |  v0.1\x1b[0;0m");
    puts("\x1b[0;36m  | | _ __ | |_ ___ _ __| |_ __ _  ___ ___  | |__ ___  ___ ___ | | __ _ \x1b[0;0m");
    puts("\x1b[0;36m  | || '_ \\| __/ _ \\ '__|  _/ _` |/ __/ _ \\ |  __/ __|/ __/ _ \\| |/ _` |\x1b[0;0m");
    puts("\x1b[0;36m _| || | | | ||  __/ |  | || (_| | (_|  __/ | |__\\__ \\ (_| (_) | | (_| |\x1b[0;0m");
    puts("\x1b[0;36m \\___/_| |_|\\__\\___|_|  |_| \\__,_|\\___\\___| \\____/___/\\___\\___/|_|\\__,_|\x1b[0;0m");

    puts("\x1b[0;36m_________________________________________________________________________\x1b[0;0m");

    puts("\x1b[0;31m(s) - sair\x1b[0;0m");
    puts("\x1b[0;32m(c) - acessar interface de cadastros\x1b[0;0m");
    puts("\x1b[0;32m(r) - acessar interface de relatorios\x1b[0;0m");

    restoreConsole();
    return 0;
}

int interfaceCad() {
}
int interfaceRel() {
}
