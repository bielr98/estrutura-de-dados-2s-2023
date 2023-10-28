#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertValue(int value, list *listReference){
    node *newnode = createNode(value);

    if (isEmpty(listReference)){
        listReference->initial = newnode;
    }else{
        node *aux = listReference->initial;

        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = newnode;
    }
}

void printList(list *listReference){
    if (isEmpty(listReference)){
        return;
    }

    node *aux = listReference->initial;

    printf("List : ");
    while (aux != NULL)
    {
        printf("%d  ", aux->value);
        aux = aux->next;
    }
    printf("\n");
    
}

int isEmpty(list *listReference){
    if(listReference->initial == NULL){
        return 1;
    }
    return 0;
}

node *createNode(int value){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

list *createList(){
    list *createdList = (list *)malloc(sizeof(list));
    createdList->initial = NULL;
    return createdList;
}

int lista_verificar_existencia(int value, list *listReference){
    node *aux = listReference->initial;

    if(isEmpty(listReference)){
        return 0;
    }

    while(aux != NULL){
        if(aux->value == value){
            printf("Contém o valor %d\n", value);
            return 1;
        }else{
            aux = aux->next;
        }
    }

    return 0;
}

int lista_verificar_ocorrencias(int value, list *listReference){
    node *aux = listReference->initial;
    int quantityOcurrency = 0;

    if(isEmpty(listReference)){
        return 0;
    }

    while(aux != NULL){
        if(aux->value == value){
            quantityOcurrency++;
        }
        aux = aux->next;
    }
    printf("Quantidade de ocorrencias do valor %d : %d\n", value, quantityOcurrency);
    return quantityOcurrency;
}

void lista_imprimir_inversa(list *listReference){
    int size = listSize(listReference);
    node *aux = listReference->initial;
    int values[10];

    int i = 0;
    while(aux != NULL){
        values[i] = aux->value;
        i++;
        aux = aux->next;
    }

    printf("Ordem reversa : ");
    for(i--; i > -1; i--){
        printf("%d ", values[i]);
    }
    printf("\n");
}

int listSize(list *listReference){
    if(isEmpty(listReference)){
        return 0;
    }

    int size = 0;
    node *aux = listReference->initial;
    while(aux != NULL){
        size ++;
        aux = aux->next;
    }

    return size;
}

void lista_inserir_no_i(int value, int position, list *listReference){
    if(isEmpty(listReference)){
        return;
    }

    if(position > listSize(listReference) - 1 || position < 0){
        return;
    }

    node *newNode = createNode(value);
    if (position == 0){
        newNode->next = listReference->initial;
        listReference->initial = newNode;
    }else{
        node *aux = listReference->initial;
        for(int i = 0; i < position - 1; i++){
            aux = aux->next;
        }

        newNode->next = aux->next;
        aux->next = newNode;
    }
}

void lista_remover_no_i(int position, list *listReference){
    if(isEmpty(listReference)){
        return;
    }

    if(position > listSize(listReference) - 1 || position < 0){
        return;
    }

    node *aux = listReference->initial;

    if (position == 0){
        listReference->initial = aux->next;
        free(aux);
    }else{
        for(int i = 0; i < position - 1; i++){
            aux = aux->next;
        }

        node *nodeToBeRemoved = aux->next;
        aux->next = nodeToBeRemoved->next;
        free(nodeToBeRemoved);
    }
}

void lista_remover_no(int value, list *listReference){
    if(isEmpty(listReference)){
        return;
    }

    node *aux = listReference->initial;
    int i = 0;
    while(aux != NULL){
        if(aux->value == value){
            aux = aux->next;
            lista_remover_no_i(i, listReference);
            continue;
        }
        i++;
        aux = aux->next;
    }
}