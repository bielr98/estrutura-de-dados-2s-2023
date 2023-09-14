//crie um programa em C que calcule a
//regressao linear de um array de coordenadas(pontos).
// y = ax + b
#include <stdio.h>
#include <stdlib.h>

// struct para representar um ponto (x, y)
typedef struct {
    int x;
    float y;
} Ponto;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s dados.csv\n", argv[0]);
        return 1;
    }

    // Abrir o arquivo dados.CSV para leitura
    FILE *dados = fopen(argv[1], "r");
    if (dados == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Conte o número de registros no arquivo
    int num_registros = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), dados) != NULL) {
        num_registros++;
    }

    // Aloque dinamicamente um array de struct Ponto
    Ponto *pontos = (Ponto *)malloc(num_registros * sizeof(Ponto));
    if (pontos == NULL) {
        perror("Erro ao alocar memória");
        return 1;
    }

    // Retorne ao início do arquivo
    fseek(dados, 0, SEEK_SET);

    // Leia os pontos (x, y) do arquivo e calcule a média
    int soma_x = 0;
    float soma_y = 0.0;

    for (int i = 0; i < num_registros; i++) {
        if (fgets(linha, sizeof(linha), dados) == NULL) {
            perror("Erro ao ler o arquivo");
            return 1;
        }
        sscanf(linha, "%d,%f", &(pontos[i].x), &(pontos[i].y));
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }

    // Calcule a média
    float media_x = (float)soma_x / num_registros;
    float media_y = soma_y / num_registros;

    // Calcule os coeficientes da regressão linear
    float soma_xy = 0.0;
    float soma_xx = 0.0;
    for (int i = 0; i < num_registros; i++) {
        float desvio_x = pontos[i].x - media_x;
        float desvio_y = pontos[i].y - media_y;
        soma_xy += desvio_x * desvio_y;
        soma_xx += desvio_x * desvio_x;
    }

    float coeficiente_angular = soma_xy / soma_xx;
    float coeficiente_linear = media_y - coeficiente_angular * media_x;

    // Exiba os resultados da regressão linear
    printf("Equação da regressão linear: y = %.2fx + %.2f\n", coeficiente_angular, coeficiente_linear);

    // Libere a memória alocada
    free(pontos);

    // Feche o arquivo
    fclose(dados);

    return 0;
}
