// Exercício 5 - Multiplicar elementos de dois arrays. Escreva uma função que recebe dois arrays de números inteiros com o mesmo tamanho e retorna um novo array com os elementos resultantes da multiplicação dos elementos dos dois arrays.
// Exemplo: multiplica_array([5, 7, 9, 6], [5, 7, 9,6])
// Saída: [25, 49, 81, 36] 

#include <stdio.h>

void multiplica_array(int arr1[], int arr2[], int size, int result[]) {
    for(int i = 0; i < size; i++) {
        result[i] = arr1[i] * arr2[i];
    }
}

int main() {
    //aray base
    int arr1[] = {5, 7, 9, 6};
    //array de multiplicacao
    int arr2[] = {2, 3, 7, 2};
    int result[4];
    multiplica_array(arr1, arr2, 4, result);
    for(int i = 0; i < 4; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
