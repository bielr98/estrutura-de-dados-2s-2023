typedef struct no{
    float value;
    struct no *next;
}node;

typedef struct{
    node *initial;
}list;

void insertValue(float value, list *listReference);
void printList(list *listReference);
int isEmpty(list *listReference);
node *createNode(float value);
list *createList();
int containsValue(float value, list *listReference);
int verifyOcurrency(float value, list *listReference);
int listSize(list *listReference);
void printInverseOrder(list *listReference);
void insertInto(float value, int position, list *listReference);
void removeInto(int position, list *listReference);
void removeNodeWith(float value, list *listReference);
void insertSorted(list *listReference, float value);
void sortList(list *listReference);