char comando[15];

int num_vert, origem, aresta[2];

typedef struct vertice
{

    int visitado; //FALSE
    int d;
    struct vertice* pi;

} vertice;

vertice *V, *E;

vertice* construir_vertices(int num_ver, vertice* V);
void inserir_vizinhos(int aresta[], vertice** V, vertice** E);
