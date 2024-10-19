#include "interface_cadastro.h"
#include "interface_main.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansi_escapes.h"

int interfaceCadAluno();
int interfaceCadProfessor();
int interfaceCadDisciplina();

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

                    printf("\x1b[0;36m[INFO]: Matricula \"%d\", Nome: \x1b[0;0m\n", 4);


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




int interfaceCadAluno(){

}

int interfaceCadProfessor(){

}

int interfaceCadDisciplina(){

}


