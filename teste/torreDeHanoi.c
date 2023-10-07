#include <stdio.h>

// Função para resolver a Torre de Hanoi
void torreDeHanoi(int n, char origem, char destino, char auxiliar, int pino1[], int pino2[], int pino3[]);
void mostrarEstado(int pino1[], int pino2[], int pino3[], int numDiscos);

int main() {
    int numDiscos;

    // Solicita ao usuário o número de discos
    printf("Digite o número de discos: ");
    scanf("%d", &numDiscos);

    // Inicializa os pinos com discos no pino 1
    int pino1[numDiscos];
    int pino2[numDiscos];
    int pino3[numDiscos];

    for (int i = 0; i < numDiscos; i++) {
        pino1[i] = numDiscos - i;
        pino2[i] = 0;
        pino3[i] = 0;
    }

    // Mostra o estado inicial dos pinos
    mostrarEstado(pino1, pino2, pino3, numDiscos);

    int origem, destino;

    while (1) {
        // Solicita ao usuário a ação de desempilhar
        printf("\nDe qual pino deseja desempilhar (1, 2 ou 3): ");
        scanf("%d", &origem);

        if (origem < 1 || origem > 3) {
            printf("Pino inválido. Tente novamente.\n");
            continue;
        }

        // Solicita ao usuário a ação de empilhar
        printf("Em qual pino deseja empilhar (1, 2 ou 3): ");
        scanf("%d", &destino);

        if (destino < 1 || destino > 3) {
            printf("Pino inválido. Tente novamente.\n");
            continue;
        }

        origem--;  // Ajusta para usar índices de 0 a 2
        destino--; // Ajusta para usar índices de 0 a 2

        // Verifica se há disco para desempilhar no pino de origem
        int disco = 0;
        for (int i = numDiscos - 1; i >= 0; i--) {
            if (origem == 0 && pino1[i] != 0) {
                disco = pino1[i];
                pino1[i] = 0;
                break;
            } else if (origem == 1 && pino2[i] != 0) {
                disco = pino2[i];
                pino2[i] = 0;
                break;
            } else if (origem == 2 && pino3[i] != 0) {
                disco = pino3[i];
                pino3[i] = 0;
                break;
            }
        }

        // Verifica se o movimento é válido
        if (disco == 0) {
            printf("Nenhum disco para desempilhar no pino %d. Tente novamente.\n", origem + 1);
            continue;
        }

        // Verifica se o destino está vazio ou se o disco é menor que o do topo do destino
        int topoDestino = 0;
        for (int i = numDiscos - 1; i >= 0; i--) {
            if (destino == 0 && pino1[i] != 0) {
                topoDestino = pino1[i];
                break;
            } else if (destino == 1 && pino2[i] != 0) {
                topoDestino = pino2[i];
                break;
            } else if (destino == 2 && pino3[i] != 0) {
                topoDestino = pino3[i];
                break;
            }
        }

        // Realiza o movimento
        if (destino == 0) {
            for (int i = numDiscos - 1; i >= 0; i--) {
                if (pino1[i] == 0) {
                    pino1[i] = disco;
                    break;
                }
            }
        } else if (destino == 1) {
            for (int i = numDiscos - 1; i >= 0; i--) {
                if (pino2[i] == 0) {
                    pino2[i] = disco;
                    break;
                }
            }
        } else if (destino == 2) {
            for (int i = numDiscos - 1; i >= 0; i--) {
                if (pino3[i] == 0) {
                    pino3[i] = disco;
                    break;
                }
            }
        }

        // Mostra o estado atual dos pinos após o movimento
        mostrarEstado(pino1, pino2, pino3, numDiscos);
    }

    return 0;
}

void torreDeHanoi(int n, char origem, char destino, char auxiliar, int pino1[], int pino2[], int pino3[]) {
    if (n == 1) {
        int disco;

        if (origem == 'A') {
            disco = pino1[n - 1];
            pino1[n - 1] = 0;
        } else if (origem == 'B') {
            disco = pino2[n - 1];
            pino2[n - 1] = 0;
        } else {
            disco = pino3[n - 1];
            pino3[n - 1] = 0;
        }

        if (destino == 'A') {
            for (int i = 0; i < n; i++) {
                if (pino1[i] == 0) {
                    pino1[i] = disco;
                    break;
                }
            }
        } else if (destino == 'B') {
            for (int i = 0; i < n; i++) {
                if (pino2[i] == 0) {
                    pino2[i] = disco;
                    break;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (pino3[i] == 0) {
                    pino3[i] = disco;
                    break;
                }
            }
        }

        // Mostra o estado atual dos pinos após mover o disco
        mostrarEstado(pino1, pino2, pino3, n);

        return;
    }

    // Move n-1 discos da origem para o auxiliar usando o destino como auxiliar
    torreDeHanoi(n - 1, origem, auxiliar, destino, pino1, pino2, pino3);

    // Move o disco restante da origem para o destino
    torreDeHanoi(1, origem, destino, auxiliar, pino1, pino2, pino3);

    // Move n-1 discos do auxiliar para o destino usando a origem como auxiliar
    torreDeHanoi(n - 1, auxiliar, destino, origem, pino1, pino2, pino3);
}

void mostrarEstado(int pino1[], int pino2[], int pino3[], int numDiscos) {
    printf("\nEstado atual dos Pinos:\n");

    printf("Pino1 [1]: ");
    for (int i = 0; i < numDiscos; i++) {
        if (pino1[i] != 0) {
            printf("[%d] ", pino1[i]);
        }
    }
    printf("\n");

    printf("Pino2 [2]: ");
    for (int i = 0; i < numDiscos; i++) {
        if (pino2[i] != 0) {
            printf("[%d] ", pino2[i]);
        }
    }
    printf("\n");

    printf("Pino3 [3]: ");
    for (int i = 0; i < numDiscos; i++) {
        if (pino3[i] != 0) {
            printf("[%d] ", pino3[i]);
        }
    }
    printf("\n");
}