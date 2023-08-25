// Exercício 2 - Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros e retorna o menor e o maior elemento do array.
// Exemplo: menor_maior_array([5, 7, 9,6])
// Saída: 5, 9 


#include <stdio.h>

void menor_maior_array(int arr[], int size, int *menor, int *maior) {
    *menor = arr[0];
    *maior = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < *menor) *menor = arr[i];
        if(arr[i] > *maior) *maior = arr[i];
    }
}

int main() {
    int arr[] = {5, 7, 9, 6};
    int menor, maior;
    menor_maior_array(arr, 4, &menor, &maior);
    printf("Maior: %d\nMenor: %d\n", menor, maior);
    return 0;
}
