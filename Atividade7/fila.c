#include "fila.h"

// Função para inicializar uma fila
void inicializarFila(Fila *f) {
    f->frente = 0;       // Inicializa o índice da frente da fila como 0
    f->tras = -1;        // Inicializa o índice do final da fila como -1 (vazia)
    f->tamanho = 0;      // Inicializa o tamanho da fila como 0 (vazia)
}

// Função para enfileirar (inserir) um valor na fila
int enfileirar(Fila *f, int valor) {
    if (f->tamanho < MAX_SIZE) {                 // Verifica se a fila não está cheia
        f->tras = (f->tras + 1) % MAX_SIZE;      // Move o índice do final circularmente
        f->elementos[f->tras] = valor;           // Insere o valor na posição do final
        f->tamanho++;                            // Aumenta o tamanho da fila
        return 1;                                 // Retorna 1 para sucesso
    } else {
        return 0;                                 // Retorna 0 para fila cheia
    }
}

// Função para desenfileirar (remover) um valor da fila
int desenfileirar(Fila *f) {
    if (f->tamanho > 0) {                     // Verifica se a fila não está vazia
        int valor = f->elementos[f->frente];  // Obtém o valor na frente da fila
        f->frente = (f->frente + 1) % MAX_SIZE;  // Move o índice da frente circularmente
        f->tamanho--;                          // Reduz o tamanho da fila
        return valor;                          // Retorna o valor removido
    } else {
        return -1;                             // Retorna -1 para fila vazia
    }
}

// Função para obter o valor na frente da fila
int frenteFila(Fila *f) {
    if (f->tamanho > 0) {
        return f->elementos[f->frente];        // Retorna o valor na frente da fila
    } else {
        return -1;                              // Retorna -1 para fila vazia
    }
}

// Função para obter o tamanho atual da fila
int tamanhoFila(Fila *f) {
    return f->tamanho;                         // Retorna o tamanho da fila
}
