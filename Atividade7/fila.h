#ifndef FILA_H
#define FILA_H

#define MAX_SIZE 10

// Definição da estrutura Fila que representa uma fila
typedef struct {
    int elementos[MAX_SIZE];  // Array para armazenar os elementos da fila
    int frente;               // Índice da frente da fila
    int tras;                 // Índice do final da fila
    int tamanho;              // Tamanho atual da fila
} Fila;

// Protótipos das funções relacionadas à fila
void inicializarFila(Fila *f);          // Inicializa a fila
int enfileirar(Fila *f, int valor);      // Insere um valor na fila
int desenfileirar(Fila *f);              // Remove um valor da fila
int frenteFila(Fila *f);                 // Obtém o valor na frente da fila
int tamanhoFila(Fila *f);                // Obtém o tamanho atual da fila

#endif
