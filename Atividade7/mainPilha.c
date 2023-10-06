#include <stdio.h>
#include "pilha.h"

// Função que implementa a Torre de Hanoi usando pilha e recursão
void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar);

int main() {
    Pilha torreA, torreB, torreC;            // Declara três pilhas para representar as torres A, B e C
    inicializarPilha(&torreA);              // Inicializa a pilha da Torre A
    inicializarPilha(&torreB);              // Inicializa a pilha da Torre B
    inicializarPilha(&torreC);              // Inicializa a pilha da Torre C
    int n = 3;                               // Número de discos

    // Inicializa a Torre A com os discos (neste caso, 3 discos)
    for (int i = n; i > 0; i--) {
        empilhar(&torreA, i);                // Empilha os discos na Torre A
    }

    // Chama a função para resolver a Torre de Hanoi
    torreDeHanoi(n, &torreA, &torreC, &torreB);

    return 0;
}

// Função que implementa a Torre de Hanoi usando recursão
void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar) {
    if (n == 1) {
        int disco = desempilhar(origem);
        empilhar(destino, disco);
        printf("Mova o disco %d de Torre %c para Torre %c\n", disco, 'A', 'C');
    } else {
        // Move n-1 discos da origem para o auxiliar usando o destino como auxiliar
        torreDeHanoi(n - 1, origem, auxiliar, destino);
        
        // Move o disco restante da origem para o destino
        int disco = desempilhar(origem);
        empilhar(destino, disco);
        printf("Mova o disco %d de Torre %c para Torre %c\n", disco, 'A', 'C');
        
        // Move n-1 discos do auxiliar para o destino usando a origem como auxiliar
        torreDeHanoi(n - 1, auxiliar, destino, origem);
    }
}
