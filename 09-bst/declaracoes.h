char comando[1];
int valor;

typedef struct folha {
    double data;
    struct folha *filho_E; //Esquerda
    struct folha *filho_D; //Direita
} folha;

folha* raiz;

void FREE(folha* raiz);                          //TERMINAR  
void inserir(folha **raiz, int valor);           // INSERIR
void buscar(folha **raiz, int valor);                       //BUSCAR
void PosOrdem(folha **raiz);        //POS-ORDEM
void EmOrdem(folha **raiz);      //EM-ORDEM
void PreOrdem(folha **raiz);   //PRE-ORDEM
void largura(folha **raiz);      //LARGURA