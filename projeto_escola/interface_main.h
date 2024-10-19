#ifndef INTERFACE_MAIN_H
#define INTERFACE_MAIN_H

struct data {
    unsigned long long int timestamp;
    int ano;
    int mes;
    int dia;
};

struct aluno {
    int matricula;
    char nome[256];
    char sexo;
    struct data nascimento;
    int cpf;
};

struct professor {
    int matricula;
    char nome[256];
    char sexo;
    struct data nascimento;
    int cpf;
};

struct disciplina {
    char nome[128];
    int id;
    int semestre;
    char professor[128];
};

#define MAX_num_alunos 5
#define MAX_num_professores 5
#define MAX_num_disciplinas 5

#define MAX_char_nome 256

extern struct aluno alunos[MAX_num_alunos];
extern struct professor professores[MAX_num_professores];
extern struct disciplina disciplinas[MAX_num_disciplinas];

extern int qtd_aluno;
extern int qtd_professor;
extern int qtd_disciplina;


void clear();//temporario solucao, depois criar arquivo de funções de utilidade
void printAlunosObj();//o mesmo do de cima

#endif