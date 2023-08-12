#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//logica do professor

// int verificaNumeroPrimo(int n){
//     int ret = 0;
//     if (n % 2 == 0){
//         return = 0;
//     }
// while (cont < n){
//     if(n % cont==0){
//         return 0;
//     }   
//     cont += 2;
//     return 1;
//     }
// }


//Nova logica
bool ehPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}




int main(){
    int n = 0;

    printf("Insira um numero Para ver se e primo?\n");
    scanf("%i", &n);
    fflush(stdin);
    printf("n = %d  ", n);
    printf("O numero %d eh primo?\n", n);

if (ehPrimo(n) == 1) {
        printf("Sim");

    }else {
        printf("Nao");
    }
    return 0;



}

