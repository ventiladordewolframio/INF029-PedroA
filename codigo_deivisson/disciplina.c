#include <stdio.h>
#include <ctype.h>  // Necessário para usar toupper()
#include <string.h>  // Necessário para usar strcmp e strcpy
#include "disciplina.h"

int menuDisciplina() {
    int opcao;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar disciplina\n");
    printf("2 - Listar disciplina\n");
    printf("3 - Atualizar disciplina\n");
    printf("4 - Excluir disciplina\n");
    printf("5 - Adicionar professor a disciplina\n");
    printf("6 - Adicionar aluno a disciplina\n");
    printf("7 - Listar alunos matriculados em disciplina\n");

    scanf("%d", &opcao);
    return opcao;
}

int menuAtualizarDisciplina() {
    int opcaoAtualizar;
    printf("0 - Voltar\n");
    printf("1 - Atualizar código da disciplina\n");
    printf("2 - Atualizar nome da disciplina\n");
    printf("3 - Atualizar semestre da disciplina\n");
    printf("4 - Atualizar professores da disciplina\n");

    scanf("%d", &opcaoAtualizar);
    return opcaoAtualizar;
}

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    if (qtdDisciplina == TAM_DISCIPLINA) {
        return LISTA_DISCIPLINA_CHEIA;
    } else {
        getchar();
        printf("Digite o código da disciplina:\n");
        char codigo[MAX_CODIGO]; 
        fgets(codigo, MAX_CODIGO, stdin);
        codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
        int i = 0;
        while(codigo[i] != '\0') {
            codigo[i] = toupper(codigo[i]);
            i++;
        }
        // Verificar se o código já existe
        for (int i = 0; i < qtdDisciplina; i++) {
            if (strcmp(listaDisciplina[i].codigo, codigo) == 0) {
                return DISCIPLINA_EXISTENTE;
            }
        }

        printf("Digite o nome da disciplina:\n");
        char nome[MAX_NOME];
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;  // Remove o '\n' no final da string

        printf("Digite o semestre da disciplina:\n");
        int semestre;
        scanf("%d", &semestre);  // Corrigido para usar o endereço de semestre

        // Transferir os dados para a lista de disciplinas
        strcpy(listaDisciplina[qtdDisciplina].codigo, codigo);
        strcpy(listaDisciplina[qtdDisciplina].nome, nome);
        listaDisciplina[qtdDisciplina].semestre = semestre;
        listaDisciplina[qtdDisciplina].ativo = TRUE;
        listaDisciplina[qtdDisciplina].numProfessores = 0;  // Inicializa o contador de professores

        return CAD_DISCIPLINA_SUCESSO;
    }
}

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    if (qtdDisciplina == 0) {
        printf("-- Lista de disciplinas vazia --\n");
    } else {
        for (int i = 0; i < qtdDisciplina; i++) {
            if (listaDisciplina[i].ativo == TRUE) {
                printf("Código: %s\n", listaDisciplina[i].codigo);
                printf("Nome: %s\n", listaDisciplina[i].nome);
                printf("Semestre: %d\n", listaDisciplina[i].semestre);
            }
        }
    }
}

int atualizarCodigoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    if (qtdDisciplina == 0) {
        printf("-- Não há disciplinas cadastradas --\n");
        return DISCIPLINA_INEXISTENTE;
    } else {
        getchar();
        printf("Digite o código da disciplina:\n");
        char codigo[MAX_CODIGO]; 
        fgets(codigo, MAX_CODIGO, stdin);
        codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
        int i = 0;
        while(codigo[i] != '\0') {
            codigo[i] = toupper(codigo[i]);
            i++;
        }

        for (int i = 0; i < qtdDisciplina; i++) {
            if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
                printf("Digite o novo código:\n");
                char novoCodigo[MAX_CODIGO];
                fgets(novoCodigo, MAX_CODIGO, stdin);
                novoCodigo[strcspn(novoCodigo, "\n")] = 0; // Remove o '\n'
                // Atualiza o código
                strcpy(listaDisciplina[i].codigo, novoCodigo);
                return ATUALIZACAO_DISCIPLINA_SUCESSO;
            }
        }
        return DISCIPLINA_INEXISTENTE;
    }
}

int atualizarNomeDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    if (qtdDisciplina == 0) {
        printf("-- Não há disciplinas cadastradas --\n");
        return DISCIPLINA_INEXISTENTE; // Adicionei um retorno aqui
    } else {
        getchar();
        printf("Digite o código da disciplina:\n");
        char codigo[MAX_CODIGO]; 
        fgets(codigo, MAX_CODIGO, stdin);
        codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
        int i = 0;
        while(codigo[i] != '\0') {
            codigo[i] = toupper(codigo[i]);
            i++;
        }

        for (int i = 0; i < qtdDisciplina; i++) {
            if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
                printf("Digite o novo nome da disciplina:\n");
                char novoNome[MAX_NOME];
                fgets(novoNome, MAX_NOME, stdin);
                novoNome[strcspn(novoNome, "\n")] = 0;

                strcpy(listaDisciplina[i].nome, novoNome);
                return ATUALIZACAO_DISCIPLINA_SUCESSO;
            }
        }
        return DISCIPLINA_INEXISTENTE;
    }
}

int atualizarSemestreDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    if (qtdDisciplina == 0) {
        printf("-- Não há disciplinas cadastradas --\n");
        return DISCIPLINA_INEXISTENTE;
    } else {
        getchar();
        printf("Digite o código da disciplina:\n");
        char codigo[MAX_CODIGO]; 
        fgets(codigo, MAX_CODIGO, stdin);
        codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
        int i = 0;
        while(codigo[i] != '\0') {
            codigo[i] = toupper(codigo[i]);
            i++;
        }

        for (int i = 0; i < qtdDisciplina; i++) {
            if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
                printf("Digite o novo semestre da disciplina:\n");
                int novoSemestre;
                scanf("%d", &novoSemestre);

                listaDisciplina[i].semestre = novoSemestre;
                return ATUALIZACAO_DISCIPLINA_SUCESSO;
            }
        }
        return DISCIPLINA_INEXISTENTE;
    }
}

int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    getchar();
    printf("Digite o código da disciplina:\n");
    char codigo[MAX_CODIGO]; 
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
    int i = 0;
    while(codigo[i] != '\0') {
        codigo[i] = toupper(codigo[i]);
        i++;
    }

    for (int i = 0; i < qtdDisciplina; i++) {
        if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
            listaDisciplina[i].ativo = FALSE;
            return EXCLUSAO_DISCIPLINA_SUCESSO;
        }
    }
    return DISCIPLINA_INEXISTENTE;
}

int adicionarProfessorDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor) {
    // Verifica se há disciplinas cadastradas
    if (qtdDisciplina == 0) {
        return DISCIPLINA_INEXISTENTE;
    }
    if (qtdDisciplina == TAM_PROFESSOR) {
        return LISTA_CHEIA;
    }
    if (qtdProfessor == 0) {
        return MATRICULA_INEXISTENTE;
    }

    // Solicita o código da disciplina
    getchar();
    printf("Digite o código da disciplina:\n");
    char codigo[MAX_CODIGO]; 
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
    int i = 0;
    while(codigo[i] != '\0') {
        codigo[i] = toupper(codigo[i]);
        i++;
    }

    // Busca a disciplina pelo código
    int indiceDisciplina = -1;
    for (int i = 0; i < qtdDisciplina; i++) {
        if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
            indiceDisciplina = i;
            break;
        }
    }

    if (indiceDisciplina == -1) {
        return DISCIPLINA_INVALIDA;
    }
    
    // Solicita a matrícula do professor
    int matriculaProfessor;
    printf("Digite a matrícula do professor:\n");
    scanf("%d", &matriculaProfessor);

    // Busca o professor pela matrícula
    int indiceProfessor = -1;
    for (int i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].matricula == matriculaProfessor && listaProfessor[i].ativo == TRUE) {
            indiceProfessor = i;
            break;
        }
    }

    if (indiceProfessor == -1) {
        return MATRICULA_INVALIDA;
    }

    // Adiciona o professor à lista de professores da disciplina
    listaDisciplina[indiceDisciplina].listaProfessor[listaDisciplina[indiceDisciplina].numProfessores] = listaProfessor[indiceProfessor];
    listaDisciplina[indiceDisciplina].numProfessores++;
    
    return ATUALIZACAO_DISCIPLINA_SUCESSO;
}

int adicionarAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno) {
    // Verifica se há disciplinas cadastradas
    if (qtdDisciplina == 0) {
        return DISCIPLINA_INEXISTENTE;
    }

    // Solicita o código da disciplina
    getchar();
    printf("Digite o código da disciplina:\n");
    char codigo[MAX_CODIGO]; 
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
    int i = 0;
    while(codigo[i] != '\0') {
        codigo[i] = toupper(codigo[i]);
        i++;
    }

    // Busca a disciplina pelo código
    int indiceDisciplina = -1; 
    for (int i = 0; i < qtdDisciplina; i++) {
        if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
            indiceDisciplina = i;
            break;
        }
    }

    if (indiceDisciplina == -1) {
        return DISCIPLINA_INVALIDA;
    }

    // Verifica se a lista de alunos da disciplina está cheia
    if (listaDisciplina[indiceDisciplina].numAluno == TAM_ALUNO) {
        printf("-- A lista de alunos desta disciplina está cheia --\n");
        return LISTA_CHEIA;
    }

    // Solicita a matrícula do aluno
    int matriculaAluno;
    printf("Digite a matrícula do aluno a ser matriculado:\n");
    scanf("%d", &matriculaAluno);

    // Busca o aluno pela matrícula
    int indiceAluno = -1; 
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].matricula == matriculaAluno && listaAluno[i].ativo == TRUE) {
            indiceAluno = i;
            break;
        }
    }

    if (indiceAluno == -1) {
        return MATRICULA_INVALIDA;
    }

    // Adiciona o aluno à lista de alunos da disciplina
    listaDisciplina[indiceDisciplina].listaAluno[listaDisciplina[indiceDisciplina].numAluno] = listaAluno[indiceAluno];
    listaDisciplina[indiceDisciplina].numAluno++;  // Incrementa o número de alunos matriculados

    return ATUALIZACAO_DISCIPLINA_SUCESSO;
}

int listarAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno) {
    if (qtdDisciplina == TAM_DISCIPLINA)
        return LISTA_CHEIA;
    if (qtdDisciplina == 0) {
        return DISCIPLINA_INEXISTENTE;
    } else {
        // Solicita o código da disciplina
        getchar();
        printf("Digite o código da disciplina:\n");
        char codigo[MAX_CODIGO]; 
        fgets(codigo, MAX_CODIGO, stdin);
        codigo[strcspn(codigo, "\n")] = 0;  // Remove o '\n' no final da string
        int i = 0;
        while(codigo[i] != '\0') {
            codigo[i] = toupper(codigo[i]);
            i++;
        }

        // Busca a disciplina
        int indiceDisciplina = -1;
        for (int i = 0; i < qtdDisciplina; i++) {
            if (strcmp(listaDisciplina[i].codigo, codigo) == 0 && listaDisciplina[i].ativo == TRUE) {
                indiceDisciplina = i;
                break;
            }
        }

        if (indiceDisciplina == -1) {
            return DISCIPLINA_INVALIDA;
        } else {
            // Exibe os detalhes da disciplina
            printf("\nCódigo: %s\n", listaDisciplina[indiceDisciplina].codigo);
            printf("Nome: %s\n", listaDisciplina[indiceDisciplina].nome);
            printf("Semestre: %d\n", listaDisciplina[indiceDisciplina].semestre);

            // Lista os alunos da disciplina
            if (listaDisciplina[indiceDisciplina].numAluno == 0) {
                printf("-- Nenhum aluno cadastrado nesta disciplina --\n");
            } else {
                printf("\n-- Lista de alunos --\n");
                for (int j = 0; j < listaDisciplina[indiceDisciplina].numAluno; j++) {
                    int matriculaAluno = listaDisciplina[indiceDisciplina].listaAluno[j].matricula;

                    // Busca os detalhes do aluno pela matrícula
                    for (int k = 0; k < qtdAluno; k++) {
                        if (listaAluno[k].matricula == matriculaAluno && listaAluno[k].ativo == TRUE) {
                            printf("\nMatrícula: %d\n", listaAluno[k].matricula);
                            printf("Nome: %s\n", listaAluno[k].nome);
                            printf("Sexo: %c\n", listaAluno[k].sexo);
                            printf("CPF: %s\n", listaAluno[k].cpf);
                            printf("Data de nascimento: %d/%d/%d\n", listaAluno[k].data.dia, listaAluno[k].data.mes, listaAluno[k].data.ano);
                            break;
                        }
                    }
                }
            }
        }
    }
    return ATUALIZACAO_DISCIPLINA_SUCESSO;
}

