#define MAX_CADEIAS 5000
#define MAX_CHAR 251
#define tabela_size 6000 

char comando[15], cadeia[MAX_CHAR], tabela[tabela_size];

void FREE();                 //REMOVER
void inserir();  //INSERIR
void busca();   //BUSCAR
void remover();         //REMOVER
unsigned long djb2( char *str);
int h1(int k);
