#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Função para inicializar uma fila vazia
void inicializarFila(Fila* fila) {
    fila->inicio = NULL; // Inicializa o ponteiro de início como NULL (fila vazia)
    fila->fim = NULL;    // Inicializa o ponteiro de fim como NULL (fila vazia)
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila) {
    return fila->inicio == NULL; // Retorna 1 se a fila estiver vazia, caso contrário, retorna 0
}

// Função para adicionar uma nova tarefa à fila
void adicionarTarefa(Fila* fila, const char* descricao) {
    //malloc aloca um bloco de memória com um tamanho específico 
    //e retornar um ponteiro para o início desse bloco de memória.
    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa)); // Aloca memória para uma nova tarefa
    if (novaTarefa == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para a tarefa.\n");
        exit(1); // Se a alocação de memória falhar, exibe uma mensagem de erro e encerra o programa
    }
    
    // Copia a descrição da tarefa para a estrutura da nova tarefa
    strncpy(novaTarefa->descricao, descricao, sizeof(novaTarefa->descricao));
    novaTarefa->proxima = NULL; // Inicializa o ponteiro "proxima" da nova tarefa como NULL
    
    if (estaVazia(fila)) {
        // Se a fila estiver vazia, a nova tarefa será tanto o início quanto o fim da fila
        fila->inicio = novaTarefa;
    } else {
        // Se a fila não estiver vazia, a nova tarefa será adicionada ao final da fila
        fila->fim->proxima = novaTarefa;
    }
    
    fila->fim = novaTarefa; // A nova tarefa é sempre o último elemento da fila
}

// Função para remover a tarefa no início da fila
void removerTarefa(Fila* fila) {
    if (estaVazia(fila)) {
        fprintf(stderr, "Erro: A fila de tarefas está vazia.\n");
        return; // Se a fila estiver vazia, exibe uma mensagem de erro e sai da função
    }
    
    Tarefa* tarefaRemovida = fila->inicio; // A tarefa a ser removida é a primeira da fila
    fila->inicio = fila->inicio->proxima;   // O início da fila agora aponta para o próximo elemento
    
    free(tarefaRemovida); // Libera a memória da tarefa removida
}

// Função para listar todas as tarefas na fila
void listarTarefas(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Nenhuma tarefa para listar.\n"); // Se a fila estiver vazia, exibe uma mensagem
        return;
    }
    
    printf("Tarefas do dia:\n");
    Tarefa* atual = fila->inicio; // Começa a partir do início da fila
    int contador = 1;
    
    while (atual != NULL) {
        printf("%d. %s\n", contador, atual->descricao); // Exibe o número da tarefa e a descrição
        atual = atual->proxima; // Move para a próxima tarefa na fila
        contador++;
    }
}
