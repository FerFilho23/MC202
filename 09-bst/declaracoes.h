char comando[15];
int chave;

typedef struct node {
    int key;
    struct node *D;
    struct node *E; 
} folha;

folha* raiz;

void FREE(folha* raiz);
void inserir(folha** raiz, int chave);
void buscar(folha* raiz, int chave);
void PosOrdem(folha** raiz);        //POS-ORDEM
void EmOrdem(folha** raiz);      //EM-ORDEM
void PreOrdem(folha** raiz);   //PRE-ORDEM
void Largura(folha** raiz);      //LARGURA