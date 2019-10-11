
int inteiro, auxDEBUG;
char comando[100];

typedef struct vetor{

    int *array;
    int *inicio;
    int *fim;
    int tamanho;
    int capacidade;

} Vet;

Vet vetor;

void insertFirst(Vet* vetor, int inteiro);   
void insertLast(Vet* vetor, int inteiro);
int isEmpty(Vet vetor);    
void printFirst(Vet vetor); 
void printLast(Vet vetor);  
void removeFirst(Vet* vetor);
void removeLast(Vet* vetor);
