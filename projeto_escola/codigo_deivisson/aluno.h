#ifndef ALUNO_H
#define ALUNO_H

#include "data.h"

#define TAM_ALUNO 3
#define MAX_NOME 100
#define MAX_CPF 13
#define MAX_SEXO 2
#define TRUE 1
#define FALSE 0

// Códigos de retorno para as funções
#define CAD_ALUNO_SUCESSO 1           //! dentro de cada funcao de adiquirir os valores eles ja
#define LISTA_CHEIA -1                //! são testados e qualquer erro ja é printado de lá mesmo
#define MATRICULA_INVALIDA -2         //! não precisando assim de retornar um valor, alem disso
#define MATRICULA_EXISTENTE -3        //! nelas mesmas já reiniciam até um valor aceitavel ser inserido
#define ATUALIZACAO_ALUNO_SUCESSO -4  //!^^
#define MATRICULA_INEXISTENTE -5      //!^^
#define EXCLUSAO_ALUNO_SUCESSO -6     //!^^
#define CPF_EXISTENTE -8              //!^^
#define SEXO_INVALIDO -9              //!^^ah por causa da formatação automatica algumas linhas com espaços extras vao conatar como modificadas.

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    char sexo;
    DataNascimento data;
    int ativo;
} Aluno;

// Protótipos das funções
int menuAluno();
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarMatriculaAluno(Aluno listaAluno[], int qtdAluno);
int atualizarNomeAluno(Aluno listaAluno[], int qtdAluno);
int atualizarSexoAluno(Aluno listaAluno[], int qtdAluno);
int atualizarCpfAluno(Aluno listaAluno[], int qtdAluno);
int atualizarDataNascAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);

#endif