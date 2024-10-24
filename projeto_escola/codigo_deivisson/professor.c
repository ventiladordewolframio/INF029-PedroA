#include "professor.h"

#include <stdio.h>
#include <string.h>  // Necessário para usar strcmp e strcpy
//! a formatação automatica dnv vai causar certas linhas constarem como modificadas mas as nao tem comentários não foram modificadas de qualquer forma

int menuProfessor() {
    int opcao;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar professor\n");
    printf("2 - Listar professor\n");
    printf("3 - Atualizar professor\n");
    printf("4 - Excluir professor\n");

    scanf("%d", &opcao);
    return opcao;
}

int menuAtualizarProfessor() {
    int opcaoAtualizar;
    printf("0 - Voltar\n");
    printf("1 - Atualizar matrícula professor\n");
    printf("2 - Atualizar nome professor\n");
    printf("3 - Atualizar sexo professor\n");
    printf("4 - Atualizar cpf professor\n");
    printf("5 - Atualizar data de nascimento professor\n");

    scanf("%d", &opcaoAtualizar);
    return opcaoAtualizar;
}

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == TAM_PROFESSOR) {
        return LISTA_CHEIA;
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula)
                return MATRICULA_EXISTENTE;
        }

        DataNascimento data = lerDataNascimento();

        int sexo;
        do {
            printf("Digite o sexo do professor (M/F):\n");

            // Limpar o buffer
            getchar();

            scanf(" %c", &sexo);
            sexo = toupper(sexo);  // Converte para maiúscula

            if (sexo != 'M' && sexo != 'F') {
                printf("Sexo inválido. Digite M ou F!\n");
                // Limpa o buffer de entrada, para nova leitura de scanf
                getchar();
            }
        } while (sexo != 'M' && sexo != 'F');

        // Limpar o buffer antes de usar fgets
        getchar();

        printf("Digite o CPF do professor:\n");
        char cpf[MAX_CPF];
        fgets(cpf, MAX_CPF, stdin);
        cpf[strcspn(cpf, "\n")] = 0;  // Remove o '\n' no final da string

        for (int i = 0; i < qtdProfessor; i++) {
            if (strcmp(listaProfessor[i].cpf, cpf) == 0)
                return CPF_EXISTENTE;
        }

        printf("Digite o nome do professor:\n");
        char nome[MAX_NOME];
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;  // Remove o '\n' no final da string

        // Transferir os dados para a lista de alunos
        listaProfessor[qtdProfessor].matricula = matricula;
        strcpy(listaProfessor[qtdProfessor].cpf, cpf);
        strcpy(listaProfessor[qtdProfessor].nome, nome);
        listaProfessor[qtdProfessor].sexo = sexo;
        listaProfessor[qtdProfessor].ativo = TRUE;
        listaProfessor[qtdProfessor].data = data;

        printf("Cadastro realizado com sucesso\n");
        return CAD_PROFESSOR_SUCESSO;
    }
}

void listarProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("-- Lista de professores vazia --\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].ativo == TRUE) {
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                printf("Nome: %s\n", listaProfessor[i].nome);
                printf("CPF: %s\n", listaProfessor[i].cpf);
                printf("Sexo: %c\n", listaProfessor[i].sexo);
                printf("Data de nascimento: %d/%d/%d\n", listaProfessor[i].data.dia, listaProfessor[i].data.mes, listaProfessor[i].data.ano);
            }
        }
    }
}

int atualizarMatriculaProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("--Não há professores cadastrados--\n");
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
                printf("Digite a nova matrícula:\n");
                int novaMatricula;
                scanf("%d", &novaMatricula);
                if (novaMatricula < 0) {
                    return MATRICULA_INVALIDA;
                }
                listaProfessor[i].matricula = novaMatricula;
                return ATUALIZACAO_PROFESSOR_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarNomeProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("--Não há professores cadastrados--\n");
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
                getchar();
                printf("Digite o novo nome:\n");
                char novoNome[MAX_NOME];
                fgets(novoNome, MAX_NOME, stdin);
                novoNome[strcspn(novoNome, "\n")] = 0;

                strcpy(listaProfessor[i].nome, novoNome);
                return ATUALIZACAO_PROFESSOR_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarSexoProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("--Não há professores cadastrados--\n");
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
                char novoSexo;
                do {
                    printf("Digite o novo sexo do professor (M/F):\n");

                    // Limpar o buffer
                    getchar();

                    scanf(" %c", &novoSexo);
                    novoSexo = toupper(novoSexo);  // Converte para maiúscula
                    listaProfessor[i].sexo = novoSexo;
                    return ATUALIZACAO_PROFESSOR_SUCESSO;

                    if (novoSexo != 'M' && novoSexo != 'F') {
                        printf("Sexo inválido. Digite M ou F!\n");
                        // Limpa o buffer de entrada, para nova leitura de scanf
                        getchar();
                    }
                } while (novoSexo != 'M' && novoSexo != 'F');
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarCpfProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("--Não há professores cadastrados--\n");
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
                char novoCpf[MAX_CPF];
                ;
                printf("Digite o novo cpf do professor (M/F):\n");

                // Limpar o buffer
                getchar();
                fgets(novoCpf, MAX_CPF, stdin);
                novoCpf[strcspn(novoCpf, "\n")] = 0;

                strcpy(listaProfessor[i].cpf, novoCpf);
                return ATUALIZACAO_PROFESSOR_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int atualizarDataNascProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("--Não há professores cadastrados--\n");
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
                DataNascimento data = lerDataNascimento();
                listaProfessor[i].data = data;
                return ATUALIZACAO_PROFESSOR_SUCESSO;
            }
        }
        return MATRICULA_INEXISTENTE;
    }
}

int excluirProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Digite a matrícula do professor:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }
    for (int i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
            listaProfessor[i].ativo = FALSE;
            return EXCLUSAO_PROFESSOR_SUCESSO;
        }
    }
    return MATRICULA_INEXISTENTE;
}
