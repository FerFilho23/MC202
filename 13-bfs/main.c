/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 13 - BSF                   =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "declaracoes.h"
#define DEBUG

/*TODO:

    . BFS
        -   corpo da funcao
        -   EQUEUE   
        -   DEQUEUE
        -   print-path
    .
*/
int main()
{
    //CONSTRUCAO DOS VET

        scanf(" %d", &num_vert); //Ler o numero de vert do grafo
        
        V = construir_vertices(num_vert, V);    //Vetor para os vertices do grafo
        E = malloc(sizeof(vertice)*(num_vert*(num_vert-1))); //Vetor para os vizinhos de cada vertice. Tamanho no maximo num_vert*(num_vert-1)
        if(!E) return 1;
    
    //
   
    //BFS
        while (scanf("%d,%d", &aresta[0], &aresta[1]))  //Ler as arestas
        {
            if (aresta[0]==0 && aresta[1]==0)
            {
                break;
            }
            
            #ifdef DEBUG
                printf("Aresta: %d %d\n", aresta[0], aresta[1]);
            #endif

            inserir_vizinhos(aresta, &V, &E);
        }
    
        scanf(" %d", &origem);  //Ler a origem da busca

    ///

    //SAIDAS

        printf("Origem da busca: %d\n", origem);


        free(V);
        free(E);
    //
}
    

   
