#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificaNumeroPrimo(int n) {
    if (n <= 1) {
        return 0; // 0 para números não primos
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // 0 para números não primos
        }
    }
    return 1; // 1 para números primos
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);//converter strings em inteiros
    int resultado = verificaNumeroPrimo(numero);

    printf("%d\n", resultado);

    return 0;
}
