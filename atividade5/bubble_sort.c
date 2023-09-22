#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O Bubble Sort compara dois elementos adjacentes e,
// se estiverem fora de ordem crescente, troca seus valores.

void bubbleSort(char *arr[], int n) {
    // Variavel temporaria para armazenar o que sera trocado
    char *temp;

    // Mostra quantas trocas foram feitas naquele loop
    int qtdTrocas;

    for (int i = 0; i < n - 1; i++) {
        qtdTrocas = 0;
        for (int j = 0; j < n - i - 1; j++) {
            // se um elemento for maior que seu sucessor
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // armazena o elemento arr[j]
                temp = arr[j];
                // Altera o valor dele pelo valor do sucessor que é maior
                arr[j] = arr[j + 1];
                // Define o valor do sucessor com aquele valor armazenado
                arr[j + 1] = temp;
                // Indica que uma troca foi feita
                qtdTrocas = 1;
            }
        }
        
        // Imprima o estado atual do array após cada passagem
        printf("Passagem %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%s ", arr[k]);
        }
        printf("\n");

        // Se não houver trocas nesta passagem, a matriz está ordenada e encerra
        if (qtdTrocas == 0)
            break;
    }
}
