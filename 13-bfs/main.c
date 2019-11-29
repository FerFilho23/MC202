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
// #define DEBUG
// #define DEBUG2
#define E_size num_vert*(num_vert-1)

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
        while (scanf("%d,%d", &aresta[0], &aresta[1]))  //Ler as arestas
        {   

            if (aresta[0]==0 && aresta[1]==0)
            {
                break;
            }

            ENQUEUE(aresta[0]); //Emprestar a QUEUE para inserir as arestas no grafo de forma a deixa-lo nao-ordenado
            ENQUEUE(aresta[1]);
        }
    
        scanf(" %d", &origem);  //Ler a origem da busca

       ///Inserir arestas em E e suas pos em V - nao-ordenado

        for (int i = 1; i <= num_vert; i++) //Percorrer V[i] - vertices
        {
            if (!Qsize) //Nao ha arestas
            {
               break;
            }
            
            

            // for (int j = 0; j < Qsize; i++) //Percorrer QUEUE[j] - fila para colocar em E
            // {   
            //     if (QUEUE[j] == i)
            //     {
            //         for (int k = 0; k < E_size; k++)  //Percorrer E[k]
            //         {
            //             if (E[k].number == -1)
            //             {                        
            //                 if (j % 2 == 1)
            //                 {
            //                     E[k].number = QUEUE[j-1];                        
            //                 } else
            //                 {
            //                     E[k].number = QUEUE[j+1];
            //                 }
            //                 V[i].number = k;
            //                 break;
            //             }

            //         } 
            //     }
                
            // }
        }
       ///

        #ifdef DEBUG2
            printf("QUEUE: ");
            for (int i = 0; i < Qsize; i++)
            {
                printf("%d ", QUEUE[i]);
            }
            printf("\nQsize: %d\n", Qsize);
        #endif

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
        
        int aux = DEQUEUE();    //Liberar a QUEUE p/ usar no BFS
        while (aux)
        {
           aux = DEQUEUE();
        }
        
        BFS(num_vert, V, E, origem);

        free(V);
        free(E);
    //
}
    

   
