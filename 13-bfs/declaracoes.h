char comando[15];

int num_vert, origem, aresta[2];

typedef struct{
    int number;
    int marked; //FALSE
    int dist;
    int pi;

} vertice;

vertice *V, *E;

vertice* construir_vertices(int num_ver, vertice* V);
vertice* construir_vizinhos(int num_vert, vertice *E);
