#include <stdio.h>
#include <string.h>  // Necessário para usar strcmp e strcpy
#include "aluno.h"

int menuAluno() {
    int opcao;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar aluno\n");
    printf("3 - Atualizar aluno\n");
    printf("4 - Excluir aluno\n");

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
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula)
                return MATRICULA_EXISTENTE;
        }

        DataNascimento data = lerDataNascimento(); //! acho melhor passar as funcoes de validação de data para o mesmo arquivo, eles nao precisam de um exclusivo
        //! mas o código deles será incorporado^^
        int sexo;
        do {
            printf("Digite o sexo do aluno (M/F):\n");

            // Limpar o buffer
            getchar(); //! a mesma questão do buffer como eu digo depois

            scanf(" %c", &sexo);  //! roubei esse método pq é mais limpo que oq eu usei↓↓↓↓↓
            sexo = toupper(sexo); // Converte para maiúscula

            if (sexo != 'M' && sexo != 'F') {
                printf("Sexo inválido. Digite M ou F!\n");
                // Limpa o buffer de entrada, para nova leitura de scanf
                getchar();
            }
        } while (sexo != 'M' && sexo != 'F');

        // Limpar o buffer antes de usar fgets
        getchar(); //! na funcao clear() do arquivo interface_main.c getchar é usado ate retornar um '\n' então seria um metodo mais seguro de limpar o buffer

        printf("Digite o CPF do aluno:\n"); //! o código para isso é o mesmo, só que em uma unção própria
        char cpf[MAX_CPF];                  //! ^^
        fgets(cpf, MAX_CPF, stdin);         //! ^^roubei essa linha abaixo↓↓
        cpf[strcspn(cpf, "\n")] = 0;  // Remove o '\n' no final da string

        for (int i = 0; i < qtdAluno; i++) {         //! na funcao alunoInputCPF() atualmente eu estou transformando para
            if (strcmp(listaAluno[i].cpf, cpf) == 0) //! numero inteiro depois de pegar como string mas mudarei isso por causa
                return CPF_EXISTENTE;                //! do problema de inteiro começando com "0"
        }

        printf("Digite o nome do aluno:\n"); //! o código para isso é o mesmo, só que em uma unção própria
        char nome[MAX_NOME];                 //! ^^
        fgets(nome, MAX_NOME, stdin);        //! ^^roubei essa linha abaixo↓↓
        nome[strcspn(nome, "\n")] = 0;  // Remove o '\n' no final da string

        // Transferir os dados para a lista de alunos
        listaAluno[qtdAluno].matricula = matricula;
        strcpy(listaAluno[qtdAluno].cpf, cpf);
        strcpy(listaAluno[qtdAluno].nome, nome);
        listaAluno[qtdAluno].sexo = sexo;
        listaAluno[qtdAluno].ativo = TRUE;
        listaAluno[qtdAluno].data = data;

        printf("Cadastro realizado com sucesso\n");
        return CAD_ALUNO_SUCESSO;
    }
}

void listarAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("-- Lista de alunos vazia --\n");
    } else {
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].ativo == TRUE) {//! o mesmo código ja existe so que sem essa parte de aluno.ativo ainda, roubarei isso :)
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Sexo: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento: %d/%d/%d\n", listaAluno[i].data.dia, listaAluno[i].data.mes, listaAluno[i].data.ano);
            }
        }
    }
}

int atualizarMatriculaAluno(Aluno listaAluno[], int qtdAluno) {//! as funcoes de atualizar** serão juntas nas mesmas que pegam as informações normalmente
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

int atualizarNomeAluno(Aluno listaAluno[], int qtdAluno) {//!^^
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

int atualizarSexoAluno(Aluno listaAluno[], int qtdAluno) {//!^^
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

int atualizarCpfAluno(Aluno listaAluno[], int qtdAluno) {//!^^
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

int atualizarDataNascAluno(Aluno listaAluno[], int qtdAluno) {//!^^
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

int excluirAluno(Aluno listaAluno[], int qtdAluno) {//! falta implementar isso no código vou me apropriar dessa função
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

