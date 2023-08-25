// Exercício 3 - Verificar se um elemento existe no array Escreva uma função que recebe um array de strings e uma string de busca, e retorna "1" se a string de busca existe no array, ou "0" caso não exista.
// Exemplo: busca_string(["texto", "J", "EDA"], "EDO")
// Saída: 0 


#include <stdio.h>
#include <string.h>

int busca_string(char* arr[], int size, char* busca) {
    for(int i = 0; i < size; i++) {
        if(strcmp(arr[i], busca) == 0) return 1;
    }
    return 0;
}

int main() {
    char* arr[] = {"texto", "J", "EDA"};
    printf("%d\n", busca_string(arr, 3, "EDO"));
    return 0;
}
