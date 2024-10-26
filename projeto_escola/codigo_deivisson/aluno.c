#include <stdio.h>
#include <string.h> // Necessário para usar strcmp e strcpy
#include <ctype.h>
#include "aluno.h"

int menuAluno() {
    int opcao;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar aluno\n");
    printf("3 - Atualizar aluno\n");
    printf("4 - Excluir aluno\n");
    printf("5 - Listar aluno ordenado por sexo\n");

    scanf("%d", &opcao);
    return opcao;
}

int menuAtualizarAluno() { 
    int opcaoAtualizar;
    printf("0 - Voltar\n");
    printf("1 - Atualizar matrícula aluno\n");
    printf("2 - Atualizar nome aluno\n");
    printf("3 - Atualizar sexo aluno\n");
    printf("4 - Atualizar cpf aluno\n");
    printf("5 - Atualizar data de nascimento aluno\n");

    scanf("%d", &opcaoAtualizar);
    return opcaoAtualizar;
}


int cadastrarAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == TAM_ALUNO) {
        return LISTA_CHEIA;
    } else {
            
        DataNascimento data = lerDataNascimento();

        char sexo;
        do {
            printf("Digite o sexo do aluno (M/F):\n");

            // Limpar o buffer
            getchar();

            scanf(" %c", &sexo);
            sexo = toupper(sexo); // Converte para maiúscula

            if (sexo != 'M' && sexo != 'F') {
                printf("Sexo inválido. Digite M ou F!\n");
                // Limpa o buffer de entrada, para nova leitura de scanf
                getchar();
            }
        } while (sexo != 'M' && sexo != 'F');

        // Limpar o buffer antes de usar fgets
        getchar();

        printf("Digite o CPF do aluno:\n");
        char cpf[MAX_CPF];
        fgets(cpf, MAX_CPF, stdin);
        cpf[strcspn(cpf, "\n")] = 0;  // Remove o '\n' no final da string

        for (int i = 0; i < qtdAluno; i++) {
            if (strcmp(listaAluno[i].cpf, cpf) == 0)
                return CPF_EXISTENTE;
        }

        printf("Digite o nome do aluno:\n");
        char nome[MAX_NOME];
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;  // Remove o '\n' no final da string

        // Transferir os dados para a lista de alunos
        listaAluno[qtdAluno].matricula = qtdAluno + 1;
        strcpy(listaAluno[qtdAluno].cpf, cpf);
        strcpy(listaAluno[qtdAluno].nome, nome);
        listaAluno[qtdAluno].sexo = sexo;
        listaAluno[qtdAluno].ativo = TRUE;
        listaAluno[qtdAluno].data = data;

        printf("Mátricula = %d\n", listaAluno[qtdAluno].matricula);
        return CAD_ALUNO_SUCESSO;
    }
}

void listarAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("-- Lista de alunos vazia --\n");
    } else {
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].ativo == TRUE) {
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            }
        }
    }
}

int atualizarMatriculaAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("--Não há alunos cadastrados--\n");
    } else {
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
                printf("Digite a nova matrícula:\n");
                int novaMatricula;
                scanf("%d", &novaMatricula);
                if (novaMatricula < 0) {
                    return MATRICULA_INVALIDA;
                }
                listaAluno[i].matricula = novaMatricula;
                return ATUALIZACAO_ALUNO_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarNomeAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("--Não há alunos cadastrados--\n");
    } else {
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
                getchar();  // Limpar o buffer antes de ler o nome
                printf("Digite o novo nome:\n");
                char novoNome[MAX_NOME];
                fgets(novoNome, MAX_NOME, stdin);
                novoNome[strcspn(novoNome, "\n")] = 0;  // Remove o '\n' no final da string

                strcpy(listaAluno[i].nome, novoNome);
                return ATUALIZACAO_ALUNO_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarSexoAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("--Não há alunos cadastrados--\n");
    } else {
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
                char novoSexo;
                do {
                    printf("Digite o novo sexo do aluno (M/F):\n");
                    getchar();  // Limpar o buffer
                    scanf(" %c", &novoSexo);
                    novoSexo = toupper(novoSexo); // Converte para maiúscula
                    if (novoSexo == 'M' || novoSexo == 'F') {
                        listaAluno[i].sexo = novoSexo;
                        return ATUALIZACAO_ALUNO_SUCESSO;
                    } else {
                        printf("Sexo inválido. Digite M ou F!\n");
                    }
                } while (novoSexo != 'M' && novoSexo != 'F');
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarCpfAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("--Não há alunos cadastrados--\n");
    } else {
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
                char novoCpf[MAX_CPF];
                printf("Digite o novo CPF do aluno:\n");
                getchar();  // Limpar o buffer
                fgets(novoCpf, MAX_CPF, stdin);
                novoCpf[strcspn(novoCpf, "\n")] = 0;  // Remove o '\n' no final da string

                strcpy(listaAluno[i].cpf, novoCpf);
                return ATUALIZACAO_ALUNO_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarDataNascAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("--Não há alunos cadastrados--\n");
    } else {
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
                DataNascimento data = lerDataNascimento();
                listaAluno[i].data = data;
                return ATUALIZACAO_ALUNO_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int excluirAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Digite a matrícula do aluno:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
            listaAluno[i].ativo = FALSE;
            return EXCLUSAO_ALUNO_SUCESSO;
        }
    }
    return MATRICULA_INEXISTENTE;
}

int listarAlunoPorSexo(Aluno listaAluno[], int qtdAluno) {
    if(qtdAluno == 0){
        return SEM_ALUNO;
    }
    getchar();
    printf("Digite o sexo a ser listado (M ou F)");
    char sexo;
    scanf(" %c", &sexo);
    sexo = toupper(sexo);
    
    if(sexo == 'M'){
        printf("\n--LISTA DE ALUNOS DO SEXO MASCULINO--\n\n");
        for(int i=0; i<qtdAluno; i++){
            if (listaAluno[i].ativo == TRUE && listaAluno[i].sexo == 'M') {
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            }
        }
        return SUCESSO;
    } else if(sexo == 'F'){
        printf("\n--LISTA DE ALUNAS DO SEXO FEMININO--\n\n");
        for(int i=0; i<qtdAluno; i++){
            if (listaAluno[i].ativo == TRUE && listaAluno[i].sexo == 'F') {
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            }
            
        }
        return SUCESSO;
    } else {
        return SEXO_INVALIDO;
    }
}

