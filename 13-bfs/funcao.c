#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>
#include "declaracoes.h"
// #define DEBUG
#define E_size num_vert *(num_vert - 1)

vertice* construir_vertices(int num_vert, vertice *V){
   #ifdef  DEBUG
    printf("ENTROU NO CONSTRUIR VET V\n");
   #endif

    V = malloc((num_vert + 1)*sizeof(vertice));
    if (!V) return V;

    for (int i = 1; i <= num_vert; i++)
    {
        V[i].number = -1;
        V[i].dist = 0;
        V[i].pi = -1;
        V[i].marked = 0;
    }
    
    return V;
}

vertice* construir_vizinhos(int num_vert, vertice *E){
    #ifdef DEBUG
        printf("ENTROU NO CONSTRUIR VET E\n");
    #endif
    E = malloc(E_size*sizeof(vertice)); //Vetor para os vizinhos de cada vertice. Tamanho no maximo num_vert*(num_vert-1)
    if (!E) return E;

    for (int i = 0; i < E_size; i++)
    {
        E[i].number = -1;
    }
    return E;
}

