#include "interface_relatorio.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansi_escapes.h"
#include "interface_main.h"

//! por algum motivo APENAS as funcoes novas tavam dando problema com areferencia?? sendo que as outras nao precisaram de aparecer aqui antes de serem usadas??? vai saber
void listarAlunos();
void listarProfessores();
void listarDisciplinas();
void listarUmaDisciplina();

void listarAlunoPorSexo(struct aluno alunos[], int qtd_aluno);
void listarAlunosOrdenadosPorNome(struct aluno alunos[], int qtd_aluno);
void listarAlunosOrdenadosPorDataNascimento(struct aluno alunos[], int qtd_aluno);

void listarProfessorPorSexo(struct professor professores[], int qtd_professor);
void listarProfessoresOrdenadosPorNome(struct professor professores[], int qtd_professor);
void listarProfessoresOrdenadosPorDataNascimento(struct professor professores[], int qtd_professor);

int listarAniversariante(struct aluno alunos[], struct professor professores[], int qtd_aluno, int qtd_professor);
void listarAlunoComMenosDeTresDisciplinas(struct aluno alunos[], int qtd_aluno);
void listarDisciplinasQueExtrapolam40Vagas(struct disciplina disciplinas[], int qtd_disciplina);
void listarPessoas();

int interfaceRel() {
    bool sair_rel = 0;
    while (!sair_rel) {
        puts("\x1b[0;36m╔═════════════════════════════════════════════╗\x1b[0;0m");
        puts("\x1b[0;36m║______     _       _             _           ║\x1b[0;0m");
        puts("\x1b[0;36m║| ___ \\   | |     | |           (_)          ║\x1b[0;0m");
        puts("\x1b[0;36m║| |_/ /___| | __ _| |_ ___  _ __ _  ___  ___ ║\x1b[0;0m");
        puts("\x1b[0;36m║|    // _ \\ |/ _` | __/ _ \\| '__| |/ _ \\/ __|║\x1b[0;0m");
        puts("\x1b[0;36m║| |\\ \\  __/ | (_| | || (_) | |  | | (_) \\__ \\║\x1b[0;0m");
        puts("\x1b[0;36m║\\_| \\_\\___|_|\\__,_|\\__\\___/|_|  |_|\\___/|___/║\x1b[0;0m");
        puts("\x1b[0;36m╚═════════════════════════════════════════════╝\x1b[0;0m");
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

        // printf("|%c|%c|", c1, c2);
        int op;

        if (c2 == '\n') {
            char int1 = c1;
            op = int1 - '0';
            // printf("|first %d|", op);
        } else {
            char int1 = c1;
            int op0 = int1 - '0';
            char int2 = c2;
            int op1 = int2 - '0';
            op = (op0 * 10) + op1;
            // printf("|second %d|", op);
        }

        // printf(" op: %d ", op);

        switch (op) {
            case 67:  // sai da aplicação
                return 0;
                break;

            case 0:  // listar alunos
                listarAlunos();
                break;

            case 1:  // listar professores
                listarProfessores();
                break;

            case 2:  // listar disciplinas
                listarDisciplinas();
                break;

            case 3:  // listar uma disciplina
                listarUmaDisciplina();
                break;

            case 4:  // listar alunos por sexo
                listarAlunoPorSexo(alunos, qtd_aluno);
                break;

            case 5:  // listar alunos por nome
                listarAlunosOrdenadosPorNome(alunos, qtd_aluno);
                break;

            case 6:  // listar alunos por data de nascimento
                listarAlunosOrdenadosPorDataNascimento(alunos, qtd_aluno);
                break;

            case 7:  // listar professores por sexo
                listarProfessorPorSexo(professores, qtd_professor);
                break;

            case 8:  // listar professores por nome
                listarProfessoresOrdenadosPorNome(professores, qtd_professor);
                break;

            case 9:  // listar professores por data de nascimento
                listarProfessoresOrdenadosPorDataNascimento(professores, qtd_professor);
                break;

            case 10:  // listar aniversariantes do mês
                listarAniversariante(alunos, professores, qtd_aluno, qtd_professor);
                break;

            case 11:  // listar pessoas (buscar)
                listarPessoas();
                break;

            case 12:  // listar alunos matriculados em menos de 3 disciplinas
                listarAlunoComMenosDeTresDisciplinas(alunos, qtd_aluno);
                break;

            case 13:  // listar disciplinas que extrapolam 40 vagas
                listarDisciplinasQueExtrapolam40Vagas(disciplinas, qtd_disciplina);
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%d\" nao existe\n", op);
                break;
        }
    }
}

