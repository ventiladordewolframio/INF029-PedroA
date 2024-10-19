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

struct data {
    unsigned long long int timestamp;
    int ano;
    int mes;
    int dia;
};

struct aluno {
    int matricula;
    char nome[256];
    char sexo;
    struct data nascimento;
    int cpf;
};

struct professor {
    int matricula;
    char nome[256];
    char sexo;
    struct data nascimento;
    int cpf;
};

struct disciplina {
    char nome[128];
    int id;
    int semestre;
    char professor[128];
};

#define num_alunos 5
#define num_professores 5
#define num_disciplinas 5
int qtdAluno = 0;
int qtdProfessor = 0;

struct aluno alunos[num_alunos];
struct professor professores[num_professores];
struct disciplina disciplinas[num_disciplinas];

void clear();
void writeDatabase();
void readDatabase();
int interfaceCad();
int interfaceRel();

int main(void) {
    bool sair = 0;

    setupConsole();

    while (!sair) {
        puts("\x1b[0;36m _____      _             __                 _____              _       \x1b[0;0m");
        puts("\x1b[0;36m|_   _|    | |           / _|               |  ___|            | |  v0.3\x1b[0;0m");
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
void writeDatabase() {
}
void readDatabase() {
}
void printAlunosObj() {
    for (int i = 0; i < num_alunos; i++) {
        printf("\x1b[0;36m[INFO]: aluno \"%d\" nome:\x1b[0;0m ", i);
        printf("\"");
        for (int c = 0; c < (sizeof(&alunos[i].nome[c]) / sizeof(char)); c++) {
            printf("%c", alunos[i].nome[c]);
        }
        printf("\"");
        printf("\n");
    }
}



int interfaceCad() {
    bool sair_cad = 0;
    while (!sair_cad) {
        puts("\x1b[0;36m _____           _           _             \x1b[0;0m");
        puts("\x1b[0;36m/  __ \\         | |         | |            \x1b[0;0m");
        puts("\x1b[0;36m| /  \\/ __ _  __| | __ _ ___| |_ _ __ ___  \x1b[0;0m");
        puts("\x1b[0;36m| |    / _` |/ _` |/ _` / __| __| '__/ _ \\ \x1b[0;0m");
        puts("\x1b[0;36m| \\__/\\ (_| | (_| | (_| \\__ \\ |_| | | (_) |\x1b[0;0m");
        puts("\x1b[0;36m \\____/\\__,_|\\__,_|\\__,_|___/\\__|_|  \\___/ \x1b[0;0m");
        puts("\x1b[0;36m____________________________________________\x1b[0;0m");
        puts("\x1b[0;31m(s) sair\x1b[0;0m");
        puts("\x1b[0;32m(a) aluno\x1b[0;0m");
        puts("\x1b[0;32m(p) professor\x1b[0;0m");
        puts("\x1b[0;32m(d) disciplina\x1b[0;0m");
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");
        char op;
        scanf(" %c", &op);
        clear();

        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;

            case 'a':  // alunos
                printf("\n");
                for (int i = 0; i < num_alunos; i++) {
                    printf("\x1b[0;36m[INFO]: Matricula \"%d\", Nome: \x1b[0;0m\n", i);
                    char nome[256];
                    fgets(nome, 256, stdin);
                    nome[strcspn(nome, "\n")] = 0;
                    strcpy(alunos[i].nome, nome);
                }

                printAlunosObj();

                break;

            case 'p':  // professores

                break;

            case 'd':  // disciplinas

                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" nao existe\n", op);
                break;
        }
    }
}
int interfaceRel() {
    bool sair_rel = 0;
    while (!sair_rel) {
        puts("\x1b[0;36m______     _       _             _           \x1b[0;0m");
        puts("\x1b[0;36m| ___ \\   | |     | |           (_)          \x1b[0;0m");
        puts("\x1b[0;36m| |_/ /___| | __ _| |_ ___  _ __ _  ___  ___ \x1b[0;0m");
        puts("\x1b[0;36m|    // _ \\ |/ _` | __/ _ \\| '__| |/ _ \\/ __|\x1b[0;0m");
        puts("\x1b[0;36m| |\\ \\  __/ | (_| | || (_) | |  | | (_) \\__ \\\x1b[0;0m");
        puts("\x1b[0;36m\\_| \\_\\___|_|\\__,_|\\__\\___/|_|  |_|\\___/|___/\x1b[0;0m");
        puts("\x1b[0;36m______________________________________________\x1b[0;0m");
        puts("\x1b[0;31m(s) sair\x1b[0;0m");
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");
        char op;
        scanf(" %c", &op);
        clear();

        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;

            case 'c':  // cadastro

                break;

            case 'r':  // relatorio

                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" nao existe\n", op);
                break;
        }
    }
}