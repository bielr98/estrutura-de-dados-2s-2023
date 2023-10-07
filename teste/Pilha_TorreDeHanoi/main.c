#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <time.h>

// Função para embaralhar um array de inteiros
void shuffleArray(int *array, int size) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gere um índice aleatório entre 0 e i (incluindo i)
        // Troque os elementos de posição
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    // Inicializa as pilhas representando os pinos
    Pilha pino1, pino2, pino3;
    inicializarPilha(&pino1);
    inicializarPilha(&pino2);
    inicializarPilha(&pino3);

    int numDiscos;

    // Solicita ao usuário o número de discos
    printf("Digite o número de discos: ");
    scanf("%d", &numDiscos);

    // Cria um array com os discos em ordem crescente
    int discos[numDiscos];
    for (int i = 0; i < numDiscos; i++) {
        discos[i] = i + 1;
    }

    // Embaralhe os discos aleatoriamente
    shuffleArray(discos, numDiscos);

    // Insira os discos na pilha representando o primeiro pino
    for (int i = numDiscos - 1; i >= 0; i--) {
        push(&pino1, discos[i]);
    }

    int movimentos = 0;

    while (!pilhaVazia(&pino1) || !pilhaVazia(&pino2)) {
        movimentos++;

        // Mostra o estado atual dos pinos
        printf("\nEstado atual dos Pinos:\n");

        printf("Pino1 [1]: ");
        mostrarPilha(&pino1);
        printf("\n");

        printf("Pino2 [2]: ");
        mostrarPilha(&pino2);
        printf("\n");

        printf("Pino3 [3]: ");
        mostrarPilha(&pino3);
        printf("\n");

        int origem, destino;

        // Solicita ao usuário o pino de origem e pino de destino
        printf("\nDe qual pino deseja Desempilhar?\n");
        scanf("%d", &origem);
        printf("Em qual pino deseja Empilhar?\n");
        scanf("%d", &destino);

        Pilha *pinoOrigem, *pinoDestino;

        // Determina qual pino corresponde ao pino de origem e destino
        switch (origem) {
            case 1:
                pinoOrigem = &pino1;
                break;
            case 2:
                pinoOrigem = &pino2;
                break;
            case 3:
                pinoOrigem = &pino3;
                break;
            default:
                printf("Pino de origem inválido. Tente novamente.\n");
                continue;
        }

        switch (destino) {
            case 1:
                pinoDestino = &pino1;
                break;
            case 2:
                pinoDestino = &pino2;
                break;
            case 3:
                pinoDestino = &pino3;
                break;
            default:
                printf("Pino de destino inválido. Tente novamente.\n");
                continue;
        }

        // Verifica se a operação é válida
        int discoOrigem = topoPilha(pinoOrigem);
        int discoDestino = topoPilha(pinoDestino);

        if (discoOrigem == -1) {
            printf("Nenhum disco para desempilhar no pino de origem. Tente novamente.\n");
            continue;
        } else if (discoDestino != -1 && discoOrigem > discoDestino) {
            printf("Movimento inválido. Disco de origem maior que o disco de destino. Tente novamente.\n");
            continue;
        }

        // Realiza a operação de desempilhar e empilhar
        pop(pinoOrigem);
        push(pinoDestino, discoOrigem);

        // Verifica se o jogo foi resolvido
        if (pilhaVazia(&pino1) && pilhaVazia(&pino2)) {
            printf("Parabéns! Você resolveu a Torre de Hanoi em %d movimentos.\n", movimentos);
            break;
        }
    }

    return 0;
}