void listarAlunos() {
    if (qtd_aluno == 0) {
        printf("\x1b[0;33m[WARNING]: Sem alunos cadastrados\x1b[0;0m\n");
        return;
    }
    printf("\n--LISTA DE ALUNOS--\n\n");
    for (int i = 0; i < MAX_num_alunos; i++) {
        if (alunos[i].ativo) {
            printFormatAlunoData(i);
        }
    }
}

void listarProfessores() {
    if (qtd_professor == 0) {
        printf("\x1b[0;33m[WARNING]: Sem professores cadastrados\x1b[0;0m\n");
        return;
    }
    printf("\n--LISTA DE PROFESSORES--\n\n");
    for (int i = 0; i < MAX_num_professores; i++) {
        if (professores[i].ativo) {
            printFormatProfessorData(i);
        }
    }
}

void listarDisciplinas() {
    if (qtd_disciplina == 0) {
        printf("\x1b[0;33m[WARNING]: Sem disciplinas cadastrados\x1b[0;0m\n");
        return;
    }
    printf("\n--LISTA DE Disciplinas--\n\n");
    for (int i = 0; i < MAX_num_disciplinas; i++) {
        if (disciplinas[i].ativo) {
            printFormatDisciplinaData(i);
        }
    }
}

void listarUmaDisciplina() {
    if (qtd_disciplina == 0) {
        printf("\x1b[0;33m[WARNING]: Sem disciplinas cadastrados\x1b[0;0m\n");
        return;
    }

    printf("\x1b[0;36m[INPUT]: Disciplina(Código): \x1b[0;0m");
    int id;
    scanf(" %d", &id);
    clear();

    if (id > MAX_num_disciplinas) {
        printf("\x1b[0;31m[ERROR]: Disciplina inválida!, a disciplina escolhida não existe\x1b[0;0m\n");
        return;
    }

    printf("\n--DISCIPLINA--\n\n");
    printFormatDisciplinaData(id);

    printf("\n--ALUNOS--\n\n");
    for (int i = 0; i < MAX_num_alunos; i++) {
        if (!alunos[i].ativo) {
            continue;
        }
        if (!alunos[i].disciplinas[id]) {
            continue;
        }
        printFormatAlunoData(i);
    }
}

void listarAlunoPorSexo(struct aluno alunos[], int qtd_aluno) {
    if (qtd_aluno == 0) {
        printf("\x1b[0;33m[WARNING]: Sem alunos cadastrados\x1b[0;0m\n");
    } else {
        printf("\x1b[0;36m[INPUT]: Digite o sexo a ser listado (M ou F)\x1b[0;0m");
        char sexo;
        scanf(" %c", &sexo);
        sexo = toupper(sexo);

        if (sexo == 'M') {
            printf("\n--LISTA DE ALUNOS DO SEXO MASCULINO--\n\n");
            for (int i = 0; i < qtd_aluno; i++) {
                if (!alunos[i].ativo) {
                    continue;  //! impede de mostrar os alunos que não estao ativos
                }
                if (alunos[i].sexo == 'M') {
                    printFormatAlunoData(i);  //! método com formatação unificada dos commandos
                }
            }
        } else if (sexo == 'F') {
            printf("\n--LISTA DE ALUNAS DO SEXO FEMININO--\n\n");
            for (int i = 0; i < qtd_aluno; i++) {
                if (!alunos[i].ativo) {
                    continue;  //! impede de mostrar os alunos que não estao ativos
                }
                if (alunos[i].sexo == 'F') {
                    printFormatAlunoData(i);
                }
            }

        } else {
            printf("\x1b[0;31m[ERROR]: Sexo inválido! Digite M ou F\x1b[0;0m\n");
        }
    }
}
// não entendi ainda como usar ponteiros então vou ter que repetir a função pra professor :(
// ah e tentei substituir as entradas pelos inputs, mas nao deu certo (os ponteiros!!!)

