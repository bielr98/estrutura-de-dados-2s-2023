/*
No seu repositório de atividades, crie uma pasta atvidade9. 
Implemente uma lista encadeada conforme definido na atividade 8. Adicione a função:

void lista_inserir_no_ordenado(No* L, No* no);

Essa função deve inserir um nó na lista considerando o seu valor, 
de forma que a lista se mantenha ordenada, sendo o primeiro nó o de menor valor e o último 
nó o de maior valor.

O nó deve armazenar valores do tipo FLOAT.

No main.c, crie duas listas: lista_nao_ordenada e lista_ordenada.

Leia o arquivo "1kk_rand_float.csv" (anexo) e carregue os números nas duas listas. 
O arquivo possui um número por linha, no formato "0.00".

Calcule o tempo médio (em segundos) de inserção em cada lista e compare os tempos obtidos.
 Como solução, poste o link da pasta atividade9 e um comentário descrevendo a observação do experimento.

OBS: para cada número lido no arquivo, devem ser criados 2 nós com o número lido. 
Cada nó deve ser inserido em uma das listas.


Anotação : O tempo de inserção ordenado leva MUITO mais tempo já que são mais comparações.
*/


#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    list *sortedList = createList();
    list *unsortedList = createList();

    FILE *csvFile = fopen("1kk_rand_float.csv", "r");

    if(csvFile == NULL){
        printf("CSV file null\n");
        return -1;
    }

    float valueRead = 0;

    do{
        fscanf(csvFile, "%f", &valueRead);
        printf("Reading : %.2f\n", valueRead);
        insertValue(valueRead, unsortedList);
        insertSorted(sortedList, valueRead);
    }while(!feof(csvFile));


    fclose(csvFile);

} 