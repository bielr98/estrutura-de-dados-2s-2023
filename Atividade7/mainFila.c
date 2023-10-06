#include <stdio.h>
#include "fila.h"

int main() {
    Fila listaDeAtividades;                 // Declara uma variável do tipo Fila para armazenar a lista de atividades
    inicializarFila(&listaDeAtividades);    // Inicializa a fila, configurando todos os valores iniciais

    // Adiciona atividades à lista
    enfileirar(&listaDeAtividades, 1);      // Enfileira a atividade com o valor 1
    enfileirar(&listaDeAtividades, 2);      // Enfileira a atividade com o valor 2
    enfileirar(&listaDeAtividades, 3);      // Enfileira a atividade com o valor 3

    printf("Lista de Atividades:\n");

    while (tamanhoFila(&listaDeAtividades) > 0) {  // Enquanto a fila não estiver vazia
        int atividade = desenfileirar(&listaDeAtividades);  // Remove a próxima atividade da fila
        printf("Atividade %d\n", atividade);   // Imprime o valor da atividade
    }

    return 0;
}