void listarAlunosOrdenadosPorNome(struct aluno alunos[], int qtd_aluno) {
    if (qtd_aluno == 0) {
        printf("\x1b[0;33m[WARNING]: Sem alunos cadastrados\x1b[0;0m\n");
        return;
    }

    // Ordenação por nome
    for (int i = 0; i < qtd_aluno - 1; i++) {
        for (int j = i + 1; j < qtd_aluno; j++) {
            if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
                struct aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    printf("\n--LISTA DE ALUNOS ORDENADOS POR NOME--\n\n");
    for (int i = 0; i < qtd_aluno; i++) {
        if (!alunos[i].ativo) {
            continue;  //! impede de mostrar os alunos que não estao ativos
        }
        printFormatAlunoData(i);
    }
}

void listarAlunosOrdenadosPorDataNascimento(struct aluno alunos[], int qtd_aluno) {
    if (qtd_aluno == 0) {
        printf("\x1b[0;33m[WARNING]: Sem alunos cadastrados\x1b[0;0m\n");
        return;
    }

    // Ordenação por data de nascimento
    for (int i = 0; i < qtd_aluno - 1; i++) {
        for (int j = i + 1; j < qtd_aluno; j++) {
            if (alunos[i].nascimento.ano > alunos[j].nascimento.ano ||
                (alunos[i].nascimento.ano == alunos[j].nascimento.ano && alunos[i].nascimento.mes > alunos[j].nascimento.mes) ||
                (alunos[i].nascimento.ano == alunos[j].nascimento.ano && alunos[i].nascimento.mes == alunos[j].nascimento.mes && alunos[i].nascimento.dia > alunos[j].nascimento.dia)) {
                struct aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    printf("\n--LISTA DE ALUNOS ORDENADOS POR DATA DE NASCIMENTO--\n\n");
    for (int i = 0; i < qtd_aluno; i++) {
        if (!alunos[i].ativo) {
            continue;  //! impede de mostrar os alunos que não estao ativos
        }
        printFormatAlunoData(i);
    }
}

void listarProfessorPorSexo(struct professor professores[], int qtd_professor) {
    if (qtd_professor == 0) {
        printf("\x1b[0;33m[WARNING]: Sem professores cadastrados\x1b[0;0m\n");
    } else {
        printf("\x1b[0;36m[INPUT]: Digite o sexo a ser listado (M ou F)\x1b[0;0m");
        char sexo;
        scanf(" %c", &sexo);
        sexo = toupper(sexo);

        if (sexo == 'M') {
            printf("\n--LISTA DE PROF. DO SEXO MASCULINO--\n\n");
            for (int i = 0; i < qtd_professor; i++) {
                if (!professores[i].ativo) {
                    continue;  //! impede de mostrar os alunos que não estao ativos
                }
                if (alunos[i].sexo == 'M') {
                    printFormatProfessorData(i);
                }
            }
        } else if (sexo == 'F') {
            printf("\n--LISTA DE PROF. DO SEXO FEMININO--\n\n");
            for (int i = 0; i < qtd_professor; i++) {
                if (!professores[i].ativo) {
                    continue;  //! impede de mostrar os alunos que não estao ativos
                }
                if (professores[i].sexo == 'F') {
                    printFormatProfessorData(i);
                }
            }

        } else {
            printf("\x1b[0;31m[ERROR]: Sexo inválido! Digite M ou F\x1b[0;0m\n");
        }
    }
}

void listarProfessoresOrdenadosPorNome(struct professor professores[], int qtd_professor) {
    if (qtd_professor == 0) {
        printf("\x1b[0;33m[WARNING]: Sem professores cadastrados\x1b[0;0m\n");
        return;
    }

    // Ordenação por nome
    for (int i = 0; i < qtd_professor - 1; i++) {
        for (int j = i + 1; j < qtd_professor; j++) {
            if (strcmp(professores[i].nome, professores[j].nome) > 0) {
                struct professor temp = professores[i];
                professores[i] = professores[j];
                professores[j] = temp;
            }
        }
    }

    printf("\n--LISTA DE PROFESSORES ORDENADOS POR NOME--\n\n");
    for (int i = 0; i < qtd_professor; i++) {
        if (!professores[i].ativo) {
            continue;  //! impede de mostrar os professores que não estao ativos
        }
        printFormatProfessorData(i);
    }
}

void listarProfessoresOrdenadosPorDataNascimento(struct professor professores[], int qtd_professor) {
    if (qtd_professor == 0) {
        printf("\x1b[0;33m[WARNING]: Sem professores cadastrados\x1b[0;0m\n");
        return;
    }

    // Ordenação por data de nascimento
    for (int i = 0; i < qtd_professor - 1; i++) {
        for (int j = i + 1; j < qtd_professor; j++) {
            if (professores[i].nascimento.ano > professores[j].nascimento.ano ||
                (professores[i].nascimento.ano == professores[j].nascimento.ano && professores[i].nascimento.mes > professores[j].nascimento.mes) ||
                (professores[i].nascimento.ano == professores[j].nascimento.ano && professores[i].nascimento.mes == professores[j].nascimento.mes && professores[i].nascimento.dia > professores[j].nascimento.dia)) {
                struct professor temp = professores[i];
                professores[i] = professores[j];
                professores[j] = temp;
            }
        }
    }

    printf("\n--LISTA DE PROFESSORES ORDENADOS POR DATA DE NASCIMENTO--\n\n");
    for (int i = 0; i < qtd_professor; i++) {
        if (!professores[i].ativo) {
            continue;  //! impede de mostrar os professores que não estao ativos
        }
        printFormatProfessorData(i);
    }
}

int listarAniversariante(struct aluno alunos[], struct professor professores[], int qtd_aluno, int qtd_professor) {
    if (qtd_aluno == 0 && qtd_professor == 0) {
        printf("\x1b[0;33m[WARNING]: Não exitem alunos ou professores cadastradoss\x1b[0;0m\n");
    } else {
        printf("\x1b[0;36m[INPUT]: Insira o mês (em algarismo) para buscar aniversariantes\x1b[0;0m\n");
        int mes;
        scanf("%d", &mes);

        if (mes < 1 || mes > 12) {
            printf("\x1b[0;31m[ERROR]:Mês inválido! Digite um mês entre 1 e 12\x1b[0;0m\n");
        } else {
            int qtdAniversariante = 0;
            if (qtd_aluno > 0) {
                printf("\n--ALUNOS ANIVERSARIANTES--\n");
                for (int i = 0; i < qtd_aluno; i++) {
                    if (alunos[i].ativo == true && alunos[i].nascimento.mes == mes) {
                        printFormatAlunoData(i);
                        qtdAniversariante++;
                    }
                }
            }
            if (qtd_professor > 0) {
                printf("\n--PROFESSORES ANIVERSARIANTES--\n");
                for (int i = 0; i < qtd_professor; i++) {
                    if (professores[i].ativo == true && professores[i].nascimento.mes == mes) {
                        printFormatProfessorData(i);
                        qtdAniversariante++;
                    }
                }
            }
            if (qtdAniversariante == 0)
                printf("\x1b[0;36m[INFO]: Não há aniversariantes nesse mês\x1b[0;0m\n");
            else
                printf("\n[Listagem concluída!]\n");
        }
    }
}

void listarAlunoComMenosDeTresDisciplinas(struct aluno alunos[], int qtd_aluno) {
    int listados = 0;
    int j = 0;
    while (j < qtd_aluno) {
        int qtdDisciplinas = 0;
        for (int i = 0; i < MAX_num_disciplinas; i++) {
            if (alunos[j].disciplinas[i]) {
                qtdDisciplinas++;
            }
        }
        if (qtdDisciplinas < 3) {
            if (!alunos[j].ativo) {
                continue;  //! impede de mostrar os alunos que não estao ativos
            }
            printFormatAlunoData(j);
            listados++;
        }
        j++;
    }
    if (listados == 0) {
        printf("\x1b[0;36m[INFO]: Não há alunos com menos de 3 disciplinas\x1b[0;0m\n");
    }
}

void listarDisciplinasQueExtrapolam40Vagas(struct disciplina disciplinas[], int qtd_disciplina) {
    if (qtd_disciplina == 0) {
        printf("\x1b[0;33m[WARNING]: Não há disciplinas cadastradas\x1b[0;0m\n");
    } else {
        int disciplinaExtrapolada = false;
        for (int i = 0; i < qtd_disciplina; i++) {  //! ao fim de tudo vou impedir que de para editar um valor maior q o qtd_aluno, entao não tem pq varrer tudo, errei fui mlk
            if (!disciplinas[i].ativo) {
                continue;
            }
            //! acho melhor varrer o obj de alunos e contabilizar nas disciplinas localmente aqui do que depender da variavel.vaga_preenchida pq se um aluno for removido teria de re-calcular esse valor. e tbm esse valor so eh útil para listar aqui por enquanto. mas vou manter caso façamos algo q precise depois
            int tmp_vaga_preenchida = 0;
            for (int a = 0; a < qtd_aluno; a++) {
                if (!alunos[a].ativo) {
                    continue;
                }
                if (alunos[a].disciplinas[i]) {
                    tmp_vaga_preenchida++;
                }
            }
            disciplinas[i].vaga_preenchida = tmp_vaga_preenchida;
            if (disciplinas[i].vaga_preenchida > 40) {
                printFormatDisciplinaData(i);
                disciplinaExtrapolada = true;
            }
        }
        if (disciplinaExtrapolada == false)
            printf("\x1b[0;36m[INFO]: Não há disciplinas com mais de 40 vagas\x1b[0;0m\n");
    }
}

void listarPessoas() {
    printf("\x1b[0;36m[INPUT]: buscar por: \x1b[0;0m");
    char word[MAX_char_nome];
    fgets(word, MAX_char_nome, stdin);
    word[strcspn(word, "\n")] = 0;
    clear();

    if (word[0] == '\n' || word[1] == '\n' || word[2] == '\n') {
        printf("\x1b[0;31m[ERROR]: A palavra de busca não pode ser menor que 3 caracteres\x1b[0;0m\n");
        return;
    }

    printf("\n--ALUNOS--\n");
    for (int i = 0; i < MAX_num_alunos; i++) {
        if (!alunos[i].ativo) {
            continue;  //! impede de mostrar os alunos que não estao ativos
        }
        if (strstr(alunos[i].nome, word) != NULL) {
            printFormatAlunoData(i);
        }
    }

    printf("\n--PROFESSORES--\n");
    for (int i = 0; i < MAX_num_professores; i++) {
        if (!professores[i].ativo) {
            continue;  //! impede de mostrar os professores que não estao ativos
        }
        if (strstr(professores[i].nome, word) != NULL) {
            printFormatProfessorData(i);
        }
    }
}
