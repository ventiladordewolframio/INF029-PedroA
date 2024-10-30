#ifndef INTERFACE_RELATORIO_H
#define INTERFACE_RELATORIO_H

#include "interface_main.h"

int interfaceRel();
void listarAlunos();
void listarProfessores();
void listarDisciplinas();
void listarAlunoPorSexo(struct aluno alunos[], int qtd_aluno);
void listarProfessorPorSexo(struct professor professores[], int qtd_professor);
int listarAniversariante(struct aluno alunos[], struct professor professores[], int qtd_aluno, int qtd_professor);
void listarAlunoComMenosDeTresDisciplinas(struct aluno alunos[], int qtd_aluno);
void listarDisciplinasQueExtrapolam40Vagas(struct disciplina disciplinas[], int qtd_disciplina);

#endif
