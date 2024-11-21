// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "pedrosantos20241160040.h"  // Substitua pelo seu arquivo de header renomeado

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) {  // função utilizada para testes
    int i, fat = 1;

    for (i = x; i > 1; i--)
        fat = fat * i;

    return fat;
}

int teste(int a) {
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

// parte os dados nas strings enviadas
void splitData(char data[], char sDia[], char sMes[], char sAno[]) {
    int i = 0;
    const int sDia_size = 2;
    const int sMes_size = 2;
    const int sAno_size = 4;
    ////char sDia[sDia_size + 1];
    ////char sMes[sMes_size + 1];
    ////char sAno[sAno_size + 1];
    // escreve NULL em todos os char das strings
    for (int d = 0; d < sDia_size + 1; d++) {
        sDia[d] = '\0';
    }
    for (int m = 0; m < sMes_size + 1; m++) {
        sMes[m] = '\0';
    }
    for (int a = 0; a < sAno_size + 1; a++) {
        sAno[a] = '\0';
    }

    // faz a leitura dos caracteres segundo a formatação as strings
    for (int d = 0; (data[i] != '\0') && (data[i] != '/') && (d < sDia_size); d++) {
        sDia[d] = data[i];
        i++;
    }
    i++;
    for (int m = 0; (data[i] != '\0') && (data[i] != '/') && (m < sMes_size); m++) {
        sMes[m] = data[i];
        i++;
    }
    i++;
    for (int a = 0; (data[i] != '\0') && (data[i] != '/') && (a < sAno_size); a++) {
        sAno[a] = data[i];
        i++;
    }
}
void dataToInt(char sDia[], char sMes[], char sAno[], int *iDia, int *iMes, int *iAno) {
    const int sDia_size = 2;
    const int sMes_size = 2;
    const int sAno_size = 4;

    // condição especial de 2 digitos para o ano, para considerar ele como sendo de 24 = 2024, 25 = 1925
    // mas para ser sincero eu acho que isso nem era necessario e que todos os resultados seriam os mesmos de qualquer modo
    if (sAno[2] == '\0') {
        if ((sAno[0] > '2') && (sAno[1] > '4')) {
            sAno[2] = sAno[0];
            sAno[3] = sAno[1];
            sAno[0] = '1';
            sAno[1] = '9';
        } else {
            sAno[2] = sAno[0];
            sAno[3] = sAno[1];
            sAno[0] = '2';
            sAno[1] = '0';
        }
    }

    // transforma os characteres em numero para fazer o resto das operações de verificação
    int pot = 0;
    for (int d = sDia_size - 1; d >= 0; d--) {
        if (sDia[d] == '\0') {
            continue;
        }
        *iDia = *iDia + (sDia[d] - 48) * ((int)pow(10, pot));
        pot++;
    }
    pot = 0;
    for (int m = sMes_size - 1; m >= 0; m--) {
        if (sMes[m] == '\0') {
            continue;
        }
        *iMes = *iMes + (sMes[m] - 48) * ((int)pow(10, pot));
        pot++;
    }
    pot = 0;
    for (int a = sAno_size - 1; a >= 0; a--) {
        if (sAno[a] == '\0') {
            continue;
        }
        *iAno = *iAno + (sAno[a] - 48) * ((int)pow(10, pot));
        pot++;
    }
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {
    int datavalida = 1;
    int datainvalida = 0;

    const int sDia_size = 2;
    const int sMes_size = 2;
    const int sAno_size = 4;
    char sDia[sDia_size + 1];
    char sMes[sMes_size + 1];
    char sAno[sAno_size + 1];
    int iDia = 0;
    int iMes = 0;
    int iAno = 0;

    // quebrar a string data em strings sDia, sMes, sAno
    splitData(data, sDia, sMes, sAno);

    //// for (int g = 0; g < 3; g++) {
    ////     printf(">");
    ////     printf("|%d=>%c|", sDia[g], sDia[g]);
    ////     printf("<\n");
    //// }
    //// printf("data =|%s|\n", data);
    //// printf("sDia  =|%s|\n", sDia);
    //// printf("sMes  =|%s|\n", sMes);
    //// printf("sAno  =|%s|\n", sAno);

    // verifica se um dos parametros esta vazio
    if ((sDia[0] == '\0') || (sMes[0] == '\0') || (sMes[0] == '\0')) {
        // printf("\nDEBUG: data invalida. primeiro char de alguma das variaveis e nulo, parametro vazio\n");
        return datainvalida;
    }

    // verifica se o ano tem 3 digitos e retorna como invalido pq eu acredito que os dois unicos formatos seriam aa ou aaaa? ja que so esses foram explicitamente determinados
    // e anos menores que a data de criacao do calendario gregoriano sao normalmente expressas pelo calendario juliano, mas isso depende demais entao eu considero esses quesitos fora do escopo da questao
    if ((sAno[3] == '\0') && (sAno[2] != '\0')) {
        // printf("\nDEBUG: data invalida. sAno. ano tem 3 digitos, apenas aceitavel 2 ou 4 digitos\n");
        return datainvalida;
    }

    // verifica se todos os caracteres sao numero
    for (int d = 0; (sDia[d] != '\0') && d < sDia_size; d++) {
        if (sDia[d] < '0' || sDia[d] > '9') {
            // printf("\nDEBUG: data invalida. sDia. algum dos char nao representa um digito\n");
            return datainvalida;
        }
    }
    for (int m = 0; (sMes[m] != '\0') && m < sMes_size; m++) {
        if (sMes[m] < '0' || sMes[m] > '9') {
            // printf("\nDEBUG: data invalida. sMes. algum dos char nao representa um digito\n");
            return datainvalida;
        }
    }
    for (int a = 0; (sAno[a] != '\0') && a < sAno_size; a++) {
        if (sAno[a] < '0' || sAno[a] > '9') {
            // printf("\nDEBUG: data invalida. sAno. algum dos char nao representa um digito\n");
            return datainvalida;
        }
    }

    dataToInt(sDia, sMes, sAno, &iDia, &iMes, &iAno);

    //// printf("iDia  =|%d|\n", iDia);
    //// printf("iMes  =|%d|\n", iMes);
    //// printf("iAno  =|%d|\n", iAno);
    //// printf("\n");

    // verifica se o mes existe no ano
    if (iMes < 1 || iMes > 12) {
        // printf("\nDEBUG: data invalida. iMes. valor maior ou menor que a quantidade possivel de meses\n");
        return datainvalida;
    }

    int max_dias = 0;
    // Meses com 30 dias
    if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) {
        max_dias = 30;
    }

    // Meses com 31 dias
    if (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes == 10 || iMes == 12) {
        max_dias = 31;
    }

    // Fevereiro
    if (iMes == 2) {
        if ((iAno % 4 == 0 && iAno % 100 != 0) || (iAno % 400 == 0)) {
            max_dias = 29;
        } else {
            max_dias = 28;
        }
    }

    // verifica se o dia existe no mes
    if (iDia < 1 || iDia > max_dias) {
        // printf("\nDEBUG: data invalida. iDia. valor maior ou menor que a quantidade possivel de dias\n");
        return datainvalida;
    }

    // se chegou ate aqui sem causar nenhum return de invalido entao ela é valida
    return datavalida;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    // calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    const int sDia_size = 2;
    const int sMes_size = 2;
    const int sAno_size = 4;
    char sDiaI[sDia_size + 1];
    char sMesI[sMes_size + 1];
    char sAnoI[sAno_size + 1];
    char sDiaF[sDia_size + 1];
    char sMesF[sMes_size + 1];
    char sAnoF[sAno_size + 1];
    int iDiaI = 0;
    int iMesI = 0;
    int iAnoI = 0;
    int iDiaF = 0;
    int iMesF = 0;
    int iAnoF = 0;

    splitData(datainicial, sDiaI, sMesI, sAnoI);
    splitData(datafinal, sDiaF, sMesF, sAnoF);

    if (q1(datainicial) == 0) {
        // printf("\nDEBUG: data inicial invalida.\n");
        dma.retorno = 2;
        return dma;
    } else if (q1(datafinal) == 0) {
        // printf("\nDEBUG: data final invalida.\n");
        dma.retorno = 3;
        return dma;
    } else {
        dataToInt(sDiaI, sMesI, sAnoI, &iDiaI, &iMesI, &iAnoI);
        dataToInt(sDiaF, sMesF, sAnoF, &iDiaF, &iMesF, &iAnoF);

        // verifique se a data final não é menor que a data inicial

        int bigDataI = (iAnoI * 10000) + (iMesI * 100) + iDiaI;
        int bigDataF = (iAnoF * 10000) + (iMesF * 100) + iDiaF;

        if (bigDataI > bigDataF) {
            // printf("\nDEBUG: data inicial maior que final.\n");
            dma.retorno = 4;
            return dma;
        }

        // calcule a distancia entre as datas
        int totalDiasI = 0;

        int anoDiff = 0;
        for (int i = iAnoF; i > iAnoI; i--) {
            if ((iAnoI % 4 == 0 && iAnoI % 100 != 0) || (iAnoI % 400 == 0)) {
                ////max_dias = 29;
                totalDiasI = totalDiasI + 366;
            } else {
                ////max_dias = 28;
                totalDiasI = totalDiasI + 365;
            }
            anoDiff++;
        }

        int mesDiff = 0;
        int i = iMesF;
        // meses finais maiores que iniciais
        for (; i > iMesI; i--) {
            int max_dias = 0;
            // Meses com 30 dias
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                max_dias = 30;
            }

            // Meses com 31 dias
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                max_dias = 31;
            }

            // Fevereiro
            if (i == 2) {
                if ((iAnoI % 4 == 0 && iAnoI % 100 != 0) || (iAnoI % 400 == 0)) {
                    max_dias = 29;
                } else {
                    max_dias = 28;
                }
            }

            totalDiasI = totalDiasI + max_dias;
            mesDiff++;
        }

        // meses iniciais maiores que finais
        for (; i < iMesI; i++) {
            int max_dias = 0;
            // Meses com 30 dias
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                max_dias = 30;
            }

            // Meses com 31 dias
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                max_dias = 31;
            }

            // Fevereiro
            if (i == 2) {
                if ((iAnoI % 4 == 0 && iAnoI % 100 != 0) || (iAnoI % 400 == 0)) {
                    max_dias = 29;
                } else {
                    max_dias = 28;
                }
            }

            totalDiasI = totalDiasI - max_dias;
            mesDiff--;
            if (mesDiff < 0) {
                anoDiff--;
                mesDiff = 11;
            }
        }

        // *dias finais maiores que iniciais
        // dia = 24 , dia = 22
        // mes -1
        // mes = 29 , mes = 31
        // 24/29 , 22/31
        // 29-24 = 5, 5+22 = 27
        // diff pode ser no maximo os dias totais do mes inicial,
        //
        int diaDiff = 0;
        i = iDiaF;
        for (; i > iDiaI; i--) {
            totalDiasI = totalDiasI + 1;
            diaDiff++;
            // printf("dia final maior que inicial↓\n");
        }
        // *dias iniciais maiores que finais
        if (i < iDiaI) {
            // totalDiasI = totalDiasI - 1;
            // diaDiff--;
            // printf("dia inicial maior que final↓\n");
            // if (diaDiff < 0) {
            int max_dias = 0;
            int mes_atual = iMesI;
            int max_diasF = 0;
            int mes_atualF = iMesF;

            // DEFIBE O MES ATUAL INICIAL DIAS
            // Meses com 30 dias
            if (mes_atual == 4 || mes_atual == 6 || mes_atual == 9 || mes_atual == 11) {
                max_dias = 30;
            }  // Meses com 31 dias
            if (mes_atual == 1 || mes_atual == 3 || mes_atual == 5 || mes_atual == 7 || mes_atual == 8 || mes_atual == 10 || mes_atual == 12) {
                max_dias = 31;
            }  // Fevereiro
            if (mes_atual == 2) {
                if (((iAnoI + anoDiff) % 4 == 0 && (iAnoI + anoDiff) % 100 != 0) || ((iAnoI + anoDiff) % 400 == 0)) {
                    max_dias = 29;
                } else {
                    max_dias = 28;
                }
            }
            ///////////////////////////*
            // DEFIBE O MES ATUAL INICIAL DIAS
            // Meses com 30 dias
            if (mes_atualF == 4 || mes_atualF == 6 || mes_atualF == 9 || mes_atualF == 11) {
                max_diasF = 30;
            }  // Meses com 31 dias
            if (mes_atualF == 1 || mes_atualF == 3 || mes_atualF == 5 || mes_atualF == 7 || mes_atualF == 8 || mes_atualF == 10 || mes_atualF == 12) {
                max_diasF = 31;
            }  // Fevereiro
            if (mes_atualF == 2) {
                if (((iAnoI + anoDiff) % 4 == 0 && (iAnoI + anoDiff) % 100 != 0) || ((iAnoI + anoDiff) % 400 == 0)) {
                    max_diasF = 29;
                } else {
                    max_diasF = 28;
                }
            }

            // printf("mesatual=%d\n",mes_atual);
            mesDiff--;
            diaDiff = max_dias - (iDiaI - iDiaF);
            //  }
        }

        dma.qtdAnos = anoDiff;
        dma.qtdMeses = mesDiff;
        dma.qtdDias = diaDiff;
        // se tudo der certo
        // printf("\ndia=%d\n",dma.qtdDias);
        // printf("mes=%d\n",dma.qtdMeses);
        // printf("ano=%d\n",dma.qtdAnos);
        // printf("\nDEBUG: bigI=%d, bigF=%d", bigDataI, bigDataF);
        // printf("\nDEBUG: operacao sucesso. d=%d,m=%d,a=%d\n", dma.qtdDias, dma.qtdMeses, dma.qtdAnos);
        dma.retorno = 1;
        return dma;
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isCaseSensitive == 1) {
            if (texto[i] == c) {
                qtdOcorrencias++;
            }
        } else {
            // considering c as lowercase and cAlt to be uppercase
            // in the case insensitive character range
            char cAlt = '\0';
            if ((c >= 'a') && (c <= 'z')) {
                cAlt = c - 32;
            }
            if ((c >= 'A') && (c <= 'Z')) {
                cAlt = c + 32;
            }

            if ((texto[i] == c) || (texto[i] == cAlt)) {
                qtdOcorrencias++;
            }
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;

    // encontra a largura da string de busca
    int strBuscaLen = 0;
    int qtdPosicoes = 0;
    for (int l = 0; strBusca[l] != '\0'; l++) {
        strBuscaLen++;
    }

    for (int i = 0; strTexto[i] != '\0'; i++) {
        int palavraEncontrada = 1;
        int posicaoComeco = i + 1;
        int posicaoFinal = i + strBuscaLen;
        int t = i;
        for (int s = 0; strBusca[s] != '\0'; s++) {
            if (strTexto[t] != strBusca[s]) {
                palavraEncontrada = 0;
            }
            t++;
        }
        if (palavraEncontrada == 1) {
            qtdOcorrencias++;
            i++;
            // add if > 30
            posicoes[qtdPosicoes] = posicaoComeco;
            posicoes[qtdPosicoes + 1] = posicaoFinal;
            // printf("posicao1=%d\n",posicoes[qtdPosicoes]);
            // printf("posicao2=%d\n",posicoes[qtdPosicoes+1]);
            qtdPosicoes = qtdPosicoes + 2;
        }
    }

    // printf("ocorrencias=%d\n",qtdOcorrencias);
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    int result = 0;
    int numLen = ((int)log10(num) + 1);
    // printf("len=%d\n",numLen);

    for (int i = 0; i < numLen; i++) {
        int digito = num / (int)pow(10, numLen - (i + 1)) % 10;
        result = result + (digito * (int)pow(10, i));
    }

    // printf("num=%d\n",result);
    return result;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;
    int numerobaseLen = ((int)log10(numerobase) + 1);
    int numerobuscaLen = ((int)log10(numerobusca) + 1);
    //printf("base=%d, busca=%d\n", numerobase, numerobusca);
    //printf("baselen=%d, buscalen=%d\n", numerobaseLen, numerobuscaLen);

    for (int i = 0; i < numerobaseLen; i++) {
        int numeroEncontrado = 1;
        int n = i;
        for (int j = 0; j < numerobuscaLen; j++) {
            int tmp = (int)pow(10, numerobaseLen - (n + 1));    //% 10;
            int tmp2 = (int)pow(10, numerobuscaLen - (j + 1));  //% 10;
            //printf("tmp=%d, tmp=%d\n", tmp, tmp2);
            if (tmp < 1) {
                // printf("operacao valida = %d",tmp);
                tmp = 1;
            }
            if (tmp2 < 1) {
                // printf("operacao valida = %d",tmp);
                tmp2 = 1;
            }
            int digitobase = numerobase / tmp % 10;
            int digitobusca = numerobusca / tmp2 % 10;
            //printf("dgtbase(%d)[%d] = %d / %d \% 10, dgtbusca(%d)[%d] = %d / %d \% 10\n", digitobase, i, numerobase, tmp, digitobusca, j, numerobusca, tmp2);
            if (digitobase != digitobusca) {
                numeroEncontrado = 0;
                n++;
                break;
            }
            if (numerobaseLen-1 == i && j != numerobuscaLen - 1) {
                numeroEncontrado = 0;
                n++;
                break;
            }
            n++;
            // printf("i=%d\n",i);
        }
        if (numeroEncontrado == 1) {
            qtdOcorrencias++;
            i = i + numerobuscaLen - 1;
        }
    }

    // printf("qtd=%d\n",qtdOcorrencias);
    return qtdOcorrencias;
}

DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;

    for (i = 0; data[i] != '/'; i++) {
        sDia[i] = data[i];
    }
    if (i == 1 || i == 2) {  // testa se tem 1 ou dois digitos
        sDia[i] = '\0';      // coloca o barra zero no final
    } else {
        dq.valido = 0;
        return dq;
    }

    int j = i + 1;  // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++) {
        sMes[i] = data[j];
        i++;
    }

    if (i == 1 || i == 2) {  // testa se tem 1 ou dois digitos
        sMes[i] = '\0';      // coloca o barra zero no final
    } else {
        dq.valido = 0;
        return dq;
    }

    j = j + 1;  // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '\0'; j++) {
        sAno[i] = data[j];
        i++;
    }

    if (i == 2 || i == 4) {  // testa se tem 2 ou 4 digitos
        sAno[i] = '\0';      // coloca o barra zero no final
    } else {
        dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

    dq.valido = 1;

    return dq;
}
