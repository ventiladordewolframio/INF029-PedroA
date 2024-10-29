#include "interface_main.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansi_escapes.h"
#include "interface_cadastro.h"
#include "interface_relatorio.h"

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
void startObjVariables();

int main(void) {
    bool sair = 0;
    setupConsole();
    startObjVariables();

    while (!sair) {
        puts("\x1b[0;36m╔════════════════════════════════════════════════════════════════════════╗           \x1b[0;0m");
        puts("\x1b[0;36m║ _____      _             __                 _____              _ v1.3.0║           \x1b[0;0m");
        puts("\x1b[0;36m║|_   _|    | |           / _|               |  ___|            | |      ║           \x1b[0;0m");
        puts("\x1b[0;36m║  | | _ __ | |_ ___ _ __| |_ __ _  ___ ___  | |__ ___  ___ ___ | | __ _ ║           \x1b[0;0m");
        puts("\x1b[0;36m║  | || '_ \\| __/ _ \\ '__|  _/ _` |/ __/ _ \\ |  __/ __|/ __/ _ \\| |/ _` |║       \x1b[0;0m");
        puts("\x1b[0;36m║ _| || | | | ||  __/ |  | || (_| | (_|  __/ | |__\\__ \\ (_| (_) | | (_| |║         \x1b[0;0m");
        puts("\x1b[0;36m║ \\___/_| |_|\\__\\___|_|  |_| \\__,_|\\___\\___| \\____/___/\\___\\___/|_|\\__,_|║ \x1b[0;0m");
        puts("\x1b[0;36m╚════════════════════════════════════════════════════════════════════════╝\x1b[0;0m");
        printf("\n");
        puts("\x1b[0;31m(s) sair\x1b[0;0m");
        puts("\x1b[0;32m(c) acessar interface de cadastros\x1b[0;0m");
        puts("\x1b[0;32m(r) acessar interface de relatórios\x1b[0;0m");
        printf("\n");
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
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }

    restoreConsole();
    return 0;
}

void clear(void) {
    while (getchar() != '\n');
}

void printFormatAlunoData(int i) {
    printf("\x1b[0;36mMatricula \"%d\"\x1b[0;0m\n", alunos[i].matricula);
    printf("\x1b[0;36m├──Nome       : \"%s\"\x1b[0;0m\n", alunos[i].nome);
    printf("\x1b[0;36m├──Sexo       : \"%c\"\x1b[0;0m\n", alunos[i].sexo);
    printf("\x1b[0;36m├──Nascimento : \"%d/%d/%d\"\x1b[0;0m\n", alunos[i].nascimento.ano, alunos[i].nascimento.mes, alunos[i].nascimento.dia);
    printf("\x1b[0;36m├──CPF        : \"%s\"\x1b[0;0m\n", alunos[i].cpf);
    printf("\x1b[0;36m├──disciplinas: \"");
    for (int j = 0; j < MAX_num_disciplinas; j++) {
        if (alunos[i].disciplinas[j]) {
            printf("%s", disciplinas[j].nome);
            if (j != MAX_num_disciplinas - 2) {
                printf(", ");
            }
        }
    }
    printf("\"\x1b[0;0m\n");
    printf("\x1b[0;36m└──ativo      : \"%s\"\x1b[0;0m\n", alunos[i].ativo ? "true" : "false");
    printf("\n");
}

void printFormatProfessorData(int i) {
    printf("\x1b[0;36mMatricula \"%d\"\x1b[0;0m\n", professores[i].matricula);
    printf("\x1b[0;36m├──Nome       : \"%s\"\x1b[0;0m\n", professores[i].nome);
    printf("\x1b[0;36m├──Sexo       : \"%c\"\x1b[0;0m\n", professores[i].sexo);
    printf("\x1b[0;36m├──Nascimento : \"%d/%d/%d\"\x1b[0;0m\n", professores[i].nascimento.ano, professores[i].nascimento.mes, professores[i].nascimento.dia);
    printf("\x1b[0;36m├──CPF        : \"%s\"\x1b[0;0m\n", professores[i].cpf);
    printf("\x1b[0;36m├──disciplinas: \"");
    for (int j = 0; j < MAX_num_disciplinas; j++) {
        if (professores[i].disciplinas[j]) {
            printf("%s", disciplinas[j].nome);
            if (j != MAX_num_disciplinas - 2) {
                printf(", ");
            }
        }
    }
    printf("\"\x1b[0;0m\n");
    printf("\x1b[0;36m└──ativo      : \"%s\"\x1b[0;0m\n", professores[i].ativo ? "true" : "false");
    printf("\n");
}

void printFormatDisciplinaData(int i) {
    printf("\x1b[0;36mCódigo \"%d\"\x1b[0;0m\n", disciplinas[i].id);
    printf("\x1b[0;36m├──Nome : \"%s\"\x1b[0;0m\n", disciplinas[i].nome);
    printf("\x1b[0;36m└──ativo: \"%s\"\x1b[0;0m\n", disciplinas[i].ativo ? "true" : "false");
    printf("\n");
}

void printAlunosObj() {
    puts("\x1b[0;36m[INFO]: Relatório Alunos Raw:\x1b[0;0m\n");
    for (int i = 0; i < MAX_num_alunos; i++) {
        printFormatAlunoData(i);
    }
}

void printProfessoresObj() {
    puts("\x1b[0;36m[INFO]: Relatório Professores Raw:\x1b[0;0m\n");
    for (int i = 0; i < MAX_num_professores; i++) {
        printFormatProfessorData(i);
    }
}

void printDisciplinasObj() {
    puts("\x1b[0;36m[INFO]: Relatório Disciplinas Raw:\x1b[0;0m\n");
    for (int i = 0; i < MAX_num_disciplinas; i++) {
        printFormatDisciplinaData(i);
    }
}

void startObjVariables() {
    for (int i = 0; i < MAX_num_alunos; i++) {
        alunos[i].nascimento.ano = 0;
        alunos[i].nascimento.mes = 0;
        alunos[i].nascimento.dia = 0;
        alunos[i].matricula = i;
        alunos[i].ativo = false;
    }
    for (int i = 0; i < MAX_num_professores; i++) {
        professores[i].nascimento.ano = 0;
        professores[i].nascimento.mes = 0;
        professores[i].nascimento.dia = 0;
        professores[i].matricula = i;
        professores[i].ativo = false;
    }
    for (int i = 0; i < MAX_num_disciplinas; i++) {
        disciplinas[i].vaga_preenchida = 0;
        disciplinas[i].ativo = false;
        disciplinas[i].id = i;
    }
}
