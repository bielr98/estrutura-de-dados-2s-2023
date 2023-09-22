#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_WORDS 100

void printArray(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    // Abra o arquivo de entrada para leitura
    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Leia as palavras do arquivo de entrada e armazene-as em um array
    char *palavras[MAX_WORDS];
    char buffer[100];
    int n = 0;

// Ele estava comendo o ultimo caracter de algumas palavras, 
//entao essa logica foi adicionada
    while (fgets(buffer, sizeof(buffer), entrada) != NULL) {
    size_t length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';  // Remova o caractere de nova linha, se existir
    }
    palavras[n] = strdup(buffer);
    n++;
}


    // Feche o arquivo de entrada
    fclose(entrada);

    // Chame a função bubbleSort para ordenar o array de palavras
    bubbleSort(palavras, n);

    // Imprima o estado atual do array após cada troca
    printf("Estado atual do array após cada troca:\n");
    printArray(palavras, n);

    // Crie e abra o arquivo de saída para escrita
    FILE *saida = fopen("arq_palavras_ordenado.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    // Escreva as palavras ordenadas no arquivo de saída
    for (int i = 0; i < n; i++) {
        fprintf(saida, "%s\n", palavras[i]);
        free(palavras[i]);  // Libere a memória alocada para cada palavra
    }

    // Feche o arquivo de saída
    fclose(saida);

    return 0;
}
