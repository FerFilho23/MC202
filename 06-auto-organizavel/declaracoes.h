int N, R;       // N = list size
int requisicao[10000];               // Variaveis

typedef struct node {
    int contador;
    int number;
    struct node *next;
} node;

node* listaMTF; // Declaracao de Listas
node* listaTR;
node* listaC;
int custoMTF;
int custoTR;
int custoC;

int MTF(int req, node** listaMTF, int N); //Funcoes
int TR(int req, node** listaTR, int N);
int C(int req, node** listaC, int N);
int createList(int num, node** lista);
void FREE(node* lista);