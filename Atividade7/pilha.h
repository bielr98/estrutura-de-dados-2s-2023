#ifndef PILHA_H
#define PILHA_H

#define MAX_SIZE 10

// Definição da estrutura Pilha que representa uma pilha
typedef struct {
    int elementos[MAX_SIZE];  // Array para armazenar os elementos da pilha
    int topo;                 // Índice do topo da pilha
} Pilha;

// Protótipos das funções relacionadas à pilha
void inicializarPilha(Pilha *p);        // Inicializa a pilha
int empilhar(Pilha *p, int valor);      // Empilha um valor na pilha
int desempilhar(Pilha *p);              // Desempilha um valor da pilha
int topoPilha(Pilha *p);                // Obtém o valor no topo da pilha

#endif
