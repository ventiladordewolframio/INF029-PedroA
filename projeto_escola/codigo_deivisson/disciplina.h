#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "professor.h"
#include "aluno.h"

#define TAM_DISCIPLINA 10    
#define MAX_NOME_DISCIPLINA 100
#define MAX_CODIGO 10

// Códigos de retorno para as funções relacionadas à disciplina
#define CAD_DISCIPLINA_SUCESSO 1
#define LISTA_DISCIPLINA_CHEIA -1
#define DISCIPLINA_EXISTENTE -2
#define DISCIPLINA_INEXISTENTE -3
#define ATUALIZACAO_DISCIPLINA_SUCESSO -4
#define EXCLUSAO_DISCIPLINA_SUCESSO -5
#define DISCIPLINA_INVALIDA -6

typedef struct {
    char codigo[MAX_CODIGO]; 
    char nome[MAX_NOME_DISCIPLINA]; 
    Professor listaProfessor[TAM_PROFESSOR];
    int numProfessores;
    Aluno listaAluno[TAM_ALUNO];
    int numAluno;
    int semestre;
    int ativo;
} Disciplina;

// Protótipos das funções
int menuDisciplina();
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int atualizarCodigoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int atualizarNomeDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int atualizarSemestreDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int adicionarProfessorDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor);
int adicionarAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno);

#endif
