#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int menuGeral();
int listarAniversariante(Aluno listaAluno[], Professor listaProfessor[], int qtdAluno, int qtdProfessor);

int main() {
    
    Aluno listaAluno[TAM_ALUNO];
    Professor listaProfessor[TAM_PROFESSOR];
    Disciplina listaDisciplina[TAM_DISCIPLINA];
    int opcao;
    int qtdAluno = 0;
    int qtdProfessor = 0;
    int qtdDisciplina = 0;
    int sair = FALSE;

    // Tela inicial com as opções e leitura
    while (sair == FALSE) {
        opcao = menuGeral();

        // Switch para cada opção
        switch (opcao) {
            case 0: {
                sair = TRUE;
                break;
            }
            case 1: {
                printf("--------------Módulo Aluno--------------\n");
                int sairAluno = FALSE;
                int opcaoAluno;
    
                while (sairAluno == FALSE) {
                    opcaoAluno = menuAluno();
    
                    switch (opcaoAluno) {
                        case 0: {
                            sairAluno = TRUE;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarAluno(listaAluno, qtdAluno);
                            if (retorno == LISTA_CHEIA)
                                printf("Lista de alunos cheia\n");
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Matrícula inválida\n");
                            else if (retorno == MATRICULA_EXISTENTE)
                                printf("Matrícula já existente\n");
                            else if (retorno == CPF_EXISTENTE)
                                printf("CPF já existente\n");
                            else if (retorno == SEXO_INVALIDO)
                                printf("Sexo inválido\n");
                            else {
                                printf("Aluno cadastrado com sucesso!\n");
                                qtdAluno++;
                            }
                            break;
                        }
                        case 2: {
                            listarAluno(listaAluno, qtdAluno);
                            break;
                        }
                        case 3: {
                            printf("Atualizar aluno\n");
                            int sairAtualizarAluno = FALSE;
                            int opcaoAtualizarAluno;
    
                            while (sairAtualizarAluno == FALSE) {
                                opcaoAtualizarAluno = menuAtualizarAluno(); 
    
                                switch (opcaoAtualizarAluno) {
                                    case 0: {
                                        sairAtualizarAluno = TRUE;
                                        break;
                                    }
                                    case 1: {
                                        int retorno = atualizarMatriculaAluno(listaAluno, qtdAluno);
                                        if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                            printf("Matrícula de aluno atualizada com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 2: {
                                        int retorno = atualizarNomeAluno(listaAluno, qtdAluno);
                                        if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                            printf("Nome de aluno atualizado com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 3: {
                                        int retorno = atualizarSexoAluno(listaAluno, qtdAluno);
                                        if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                            printf("Sexo de aluno atualizado com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 4: {
                                        int retorno = atualizarCpfAluno(listaAluno, qtdAluno);
                                        if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                            printf("CPF do aluno atualizado com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 5: {
                                        int retorno = atualizarDataNascAluno(listaAluno, qtdAluno);
                                        if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                            printf("Data de nascimento do aluno atualizada com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4: {
                            int retorno = excluirAluno(listaAluno, qtdAluno);
                            if (retorno == EXCLUSAO_ALUNO_SUCESSO) {
                                printf("Aluno excluído com sucesso\n");
                                qtdAluno--;
                            } else if (retorno == MATRICULA_INEXISTENTE)
                                printf("Matrícula inexistente\n");
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Matrícula inválida\n");
                            break;
                        }
                        case 5: {
                            int retorno = listarAlunoPorSexo(listaAluno, qtdAluno);
                            if(retorno == SEM_ALUNO){
                                printf("--Não há alunos cadastrados--\n");
                            } else if(retorno == SEXO_INVALIDO){
                                printf("--Sexo Inválido. Digite M ou F\n");
                            } else 
                                printf("Listagem concluída com sucesso\n");
                            break;
                        }
                    }
                }
                break;
            } 
            case 2: {
                getchar();
                printf("--------------Módulo Professor--------------\n");
                int sairProfessor = FALSE;
                int opcaoProfessor;
    
                while (sairProfessor == FALSE) {
                    opcaoProfessor = menuProfessor();
    
                    switch (opcaoProfessor) {
                        case 0: {
                            sairProfessor = TRUE;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);
                            if (retorno == LISTA_CHEIA)
                                printf("Lista de professores cheia\n");
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Matrícula inválida\n");
                            else if (retorno == MATRICULA_EXISTENTE)
                                printf("Matrícula já existente\n");
                            else if (retorno == CPF_EXISTENTE)
                                printf("CPF já existente\n");
                            else if (retorno == SEXO_INVALIDO)
                                printf("Sexo inválido\n");
                            else {
                                printf("Professor cadastrado com sucesso\n");
                                qtdProfessor++;
                            }
                            break;
                        }
                        case 2: {
                            listarProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 3: {
                            printf("Atualizar professor\n");
                            int sairAtualizarProfessor = FALSE;
                            int opcaoAtualizarProfessor;
                            
                            while (sairAtualizarProfessor == FALSE){
                                opcaoAtualizarProfessor = menuAtualizarProfessor();
                                
                                switch (opcaoAtualizarProfessor){
                                    case 0:{
                                        sairAtualizarProfessor = TRUE;
                                        break;
                                    }
                                    case 1:{
                                        int retorno = atualizarMatriculaProfessor(listaProfessor, qtdProfessor);
                                        if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                            printf("Matrícula de professor atualizada com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 2:{
                                        int retorno = atualizarNomeProfessor(listaProfessor, qtdProfessor);
                                        if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                            printf("Nome de professor atualizado com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 3:{
                                        int retorno = atualizarSexoProfessor(listaProfessor, qtdProfessor);
                                        if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                            printf("Sexo de professor atualizado com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 4:{
                                        int retorno = atualizarCpfProfessor(listaProfessor, qtdProfessor);
                                        if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                            printf("CPF do professor atualizado com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                    case 5:{
                                        int retorno = atualizarDataNascProfessor(listaProfessor, qtdProfessor);
                                        if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                            printf("Data de nascimento do professor atualizada com sucesso\n");
                                        else if (retorno == MATRICULA_INEXISTENTE)
                                            printf("Matrícula inexistente\n");
                                        else if (retorno == MATRICULA_INVALIDA)
                                            printf("Matrícula inválida\n");
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4: {
                            int retorno = excluirProfessor(listaProfessor, qtdProfessor);
                            if (retorno == EXCLUSAO_PROFESSOR_SUCESSO) {
                                printf("Professor excluído com sucesso\n");
                                qtdProfessor--;
                            } else if (retorno == MATRICULA_INEXISTENTE)
                                printf("Matrícula inexistente\n");
                            else if (retorno == MATRICULA_INVALIDA)
                                printf("Matrícula inválida\n");
                            break;
                        }
                    }
                }
                break;
            } 
            case 3: {
                getchar();
                printf("--------------Módulo Disciplina--------------\n");
                int sairDisciplina = FALSE;
                int opcaoDisciplina;
    
                while (sairDisciplina == FALSE) {
                    opcaoDisciplina = menuDisciplina();
    
                    switch (opcaoDisciplina) {
                        case 0: {
                            sairDisciplina = TRUE;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
                            if (retorno == LISTA_CHEIA)
                                printf("Lista de disciplinas cheia\n");
                            else if (retorno == DISCIPLINA_EXISTENTE)
                                printf("Código já existente\n");
                            else {
                                printf("Disciplina cadastrada com sucesso\n");
                                qtdDisciplina++;
                            }
                            break;
                        }
                        case 2: {
                            listarDisciplina(listaDisciplina, qtdDisciplina);
                            break;
                        }
                        case 3: {
                            printf("Atualizar disciplina\n");
                            int sairAtualizarDisciplina = FALSE;
                            int opcaoAtualizarDisciplina;

                            while (sairAtualizarDisciplina == FALSE){
                                opcaoAtualizarDisciplina = menuAtualizarDisciplina();
                                
                                switch (opcaoAtualizarDisciplina){
                                    case 0:{
                                        sairAtualizarDisciplina = TRUE;
                                        break;
                                    }
                                    case 1:{
                                        int retorno = atualizarCodigoDisciplina(listaDisciplina, qtdDisciplina);
                                        if (retorno == ATUALIZACAO_DISCIPLINA_SUCESSO)
                                            printf("Código da disciplina atualizado com sucesso\n");
                                        else if (retorno == DISCIPLINA_INEXISTENTE)
                                            printf("Código inexistente\n");
                                        break;
                                    }
                                    case 2:{
                                        int retorno = atualizarNomeDisciplina(listaDisciplina, qtdDisciplina);
                                        if (retorno == ATUALIZACAO_DISCIPLINA_SUCESSO)
                                            printf("Nome da disciplina atualizada com sucesso\n");
                                        else if (retorno == DISCIPLINA_INEXISTENTE)
                                            printf("Código inexistente\n");
                                    }
                                    case 3:{
                                        int retorno = atualizarSemestreDisciplina(listaDisciplina, qtdDisciplina);
                                        if (retorno == ATUALIZACAO_DISCIPLINA_SUCESSO)
                                            printf("Semestre da disciplina atualizado com sucesso\n");
                                        else if (retorno == DISCIPLINA_INEXISTENTE)
                                            printf("Disciplina inexistente\n");
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4: {
                            int retorno = excluirDisciplina(listaDisciplina, qtdDisciplina);
                            if (retorno == EXCLUSAO_DISCIPLINA_SUCESSO) {
                                printf("Disciplina excluída com sucesso\n");
                                qtdDisciplina--;
                            } else if (retorno == DISCIPLINA_INEXISTENTE)
                                printf("Código inexistente\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 4: {
                int retorno = listarAniversariante(listaAluno, listaProfessor, qtdAluno, qtdProfessor);
                if (retorno == MATRICULA_INEXISTENTE)
                    printf("Não existem mátriculas vinculadas a professores ou alunos\n");
                else if(retorno == DATA_INVALIDA)
                    printf("Insira um mês válido (em número)\n");
                else if(retorno == ERRO)
                    printf("Não existem aniversários para o mês solicitado\n");
                else
                    printf("Listagem concluída\n");
                break;
            }
            default: {
                printf("Opção inválida\n");
                break;
            }
        }
    }

    return 0;
}

int menuGeral(){
    int opcao;
    printf("--------------PROJETO ESCOLA--------------\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Aniversarientes do mês\n");

    scanf("%d", &opcao);
    return opcao;
}

int listarAniversariante(Aluno listaAluno[], Professor listaProfessor[], int qtdAluno, int qtdProfessor) {
    if(qtdAluno == 0 && qtdProfessor == 0) {
        return MATRICULA_INEXISTENTE;
    }
    
    printf("Insira o mês (em número) para buscar aniversariantes\n");
    int mes;
    scanf("%d", &mes);
    
    if(mes < 1 || mes > 12) {
        return DATA_INVALIDA;
    }

    int qtdAniversariante = 0;

    if(qtdAluno > 0) {
        printf("\n--------------ALUNOS ANIVERSARIANTES DO MÊS %d--------------\n", mes);
        for(int i = 0; i < qtdAluno; i++) {
            if(listaAluno[i].ativo == TRUE && listaAluno[i].data.mes == mes) {
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                qtdAniversariante++;
            }
        }
    }

    if(qtdProfessor > 0) {
        printf("\n--------------PROFESSORES ANIVERSARIENTES DO MÊS %d--------------\n", mes);
        for(int i = 0; i < qtdProfessor; i++) {
            if(listaProfessor[i].ativo == TRUE && listaProfessor[i].data.mes == mes) {
                printf("Nome: %s\n", listaProfessor[i].nome);
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                qtdAniversariante++;
            }
        }
    }

    if(qtdAniversariante == 0) {
        return ERRO;
    }

    return SUCESSO;
}
