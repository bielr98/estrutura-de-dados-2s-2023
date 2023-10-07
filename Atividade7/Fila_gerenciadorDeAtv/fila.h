#ifndef FILA_H
#define FILA_H

// Definição da estrutura "Tarefa" que representa uma tarefa na fila
typedef struct Tarefa {
    char descricao[100];    // Descrição da tarefa
    struct Tarefa* proxima; // Ponteiro para a próxima tarefa na fila
} Tarefa;

// Definição da estrutura "Fila" que representa uma fila de tarefas
typedef struct {
    Tarefa* inicio; // Ponteiro para o início da fila
    Tarefa* fim;    // Ponteiro para o fim da fila
} Fila;

// Função para inicializar uma fila vazia
void inicializarFila(Fila* fila);

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila);

// Função para adicionar uma nova tarefa à fila
void adicionarTarefa(Fila* fila, const char* descricao);

// Função para remover a tarefa no início da fila
void removerTarefa(Fila* fila);

// Função para listar todas as tarefas na fila
void listarTarefas(Fila* fila);

#endif
