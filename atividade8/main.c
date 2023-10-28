#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    list *myList = createList();

    insertValue(10, myList);
    insertValue(20, myList);
    insertValue(30, myList);
    insertValue(10, myList);
    insertValue(40, myList);
    printList(myList);
    int result = lista_verificar_existencia(20, myList);
    int quantityOcurrency = lista_verificar_ocorrencias(10, myList);
    int sizeList = listSize(myList);
    lista_imprimir_inversa(myList);
    lista_inserir_no_i(50, 2, myList);
    printList(myList);
    lista_remover_no_i(2, myList);
    printList(myList);
    lista_remover_no(10, myList);
    printList(myList);
} 