//define o nó como um Valor(value) inteiro.
typedef struct no{
    char value;
//ponteiro para o próximo nó na lista
    struct no *next;
}node;

//lista 
typedef struct{
    //ponteiro para o nó inicial
    node *initial;
}list;

void insertValue(int value, list *listReference); // inserir valor
void printList(list *listReference); //Imprime a lista
int isEmpty(list *listReference); //verifica se a list esta vazia
node *createNode(int value);//cria um nó com um valor int
list *createList(); //cria nova lista
int listSize(list *listReference);//tamanho da lista


int lista_verificar_existencia(int value, list *listReference);//verifica se contem o valor
int lista_verificar_ocorrencias(int value, list *listReference);//verifica quantas vezes um valor esta presente
void lista_imprimir_inversa(list *listReference);//printa em ordem inversa
void lista_inserir_no_i(int value, int position, list *listReference);//insere um valor numa posicao especifica
void lista_remover_no_i(int position, list *listReference);//Remove um no de posicao especifica
void lista_remover_no(int value, list *listReference);//Remove um no com um valor especifico
