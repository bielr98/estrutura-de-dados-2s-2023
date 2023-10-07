#ifndef PILHA_H
#define PILHA_H

#define MAX_SIZE 10

// Definição da estrutura Pilha
typedef struct {
    int elementos[MAX_SIZE]; // Array para armazenar os elementos da pilha
    int topo; // Índice que representa o topo da pilha
} Pilha;

// Função para inicializar uma pilha
void inicializarPilha(Pilha *p);

// Função para adicionar um valor à pilha (push)
int push(Pilha *p, int valor);

// Função para remover um valor da pilha (pop)
int pop(Pilha *p);

// Função para obter o valor no topo da pilha sem removê-lo
int topoPilha(Pilha *p);

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *p);

// Função para mostrar o conteúdo da pilha
void mostrarPilha(Pilha *p);

#endif
