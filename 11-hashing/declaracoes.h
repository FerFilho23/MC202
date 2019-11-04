#define MAX_CADEIAS 5000
#define MAX_CHAR 251
#define tabela_size 6000 
#define m 4987

char comando[15], cadeia[MAX_CHAR], tabela[tabela_size][MAX_CHAR];
int id, identificadores[tabela_size]; 
int key_num;

void FREE();                 //REMOVER
void inserir(long key, char tabela[tabela_size][MAX_CHAR], char cadeia[], int id, int identificadores[]); //INSERIR
int busca(char cadeia[], char tabela[tabela_size][MAX_CHAR], int identificadores[]);              //BUSCAR
void remover(char tabela[tabela_size][MAX_CHAR], char cadeia[], int id, int identificadores[]);   //REMOVER
long djb2( char *str);
int h1(int k);
int hashingDUPLO (int k, int h1, int i);
