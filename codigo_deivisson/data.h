#ifndef DATA_H
#define DATA_H

#define TRUE 1
#define FALSE 0
#define DATA_VALIDA -20
#define DATA_INVALIDA -21
#define BISSEXTO_TRUE -22
#define BISSEXTO_FALSE -23

// Estrutura de data de nascimento
typedef struct {
    int dia;
    int mes;
    int ano;
} DataNascimento;

//Protótipos das funções
int verificarBissexto(int ano);
int validarData(int dia, int mes, int ano);
DataNascimento lerDataNascimento();

#endif
