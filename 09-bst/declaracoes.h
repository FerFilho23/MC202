char comando[15];
int chave, x1, x2, i;

typedef struct folha {
    int key;
    struct folha *D;
    struct folha *E;
    struct folha *pai;
    struct folha *next;
} folha;

folha* atual, *raiz, *aux, *aux2; //USAR NA FILA DA LARGURA;

void FREE(folha* raiz);                 //REMOVER
void inserir(folha** raiz, int chave);  //INSERIR
folha* busca(folha* raiz, int chave);   //BUSCAR
void PosOrdem(folha* raiz);        //POS-ORDEM
void EmOrdem(folha* raiz);      //EM-ORDEM
void PreOrdem(folha* raiz);   //PRE-ORDEM
void Largura(folha* raiz, folha* atual, folha* aux);      //LARGURA
folha* MAX(folha *raiz);        //MAXIMO
folha* MIN(folha *raiz);        //MINIMO        
folha* sucessor(folha *atual);     //SUCESSOR
folha* predecessor(folha *atual);  //PREDECESSOR  
folha* remover(folha *raiz, int chave);         //REMOVER
int intervalo(folha *raiz, int x1, int x2, int i);    //INTERVALO