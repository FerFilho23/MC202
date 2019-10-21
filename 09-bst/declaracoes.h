char comando[15];
int chave;

typedef struct folha {
    int key;
    struct folha *D;
    struct folha *E;
    struct folha *next;
} folha;

folha* atual, *raiz, *aux; //USAR NA FILA; 

void FREE(folha* raiz);
void inserir(folha** raiz, int chave);
void buscar(folha* raiz, int chave);
void PosOrdem(folha* raiz);        //POS-ORDEM
void EmOrdem(folha* raiz);      //EM-ORDEM
void PreOrdem(folha* raiz);   //PRE-ORDEM
void Largura(folha* raiz, folha* atual, folha* aux);      //LARGURA
void MAX(folha* raiz);
void MIN(folha* raiz);
void SUCESSOR(folha* raiz);
void PREDECESSOR(folha* raiz);
