#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>
#include "declaracoes.h"
#define DEBUG
#define E_size num_vert *(num_vert - 1)

vertice* construir_vertices(int num_vert, vertice *V){
   #ifdef  DEBUG
    printf("ENTROU NO CONSTRUIR VET V\n");
   #endif
   
    V = malloc(sizeof(vertice)*(num_vert + 1));
    if (!V) return V;

    for (int i = 1; i <= num_vert; i++)
    {
        V[i].vertice = -1;
        V[i].d = 0;
        V[i].pi = -1;
        V[i].visitado = 0;
    }
    
    return V;
}

vertice* construir_vizinhos(int num_vert, vertice *E){
    #ifdef DEBUG
        printf("ENTROU NO CONSTRUIR VET E\n");
    #endif
    E = malloc(sizeof(vertice) * E_size); //Vetor para os vizinhos de cada vertice. Tamanho no maximo num_vert*(num_vert-1)
    if (!E)
        return V;

    for (int i = 0; i < E_size; i++)
    {
        E[i].vertice = -1;
    }
    return E;
}

void inserir_vizinhos(int aresta[], int num_vert, vertice **V, vertice **E)
{   
    #ifdef  DEBUG
        printf("ENTROU EM INSERIR VIZINHOS\n");
    #endif

    vertice* v = *V;
    vertice* e = *E;

    if (v[aresta[0]].vertice == -1) //Add a primeira aresta de um vertice
    {
        for (int i = 0; i < E_size; i++)
        {
            if (e[i].vertice == -1)
            {
                e[i].vertice = aresta[1];
                v[aresta[0]].vertice = i;
            }
            
        }
        
    } else  // Add uma nova aresta a um vertice
    {
        for (int i = 0; i < E_size; i++)
        {
            if (e[i].vertice == -1)
            {
                e[i].vertice = aresta[1];
            }
        }
    }
    
    V = &v;
    E = &e;


    return;
}