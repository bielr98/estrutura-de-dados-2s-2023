//Exercício 1 - Soma dos elementos de um array. Escreva uma função que recebe um array de números inteiros e retorna a soma de todos os elementos;
// Exemplo: soma_array([5, 7, 9,6])
// Saída: 27


#include <stdio.h>

int soma_array(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {5, 7, 9, 6};
    printf("%d\n", soma_array(arr, 4));
    return 0;
}
