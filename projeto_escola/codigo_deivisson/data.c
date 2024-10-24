#include <stdio.h>
#include <string.h>  // Necessário para usar strcmp e strcpy
#include "data.h"

int verificarBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return BISSEXTO_TRUE;
    }else{
      return BISSEXTO_FALSE;
    }
}

int validarData(int dia, int mes, int ano) {
    // Verifica se o mês é válido (entre 1 e 12)
    if (mes < 1 || mes > 12) {
        return DATA_INVALIDA;
    }
  
    // Meses com 31 dias
    int max_dias_mes;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
         max_dias_mes = 31;
    }
    // Meses com 30 dias
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        max_dias_mes = 30;
    }
    //Fevereiro
    else if (mes == 2) {
        int retorno;
        retorno = verificarBissexto(ano);
        if (retorno == BISSEXTO_TRUE) {
            max_dias_mes = 29;
        } else {
            max_dias_mes = 28;
        }
    }
    if(dia >= 1 && dia <= max_dias_mes)
      return DATA_VALIDA;
    else
      return DATA_INVALIDA;
}

// Função para ler e validar a data de nascimento
DataNascimento lerDataNascimento() {
    int dia, mes, ano;
    int dataValida = FALSE;
    int retorno;
    DataNascimento data;

    do {
        printf("Digite a data de nascimento (dd mm aaaa):\n");
        scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

        // Valida a data
        retorno = validarData(data.dia, data.mes, data.ano);
        if (retorno == DATA_VALIDA) {
            dataValida = TRUE;
        } else {
            printf("Data inválida. Tente novamente.\n");
        }
    } while (dataValida == FALSE);

    return data;
}
