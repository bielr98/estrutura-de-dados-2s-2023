#include "pilha.h"

// Função para inicializar uma pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;          // Inicializa o topo da pilha como -1 (pilha vazia)
}

// Função para empilhar (inserir) um valor na pilha
int empilhar(Pilha *p, int valor) {
    if (p->topo < MAX_SIZE - 1) {       // Verifica se a pilha não está cheia
        p->elementos[++p->topo] = valor; // Insere o valor na próxima posição disponível
        return 1;                        // Retorna 1 para sucesso
    } else {
        return 0;                        // Retorna 0 para pilha cheia
    }
}

// Função para desempilhar (remover) um valor da pilha
int desempilhar(Pilha *p) {
    if (p->topo >= 0) {                // Verifica se a pilha não está vazia
        return p->elementos[p->topo--]; // Remove e retorna o valor do topo da pilha
    } else {
        return -1;                      // Retorna -1 para pilha vazia
    }
}

// Função para obter o valor no topo da pilha
int topoPilha(Pilha *p) {
    if (p->topo >= 0) {
        return p->elementos[p->topo];   // Retorna o valor no topo da pilha
    } else {
        return -1;                       // Retorna -1 para pilha vazia
    }
}
