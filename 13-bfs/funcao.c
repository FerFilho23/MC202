#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>
#include "declaracoes.h"
// #define DEBUG
#define E_size num_vert *(num_vert - 1)
#define FALSE  0
#define TRUE  1
#define CAPACIDADE INT_MAX

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
        V[i].marked = FALSE;    //FALSE
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

int intervalo_vizinhos(int num_vert, vertice* V, int origem){    
    //Encontrar o intervelo de indices dos vizinhos de v

    int min = -1;

    for (int i = 1; i <= num_vert; i++) //Percorrer o vetor V e encontrar o menor valor maior que V[v].number
    {
        if (V[i].number > V[origem].number)
        {
            if (min == -1) // Primeiro numero 
            {
                min = V[i].number;
                continue;
            }
            else if(V[i].number<min)
            {
                min = V[i].number;
                continue;
            }
        }
    }

    if (min == -1)
    {
       return 1;
    }
    

    return min-V[origem].number; //intervalo dos vizinhos de v no vet E
}

void ENQUEUE(int data){
    if(size >= CAPACIDADE) return;  //Tamanho superou a capacidade da lista

    fim = (fim+1)%CAPACIDADE; 
    size++;

    QUEUE[fim] = data;
    return;
}

int DEQUEUE(){
    if(!size) return -1;   //Lista vazia

    int data = QUEUE[inicio];

    inicio = (inicio+1)%CAPACIDADE;
    size -= 1;

    return data;
}

void BFS(int num_vert, vertice *V, vertice *E, int origem){





}