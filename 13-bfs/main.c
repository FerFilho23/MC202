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
#define E_size num_vert*(num_vert-1)

/*TODO:
    
    .   Transformar em NAO-ORIENTADO!! 

*/
int QUEUE[CAPACIDADE];
int Qsize = 0;
int fim = CAPACIDADE-1;
int inicio = 0;

int main()
{
    //CONSTRUCAO DOS VET

        scanf(" %d", &num_vert); //Ler o numero de verts do grafo
        
        V = construir_vertices(num_vert, V);    //Vetor para os vertices do grafo
        E = construir_vizinhos(num_vert, E);    //Vetor para as arestas do grafo
       
    
    //
   
    //BFS
        int aux = 0;

        while (scanf("%d,%d", &aresta[0], &aresta[1]))  //Ler as arestas
        {
            if (aresta[0]==0 && aresta[1]==0)
            {
                break;
            }

            for (int i = 0; i <= E_size; i++)
            {
                if (E[i].number == -1)
                {
                    E[i].number = aresta[1];
                    if (V[aresta[0]].number == -1)
                    {
                        V[aresta[0]].number = i;
                    }
                    break;
                }
                
            }
            
            
        }
    
        scanf(" %d", &origem);  //Ler a origem da busca

    ///

    //SAIDAS

        printf("Origem da busca: %d\n", origem);
        printf("Vertices alcancados e distancias:\n");

        #ifdef  DEBUG
            for (int i = 1; i <= num_vert; i++)
            {
                printf("%d ", V[i].number);
            }
            printf("\n");

            for (int i = 0; i < E_size; i++)
            {
                printf("%d ", E[i].number);
            }
            printf("\n");

            for (int j = 1; j <= num_vert ; j++)
            {
            
                printf("Vizinhos de %d: ", j);

                if (V[j].number == -1)
                {
                    printf("\n");
                    continue;
                }
                

                for (int i = V[j].number; i < V[j].number+intervalo_vizinhos(num_vert, V, j); i++)   
                {
                    printf("%d ", E[i].number);
                }
                printf("\n");
            }
        #endif
        
        printf("%d %d\n", origem, V[origem].dist);
        BFS(num_vert, V, E, origem);

        free(V);
        free(E);
    //
}
    

   
