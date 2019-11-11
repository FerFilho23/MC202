#define MAX_CADEIAS 500
#define MAX_CHAR 251
#define tabela_size 6251
#define m 4987

char comando[15], cadeia[MAX_CHAR], tabela[tabela_size][MAX_CHAR];
int id, identificadores[tabela_size]; 
int h1, h2;

int inserir(int h1, int h2, char tabela[tabela_size][MAX_CHAR], char cadeia[], int id, int identificadores[]); //INSERIR
int busca(char cadeia[], char tabela[tabela_size][MAX_CHAR], int identificadores[]);              //BUSCAR
void remover(char tabela[tabela_size][MAX_CHAR], char cadeia[], int identificadores[]);   //REMOVER
long djb2( char *str);
int H1(int k);
int H2(int k);
