// Exercício 4 - Contar a quantidade de ocorrências de um elemento no array. Escreva uma função que recebe um array de números inteiros e um número inteiro de busca, e retorna a quantidade de vezes que o número de busca aparece no array.
// Exemplo: conta_int_array([5, 7, 9, 6, 7, 11, 6, 5], 7)
// Saída: 2

#include <stdio.h>

int conta_int_array(int arr[], int size, int busca) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == busca) count++;
    }
    return count;
}

int main() {
    int arr[] = {5, 7, 9, 6, 7, 11, 6, 5};
    //array, tamanho do array, numero de busca
    printf("%d\n", conta_int_array(arr, 8, 7));
    return 0;
}
