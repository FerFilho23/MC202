#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>
#include "declaracoes.h"
#define DEBUG

vertice* construir_vertices(int num_vert, vertice *V){
   #ifdef  DEBUG
    printf("ENTROU NO CONSTRUIR VET V\n");
   #endif
   
    V = malloc(sizeof(vertice)*(num_vert + 1));
    if (!V) return V;

    for (int i = 1; i <= num_vert; i++)
    {
       V[i].d = 0;
       V[i].pi = -1;
       V[i].visitado = 0;
    }
    
    return V;
}


void inserir_vizinhos(int aresta[], vertice **V, vertice **E)
{   
    #ifdef  DEBUG
        printf("ENTROU EM INSERIR VIZINHOS\n");
    #endif

    return;
}