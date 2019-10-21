char comando[15];
int chave;

typedef struct folha {
    int key;
    struct folha *D;
    struct folha *E;
    struct folha *pai;
    struct folha *next;
} folha;

folha* atual, *raiz, *aux, *aux2; //USAR NA FILA; 

void FREE(folha* raiz);
void inserir(folha** raiz, int chave);
folha* busca(folha* raiz, int chave);
void PosOrdem(folha* raiz);        //POS-ORDEM
void EmOrdem(folha* raiz);      //EM-ORDEM
void PreOrdem(folha* raiz);   //PRE-ORDEM
void Largura(folha* raiz, folha* atual, folha* aux);      //LARGURA
folha* MAX(folha *raiz);
folha* MIN(folha *raiz);
folha* sucessor(folha *raiz, folha *atual);
folha* predecessor(folha *raiz, folha *atual);
