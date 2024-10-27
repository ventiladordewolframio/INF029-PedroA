#include <stdbool.h>

#ifndef INTERFACE_MAIN_H
#define INTERFACE_MAIN_H

#define MAX_num_alunos 5
#define MAX_num_professores 5
#define MAX_num_disciplinas 5

#define MAX_char_nome 256
#define MAX_char_cpf 9

struct data {
    unsigned long long int timestamp;  //! desnecessário
    int ano;
    int mes;
    int dia;
};

struct aluno {
    int matricula;
    char nome[MAX_char_nome];
    char sexo;
    struct data nascimento;
    char cpf[MAX_char_cpf];
    bool ativo;
    bool disciplinas[MAX_num_disciplinas];
};

struct professor {
    int matricula;
    char nome[MAX_char_nome];
    char sexo;
    struct data nascimento;
    char cpf[MAX_char_cpf];
    bool ativo;
    bool disciplinas[MAX_num_disciplinas];
};

struct disciplina {
    char nome[MAX_char_nome];
    int id;
    int semestre;  //! existe essa variavel aqui mas como a gente usa ela? serve para oq o semestre?
    bool ativo;
    int vaga_preenchida;  // criei para contar número de alunos em uma disciplina
};

extern struct aluno alunos[MAX_num_alunos];
extern struct professor professores[MAX_num_professores];
extern struct disciplina disciplinas[MAX_num_disciplinas];

extern int qtd_aluno;
extern int qtd_professor;
extern int qtd_disciplina;

void clear();           // temporario solucao, depois criar arquivo de funções de utilidade
void printAlunosObj();  // o mesmo do de cima
void printProfessoresObj();
void printDisciplinasObj();

#endif
