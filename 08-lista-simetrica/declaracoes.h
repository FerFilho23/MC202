char comando[1];
int inicio, termino, posicao;
double valor;

typedef struct node {
    double data;
    struct node *A;
    struct node *B; 
} node;

node* head;

void FREE(node* head);
void inserir(node** head, double valor, int posicao);
void print(node** head);
void reverter(node** head, int inicio, int termino);