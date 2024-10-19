#include "interface_cadastro.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansi_escapes.h"
#include "interface_main.h"

int interfaceCadAluno();
int interfaceCadProfessor();
int interfaceCadDisciplina();

int interfaceCad() {
    bool sair_cad = 0;   // pra falar a real esse bool acaba não sendo necessário
    while (!sair_cad) {  // poderia ser substituido por um while(true){}
        puts("\x1b[0;36m _____           _           _                   \x1b[0;0m");
        puts("\x1b[0;36m/  __ \\         | |         | |                 \x1b[0;0m");
        puts("\x1b[0;36m| /  \\/ __ _  __| | __ _ ___| |_ _ __ ___       \x1b[0;0m");
        puts("\x1b[0;36m| |    / _` |/ _` |/ _` / __| __| '__/ _ \\      \x1b[0;0m");
        puts("\x1b[0;36m| \\__/\\ (_| | (_| | (_| \\__ \\ |_| | | (_) |  \x1b[0;0m");
        puts("\x1b[0;36m \\____/\\__,_|\\__,_|\\__,_|___/\\__|_|  \\___/ \x1b[0;0m");
        puts("\x1b[0;36m____________________________________________     \x1b[0;0m");
        puts("\x1b[0;31m(s) sair - (Interface Escola)                    \x1b[0;0m");
        puts("\x1b[0;32m(a) aluno                                        \x1b[0;0m");
        puts("\x1b[0;32m(p) professor                                    \x1b[0;0m");
        puts("\x1b[0;32m(d) disciplina                                   \x1b[0;0m");

        printf("\x1b[0;36m[INFO]: Escolha:  \x1b[0;0m");  // input de dados do usuário
        char op;                                          // operação
        scanf(" %c", &op);                                // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();                                          // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados

        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;

            case 'a':  // alunos
                interfaceCadAluno();
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

int interfaceCadAluno() {
    bool sair_cad_aluno = 0;   // pra falar a real esse bool acaba não sendo necessário
    while (!sair_cad_aluno) {  // poderia ser substituido por um while(true){}
        puts("\x1b[0;36m _____           _  ___  _                                         \x1b[0;0m");
        puts("\x1b[0;36m/  __ \\         | |/ _ \\| |                                      \x1b[0;0m");
        puts("\x1b[0;36m| /  \\/ __ _  __| / /_\\ \\ |_   _ _ __   ___                     \x1b[0;0m");
        puts("\x1b[0;36m| |    / _` |/ _` |  _  | | | | | '_ \\ / _ \\                     \x1b[0;0m");
        puts("\x1b[0;36m| \\__/\\ (_| | (_| | | | | | |_| | | | | (_) |                    \x1b[0;0m");
        puts("\x1b[0;36m \\____/\\__,_|\\__,_\\_| |_/_|\\__,_|_| |_|\\___/                 \x1b[0;0m");
        puts("\x1b[0;36m_____________________________________________                      \x1b[0;0m");
        printf("\x1b[0;31m(s) sair do menu de cadastro de alunos                           \x1b[0;0m\n");
        if (qtd_aluno == MAX_num_alunos) {
            printf("\x1b[0;31m(i) Inserir dados de uma nova Matricula: (CHEIO) (%d/%d)     \x1b[0;0m\n", qtd_aluno, qtd_aluno);
        } else {
            printf("\x1b[0;32m(i) Inserir dados de uma nova Matricula: (%d)                \x1b[0;0m\n", qtd_aluno);
        }
        printf("\x1b[0;36m(e) Editar dados de uma Matricula                                \x1b[0;0m\n");
        printf("\x1b[0;36m(l) listar matriculas                                            \x1b[0;0m\n");

        printf("\x1b[0;36m[INFO]: Escolha:  \x1b[0;0m");  // input de dados do usuário
        char op;                                          // operação
        scanf(" %c", &op);                                // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();                                          // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados

        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;

            case 'i':                               // inserir dados de uma nova matricula
                if (qtd_aluno == MAX_num_alunos) {  // se as matriculas definidas estiverem cheias, impedir o commando de rodar
                    break;
                }
                printf("\x1b[0;36m[INFO]: Matricula: \"%d\"\x1b[0;0m\n", qtd_aluno);  // INSERIR NOME
                printf("\x1b[0;36m[INPUT]:     Nome: \x1b[0;0m");
                char nome[MAX_char_nome];
                fgets(nome, MAX_char_nome, stdin);
                nome[strcspn(nome, "\n")] = 0;  // roubei do teu replit :) obg
                strcpy(alunos[qtd_aluno].nome, nome);

                printf("\x1b[0;36m[INPUT]:     Sexo: \x1b[0;0m");  // INSERIR SEXO (lá ele)
                scanf(" %c", &alunos[qtd_aluno].sexo);             // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
                clear();                                           // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados

                // printf("\x1b[0;36m[INFO]: Salvo: Matricula: \"%d\"\n[INFO]:             Nome: \"%s\"\x1b[0;0m\n", qtd_aluno, nome);  // espaco necessário para a formatação correta
                qtd_aluno++;
                break;

            case 'e':  // editar dados de uma matricula
                       // TODO se o usuario deixar em branco, não mudar o valor. caso contrario muda para oq for escrito
                break;

            case 'l':  // listar matriculas
                printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                printAlunosObj();
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" nao existe\n", op);
                break;
        }
    }
}

int interfaceCadProfessor() {
}

int interfaceCadDisciplina() {
}
