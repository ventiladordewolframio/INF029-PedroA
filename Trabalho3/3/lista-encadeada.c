#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    int vazio;
    struct reg *next;
    struct reg *last;
} No;

void printLista(No *head) {
    No *temp = head;

    bool firsttime = true;
    while (temp != NULL) {
        if (firsttime) {
            if (temp->vazio) {
                printf("NULL <= (EMPTY)");
            } else {
                printf("NULL <= (%d)", temp->conteudo);
            }
            firsttime = false;
        } else {
            if (temp->vazio) {
                printf("<=> (EMPTY)");
            } else {
                printf(" <=> (%d)", temp->conteudo);
            }
        }
        temp = temp->next;
    }
    printf(" => NULL");
}

void insertLista(No *head) {
    No *temp = head;

    if (temp == NULL) {
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    No *newNo = malloc(sizeof(No));

    temp->next = newNo;

    newNo->conteudo = 0;
    newNo->vazio = 1;
    newNo->last = temp;
    newNo->next = NULL;
}

void writeElementLista(No *head, int position, int newcontend) {
    No *temp = head;

    if (temp == NULL) {
        return;
    }

    for(int i=0;i<position;i++) {
        if(temp == NULL){
            return;
        }
        temp = temp->next;
    }

    temp->conteudo = newcontend;
    temp->vazio = 0;

}

void clearElementLista(No *head, int position) {
    No *temp = head;

    if (temp == NULL) {
        return;
    }


    for(int i=0;i<position;i++) {
        if(temp == NULL){
            return;
        }
        temp = temp->next;
    }

    temp->conteudo = 0;
    temp->vazio = 1;

}

int main() {
    No *head = malloc(sizeof(No));

    head->conteudo = 0;
    head->vazio = 1;
    head->last = NULL;
    head->next = NULL;

    insertLista(head);
    insertLista(head);
    insertLista(head);
    insertLista(head);

    writeElementLista(head, 2, 176);
    writeElementLista(head, 3, 444);
    clearElementLista(head, 2);

    printLista(head);
}