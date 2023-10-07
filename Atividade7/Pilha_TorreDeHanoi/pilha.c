#include "pilha.h"
#include <stdio.h>

// Função para inicializar uma pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1; // Define o topo da pilha como -1 para indicar que está vazia
}

// Função para adicionar um valor à pilha (push)
int push(Pilha *p, int valor) {
    if (p->topo < MAX_SIZE - 1) { // Verifica se a pilha não está cheia
        p->elementos[++p->topo] = valor; // Incrementa o topo e adiciona o valor à pilha
        return 1;  // Sucesso
    } else {
        return 0;  // Pilha cheia
    }
}

// Função para remover um valor da pilha (pop)
int pop(Pilha *p) {
    if (p->topo >= 0) { // Verifica se a pilha não está vazia
        return p->elementos[p->topo--]; // Retorna o valor do topo e o remove da pilha
    } else {
        return -1;  // Pilha vazia
    }
}

// Função para obter o valor no topo da pilha sem removê-lo
int topoPilha(Pilha *p) {
    if (p->topo >= 0) { // Verifica se a pilha não está vazia
        return p->elementos[p->topo]; // Retorna o valor no topo da pilha
    } else {
        return -1;  // Pilha vazia
    }
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1; // Retorna 1 se a pilha estiver vazia, 0 caso contrário
}

// Função para mostrar o conteúdo da pilha
void mostrarPilha(Pilha *p) {
    for (int i = p->topo; i >= 0; i--) { // Itera da parte superior para a base da pilha
        printf("Disco %d, ", p->elementos[i]); // Imprime cada elemento na pilha
    }
}
