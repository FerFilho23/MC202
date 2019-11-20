char comando[15];

int num_vert, origem, aresta[2];

typedef struct vertice
{
    int vertice;
    int visitado; //FALSE
    int d;
    int pi;

} vertice;

vertice *V, *E;

vertice* construir_vertices(int num_ver, vertice* V);
vertice *construir_vizinhos(int num_vert, vertice *E);
void inserir_vizinhos(int aresta[], int num_vert, vertice **V, vertice **E);
