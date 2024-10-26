#include "interface_relatorio.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ansi_escapes.h"
#include "interface_main.h"

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
        puts("\x1b[0;31m(s)  sair - (Interface Escola)\x1b[0;0m");
        printf("\n");
        puts("\x1b[0;32m(0)  listar alunos\x1b[0;0m");
        puts("\x1b[0;32m(1)  listar professores\x1b[0;0m");
        puts("\x1b[0;32m(2)  listar disciplinas\x1b[0;0m");
        puts("\x1b[0;32m(3)  listar uma disciplina\x1b[0;0m");  // usuario deve inserir o codigo da disciplina e receber os dados dela + dados dos alunos matriculados (loop pelo aluno.disciplinas (bool) (cada valor booleano corresponde a disciplina de mesmo codigo))
        printf("\n");
        puts("\x1b[0;32m(4)  listar alunos por sexo\x1b[0;0m");
        puts("\x1b[0;32m(5)  listar alunos por nome\x1b[0;0m");
        puts("\x1b[0;32m(6)  listar alunos por data de nascimento\x1b[0;0m");
        puts("\x1b[0;32m(7)  listar professores por sexo\x1b[0;0m");
        puts("\x1b[0;32m(8)  listar professores por nome\x1b[0;0m");
        puts("\x1b[0;32m(9)  listar professores por data de nascimento\x1b[0;0m");
        printf("\n");
        puts("\x1b[0;32m(10) listar aniversariantes do mês\x1b[0;0m");  // professores + alunos
        puts("\x1b[0;32m(11) listar pessoas (buscar)\x1b[0;0m");        //! código ja esta em maior parte pronto eu acabei fazendo antes
        puts("\x1b[0;32m(12) listar alunos matriculados em menos de 3 disciplinas\x1b[0;0m");
        puts("\x1b[0;32m(13) listar disciplinas que extrapolam 40 vagas\x1b[0;0m");  // listar tambem o nome do(s) proessor(es) que da essas disciplinas
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");

        char c1, c2;
        scanf(" %c", &c1);
        scanf("%c", &c2);
        clear();

        //printf("|%c|%c|", c1, c2);
        int op;

        if (c2 == '\n') {
            char int1 = c1;
            op = int1 - '0';
            //printf("|first %d|", op);
        } else {
            char int1 = c1;
            int op0 = int1 - '0';
            char int2 = c2;
            int op1 = int2 - '0';
            op = (op0 * 10) + op1;
            //printf("|second %d|", op);
        }

        //printf(" op: %d ", op);

        switch (op) {
            case 67:  // sai da aplicação
                return 0;
                break;

            case 0:  // listar alunos
                //! inserir chamada de funcao aqui
                break;

            case 1:  // listar professores
                //! inserir chamada de funcao aqui
                break;

            case 2:  // listar disciplinas
                //! inserir chamada de funcao aqui
                break;

            case 3:  // listar uma disciplina
                //! inserir chamada de funcao aqui
                break;

            case 4:  // listar alunos por sexo
                Printf("Insira o sexo (M ou F)\n");
                listarProfessoresPorSexo();
                break;

            case 5:  // listar alunos por nome
                //! inserir chamada de funcao aqui
                break;

            case 6:  // listar alunos por data de nascimento
                //! inserir chamada de funcao aqui
                break;

            case 7:  // listar professores por sexo
                //! inserir chamada de funcao aqui
                break;

            case 8:  // listar professores por nome
                //! inserir chamada de funcao aqui
                break;

            case 9:  // listar professores por data de nascimento
                //! inserir chamada de funcao aqui
                break;

            case 10:  // listar aniversariantes do mês
                //! inserir chamada de funcao aqui
                break;

            case 11:  // listar pessoas (buscar)
                //! inserir chamada de funcao aqui
                break;

            case 12:  // listar alunos matriculados em menos de 3 disciplinas
                //! inserir chamada de funcao aqui
                break;

            case 13:  // listar disciplinas que extrapolam 40 vagas
                //! inserir chamada de funcao aqui
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%d\" nao existe\n", op);
                break;
        }
    }
    void listarProfessoresPorSexo(char sexo) {
        sexo = toupper(sexo);
        printf("Lista de Professores do sexo %c:\n", sexo);
        for (int i = 0; i < qtd_professor; i++) {
            if (professores[i].ativo && professores[i].sexo == sexo) {
                printf("Professor #%d\n", i + 1);
                printf("Matrícula: %d\n", professores[i].matricula);
                printf("Nome: %s\n", professores[i].nome);
                printf("Data de Nascimento: %02d/%02d/%d\n", professores[i].nascimento.dia, professores[i].nascimento.mes, professores[i].nascimento.ano);
                printf("CPF: %s\n\n", professores[i].cpf);
            }
        }
    }
}
