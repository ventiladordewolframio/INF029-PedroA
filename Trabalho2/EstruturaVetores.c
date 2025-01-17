#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

No *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
    int retorno = 0;

    // se posição é um valor válido {entre 1 e 10}
    if (!(posicao > 0 && posicao < 11)) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    // a posicao pode já existir estrutura auxiliar
    if (!(vetorPrincipal[posicao] == 0)) {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    // o tamanho nao pode ser menor que 1
    if (tamanho < 1) {
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }

    // deu tudo certo, crie
    No *lista_ptr_No[tamanho];
    for (int l = 0; l < tamanho; l++) {
        lista_ptr_No[l] = NULL;
    }
    No *ultimo_No = NULL;
    for (int i = 0; i < tamanho; i++) {
        No *ptr_No = malloc(sizeof(No));
        // indentifica falha de alocar memoria no sistema
        if (ptr_No == NULL) {
            retorno = SEM_ESPACO_DE_MEMORIA;
            break;
        }
        ptr_No->prox = NULL;
        ptr_No->conteudo = 0;
        ptr_No->excluido = 0;
        ptr_No->vazio = 1;
        if (ultimo_No != NULL) {
            ultimo_No->prox = ptr_No;
        }
        if (ultimo_No == NULL) {
            vetorPrincipal[posicao] = ptr_No;
        }
        ultimo_No = ptr_No;
        lista_ptr_No[i] = ptr_No;
    }
    // o tamanho ser muito grande
    if (retorno == SEM_ESPACO_DE_MEMORIA) {
        for (int l = 0; l < tamanho; l++) {
            free(lista_ptr_No[l]);
        }
        return retorno;
    }

    retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    // se posição é um valor válido {entre 1 e 10}
    if (!(posicao > 0 && posicao < 11)) {
        posicao_invalida = 1;
    }
    if (posicao_invalida) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    } else {
        // testar se existe a estrutura auxiliar
        if (!(vetorPrincipal[posicao] == 0)) {
            existeEstruturaAuxiliar = 1;
        }
        if (existeEstruturaAuxiliar) {
            No *ptr_No = vetorPrincipal[posicao];

            while (ptr_No != NULL) {
                ////printf("%d\n", ptr_No);
                if (ptr_No->vazio) {
                    ptr_No->conteudo = valor;
                    ptr_No->vazio = 0;
                    return SUCESSO;
                }
                ptr_No = ptr_No->prox;
            }
            if (!temEspaco) {
                return SEM_ESPACO;
            }
        } else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (!(posicao > 0 && posicao < 11)) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao] == 0) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorPrincipal[posicao]->vazio) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    No *ptr_No = vetorPrincipal[posicao];
    while (ptr_No != NULL) {
        if (ptr_No->prox == NULL) {
            ptr_No->conteudo = 0;
            ptr_No->vazio = 1;
            return SUCESSO;
        }
        if (ptr_No->prox->vazio) {
            ptr_No->conteudo = 0;
            ptr_No->vazio = 1;
            return SUCESSO;
        }
        ptr_No = ptr_No->prox;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    int numeroExiste = 0;
    if (!(posicao > 0 && posicao < 11)) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao] == 0) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorPrincipal[posicao]->vazio) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    No *ptr_No = vetorPrincipal[posicao];
    do {
        if (ptr_No->conteudo == valor) {
            ptr_No->conteudo = 0;
            ptr_No->vazio = 1;
            numeroExiste = 1;
            break;
        }
        ptr_No = ptr_No->prox;
    } while (ptr_No->prox != NULL);
    if (!numeroExiste) {
        return NUMERO_INEXISTENTE;
    }
    ptr_No = vetorPrincipal[posicao];
    do {
        if ((ptr_No->vazio) && !(ptr_No->prox->vazio)) {
            ptr_No->conteudo = ptr_No->prox->conteudo;
            ptr_No->prox->conteudo = 0;
            ptr_No->vazio = 0;
            ptr_No->prox->vazio = 1;
        }
        ptr_No = ptr_No->prox;
    } while (ptr_No->prox != NULL);
    int retorno = SUCESSO;
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
    int retorno = 0;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
    } else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = 0;
    if (!(posicao > 0 && posicao < 11)) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao] == 0) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    No *ptr_No = vetorPrincipal[posicao];
    int i = 0;
    do {
        vetorAux[i] = ptr_No->conteudo;
        i++;
        // printf("|%d",vetorAux[0]);
        // printf("|%d|\n",vetorAux[1]);
        if (ptr_No->prox == NULL) {
            return SUCESSO;
        }
        if (ptr_No->prox->vazio) {
            // printf("prox vazio\n");
            return SUCESSO;
        }
        ptr_No = ptr_No->prox;
    } while (ptr_No->prox != NULL);
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = 0;
    if (!(posicao > 0 && posicao < 11)) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao] == 0) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    No *ptr_No = vetorPrincipal[posicao];
    int i = 0;
    do {
        vetorAux[i] = ptr_No->conteudo;
        i++;
        // printf("|%d",vetorAux[0]);
        // printf("|%d|\n",vetorAux[1]);
        if (ptr_No->prox == NULL) {
            break;
        }
        if (ptr_No->prox->vazio) {
            // printf("prox vazio\n");
            break;
        }
        ptr_No = ptr_No->prox;
    } while (ptr_No->prox != NULL);
    insertionSort(vetorAux, 2);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = 0;
    int todasVazias = 1;

    No *ptr_No = vetorPrincipal[0];
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != 0) {
            ptr_No = vetorPrincipal[i];
        } else {
            continue;
        }
        do {
            if (!(ptr_No->vazio)) {
                // printf("estrutura nao vazia|%d|%d|", i, ptr_No->conteudo);
                todasVazias = 0;
                break;
            }
            ptr_No = ptr_No->prox;
        } while (ptr_No->prox != NULL);
    }
    if (todasVazias) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    int j = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] == 0) {
            continue;
        }
        No *ptr_No = vetorPrincipal[i];
        // printf("new");
        do {
            // printf("%d|", ptr_No->conteudo);
            vetorAux[j] = ptr_No->conteudo;
            j++;
            if (ptr_No->prox == NULL) {
                // printf("cause:null");
                break;
            }
            if (ptr_No->prox->vazio) {
                // printf("cause:empty");
                break;
            }
            ptr_No = ptr_No->prox;
        } while (1);
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = 0;
    int todasVazias = 1;

    No *ptr_No = vetorPrincipal[0];
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != 0) {
            ptr_No = vetorPrincipal[i];
        } else {
            continue;
        }
        do {
            if (!(ptr_No->vazio)) {
                // printf("estrutura nao vazia|%d|%d|", i, ptr_No->conteudo);
                todasVazias = 0;
                break;
            }
            ptr_No = ptr_No->prox;
        } while (ptr_No->prox != NULL);
    }
    if (todasVazias) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    int j = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] == 0) {
            continue;
        }
        No *ptr_No = vetorPrincipal[i];
        // printf("new");
        do {
            // printf("%d|", ptr_No->conteudo);
            vetorAux[j] = ptr_No->conteudo;
            j++;
            if (ptr_No->prox == NULL) {
                // printf("cause:null");
                break;
            }
            if (ptr_No->prox->vazio) {
                // printf("cause:empty");
                break;
            }
            ptr_No = ptr_No->prox;
        } while (1);
    }
    insertionSort(vetorAux, j - 1);
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    int retorno = 0;

    if (!(posicao > 0 && posicao < 11)) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao] == 0) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    int tamanhoAux = getQuantidadeElementosEstruturaAuxiliar(posicao);
    if (!((novoTamanho + tamanhoAux) >= 1)) {
        return NOVO_TAMANHO_INVALIDO;
    }

    // novo tamanho positivo / negativo
    if (novoTamanho > 0) {
        // pega o ultimo ptr no da posicao
        No *ptr_No = vetorPrincipal[posicao];
        int i = 0;
        do {
            if (ptr_No->prox == NULL) {
                break;
            }
            ptr_No = ptr_No->prox;
        } while (1);
        // printf("ptr no = |%d|",ptr_No->conteudo);
        //  emenda os ptr no e cria os novos
        No *lista_ptr_No[novoTamanho];
        for (int l = 0; l < novoTamanho; l++) {
            lista_ptr_No[l] = NULL;
        }
        No *ultimo_No = NULL;
        for (int i = 0; i < novoTamanho; i++) {
            No *novo_ptr_No = malloc(sizeof(No));

            // indentifica falha de alocar memoria no sistema
            if (novo_ptr_No == NULL) {
                retorno = SEM_ESPACO_DE_MEMORIA;
                break;
            }
            novo_ptr_No->prox = NULL;
            novo_ptr_No->conteudo = 0;
            novo_ptr_No->excluido = 0;
            novo_ptr_No->vazio = 1;
            if (i == 0) {
                ptr_No->prox = novo_ptr_No;
            }
            if (ultimo_No != NULL) {
                ultimo_No->prox = novo_ptr_No;
            }
            // if (ultimo_No == NULL) {
            //     vetorPrincipal[posicao] = novo_ptr_No;
            // }
            ultimo_No = novo_ptr_No;
            lista_ptr_No[i] = novo_ptr_No;
        }

        // o tamanho ser muito grande
        if (retorno == SEM_ESPACO_DE_MEMORIA) {
            for (int l = 0; l < novoTamanho; l++) {
                free(lista_ptr_No[l]);
            }
            return retorno;
        }
    } else {
        // pega o ultimo ptr no da posicao
        No *ptr_No = vetorPrincipal[posicao];
        int i = 0;
        int comecoDelete = tamanhoAux + novoTamanho;
        No *ultimo_ptr;
        No *deleteList[novoTamanho - novoTamanho - novoTamanho];
        int d = 0;
        do {
            if (ptr_No->prox == NULL) {
                deleteList[d] = ptr_No;
                // printf("marca da morte = |%d|", ptr_No->conteudo);
                d++;
                break;
            }
            if (i == comecoDelete - 1) {
                ultimo_ptr = ptr_No;
                // printf("akill |%d|", ptr_No->conteudo);
            }
            ////printf("i = |%d|", i);
            if (i >= comecoDelete) {
                deleteList[d] = ptr_No;
                // printf("marca da morte = |%d|", ptr_No->conteudo);
                d++;
            }
            i++;
            ptr_No = ptr_No->prox;
        } while (1);

        ultimo_ptr->prox = NULL;

        for (int l = 0; l < d; l++) {  // printf("terminou");
            free(deleteList[l]);
        }
    }
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    int retorno = 0;
    if (!(posicao > 0 && posicao < 11)) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao] == 0) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    No *ptr_No = vetorPrincipal[posicao];
    int i = 0;
    while (ptr_No != NULL) {
        if (!(ptr_No->vazio)) {
            i++;
        } else {
            break;
        }
        ptr_No = ptr_No->prox;
    }
    if (i == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    return i;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {
    int todasVazias = 1;

    No *ptr_No = vetorPrincipal[0];
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != 0) {
            ptr_No = vetorPrincipal[i];
        } else {
            continue;
        }
        do {
            if (!(ptr_No->vazio)) {
                // printf("estrutura nao vazia|%d|%d|", i, ptr_No->conteudo);
                todasVazias = 0;
                break;
            }
            ptr_No = ptr_No->prox;
        } while (ptr_No->prox != NULL);
    }
    if (todasVazias) {
        return NULL;
    }

    No *head = malloc(sizeof(No));
    No *temp = head;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] == 0) {
            continue;
        }
        No *ptr_No = vetorPrincipal[i];
        do {
            // vetorAux[j] = ptr_No->conteudo;
            No *novo_no = malloc(sizeof(No));
            temp->prox = novo_no;  // temp (head) -> novo no
            temp = temp->prox;     // temp = novo no | // novo no->prox == NULL
            temp->conteudo = ptr_No->conteudo;
            temp->excluido = 0;
            temp->vazio = 0;
            if (ptr_No->prox == NULL) {
                break;
            }
            if (ptr_No->prox->vazio) {
                break;
            }
            ptr_No = ptr_No->prox;
        } while (1);
    }
    // printf("fist no = |%d|", head->prox->conteudo);
    return head;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    No *ptr_No = inicio->prox;
    int j = 0;
    do {
        vetorAux[j] = ptr_No->conteudo;
        j++;
        // printf("c=%d", ptr_No->conteudo);
        if (ptr_No->prox->prox == NULL) {
            break;
        }
        // if (ptr_No->prox->vazio) {
        //     break;
        // }

        ptr_No = ptr_No->prox;
    } while (1);
    // printf("vect=%d|",vetorAux[0]);
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
    // printf("RESULT = |%d|",*inicio);
    No *atual = *inicio;  // Ponteiro para o nó atual
    No *temp;             // Ponteiro auxiliar para armazenar o próximo nó

    // Itera até que o ponteiro atual seja NULL (fim da lista)
    while (atual != NULL) {
        temp = atual;         // Armazena o nó atual
        atual = atual->prox;  // Avança para o próximo nó
        free(temp);           // Libera a memória do nó atual
    }

    // Após liberar todos os nós, ajusta o ponteiro head para NULL
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
}
