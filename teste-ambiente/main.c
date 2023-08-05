#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//logica do profesor

int verificaNumeroPrimo(int n){
    int ret = 0;
    if (n % 2 == 0){
        return = 0;
    }
while (cont < n){
    if(n % cont==0){
        return 0;
    }   
    cont += 2;
    return 1;
    }
}


//logica do GPT
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
    int n = 123131231;
    printf("n = %d  \n", n);
    printf("O numero %d eh primo? %d\n", n, ehPrimo(n));


    return 0;



}

