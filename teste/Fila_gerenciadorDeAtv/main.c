#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    Fila filaDeTarefas; // Declaração de uma fila para armazenar tarefas
    inicializarFila(&filaDeTarefas); // Inicializa a fila vazia
    
    while (1) { // Loop infinito para interação com o usuário
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Remover tarefa\n");
        printf("3. Listar tarefas\n");
        printf("4. Sair\n");
        
        int escolha;
        scanf("%d", &escolha); // Lê a escolha do usuário
        
        switch (escolha) {
            case 1: {
                char descricao[100];
                printf("Digite a descrição da tarefa: ");
                getchar(); // Limpa o buffer do teclado
                fgets(descricao, sizeof(descricao), stdin); // Lê a descrição da tarefa
                descricao[strcspn(descricao, "\n")] = '\0'; // Remove a quebra de linha
                
                adicionarTarefa(&filaDeTarefas, descricao); // Adiciona a tarefa à fila
                printf("Tarefa adicionada com sucesso.\n");
                break;
            }
            case 2:
                removerTarefa(&filaDeTarefas); // Remove a tarefa no início da fila
                printf("Tarefa removida com sucesso.\n");
                break;
            case 3:
                listarTarefas(&filaDeTarefas); // Lista todas as tarefas na fila
                break;
            case 4:
                printf("Saindo do programa.\n");
                exit(0); // Encerra o programa
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
    
    return 0;
}
