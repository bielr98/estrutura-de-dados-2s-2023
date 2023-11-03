#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include <string.h>

void initializeTable(){
    for(int i = 0; i < 26; i++){
        table[i] = "";
    }
}

int getIndex(char *chave){
    //Get the first character of the string
    char fisrtCharactere = chave[0];
    //Converts into ascii value
    int index = fisrtCharactere;
    //Operate over the index to assign a index in the rage of 0 -> 26
    index = index - 97;
    return index;
}

const char* hash_table_get(char* chave){
    int index = getIndex(chave);
    printf("Valor retornado : %s\n", table[index]);
    return table[index];
}

void hash_table_put(char* chave, char* dado){
    int index = getIndex(chave);
    table[index] = dado;
}

int hash_table_contains(char* chave){
    int index = getIndex(chave);
    if(strcmp(table[index], "") == 0){
        printf("Valor nulo. \n");
        return 0;
    }else{
        printf("Contem valor : %s. \n", table[index]);
        return 1;
    }
}

void hash_table_remove(char* chave){
    int index = getIndex(chave);
    table[index] = "";
}