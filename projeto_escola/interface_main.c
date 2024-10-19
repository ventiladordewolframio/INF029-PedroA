#include "interface_main.h"
#include "interface_cadastro.h"
#include "interface_relatorio.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansi_escapes.h"

// add arquivo databaseLoad.c
// add arquivo databaseWrite.c
// para lidar com as funcoes necessarias para isso

// ANSI colors
// |    red \x1b[0;31m
// |  green \x1b[0;32m
// | yellow \x1b[0;33m
// |   cyan \x1b[0;36m
// |  blank \x1b[0;0m


int qtd_aluno = 0;
int qtd_professor = 0;
int qtd_disciplina = 0;

struct aluno alunos[MAX_num_alunos];
struct professor professores[MAX_num_professores];
struct disciplina disciplinas[MAX_num_disciplinas];


void clear();


int main(void) {
    bool sair = 0;

    setupConsole();

    while (!sair) {
        puts("\x1b[0;36m _____      _             __                 _____              _       \x1b[0;0m");
        puts("\x1b[0;36m|_   _|    | |           / _|               |  ___|            | |  v0.5\x1b[0;0m");
        puts("\x1b[0;36m  | | _ __ | |_ ___ _ __| |_ __ _  ___ ___  | |__ ___  ___ ___ | | __ _ \x1b[0;0m");
        puts("\x1b[0;36m  | || '_ \\| __/ _ \\ '__|  _/ _` |/ __/ _ \\ |  __/ __|/ __/ _ \\| |/ _` |\x1b[0;0m");
        puts("\x1b[0;36m _| || | | | ||  __/ |  | || (_| | (_|  __/ | |__\\__ \\ (_| (_) | | (_| |\x1b[0;0m");
        puts("\x1b[0;36m \\___/_| |_|\\__\\___|_|  |_| \\__,_|\\___\\___| \\____/___/\\___\\___/|_|\\__,_|\x1b[0;0m");
        puts("\x1b[0;36m_________________________________________________________________________\x1b[0;0m");
        puts("\x1b[0;31m(s) sair\x1b[0;0m");
        puts("\x1b[0;32m(c) acessar interface de cadastros\x1b[0;0m");
        puts("\x1b[0;32m(r) acessar interface de relatorios\x1b[0;0m");
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");
        char op;
        scanf(" %c", &op);
        clear();

        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;

            case 'c':  // cadastro
                interfaceCad();
                break;

            case 'r':  // relatorio
                interfaceRel();
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" nao existe\n", op);
                break;
        }
    }

    restoreConsole();
    return 0;
}

void clear(void) {
    while (getchar() != '\n');
}

void printAlunosObj() {
    for (int i = 0; i < MAX_num_alunos; i++) {
        printf("\x1b[0;36m[INFO]: aluno \"%d\" nome:\x1b[0;0m ", i);
        printf("\"");
        for (int c = 0; c < (sizeof(&alunos[i].nome[c]) / sizeof(char)); c++) {
            printf("%c", alunos[i].nome[c]);
        }
        printf("\"");
        printf("\n");
    }
}




