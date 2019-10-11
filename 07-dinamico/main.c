/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 07 - Dinamico              =*
*==========================================*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"



int main()
{
    vetor.tamanho = 0;
    vetor.capacidade = 2;    
    
    vetor.array = malloc(vetor.capacidade*sizeof(int));  //Alocar 1 inteiro
    if (!vetor.array) return 0;

    while (scanf(" %s", comando))
    {

        if (strcmp(comando, "exit") == 0)
        { // Quit
            free(vetor.array);
            return 0;
        }

        if (strcmp(comando, "is-empty") == 0)
        { // IS-EMPTY

            isEmpty(vetor);
        }

        if (strcmp(comando, "print-last") == 0)
        { //PRINT-LAST

            printLast(vetor);
        }

        if (strcmp(comando, "remove-last") == 0)
        { //REMOVE-LAST
            removeLast(&vetor);
        }

        if (strcmp(comando, "insert-last") == 0)
        { //INSERT-LAST
            scanf(" %d", &inteiro);
            if (vetor.tamanho == vetor.capacidade)  //ORGANIZAR
            {
                int x, aux_posicao, aux_VET[vetor.tamanho];

                for (int i = 0; i < vetor.capacidade; i++)
                {
                    if (vetor.array[i] == *vetor.inicio)
                    {
                        aux_posicao = i; // Encontrar a posicao do vetor inicio
                        break;
                    }
                }

                for (int i = 0; i < vetor.tamanho; i++) //Copiar o vetor de forma organizada para aux_VET
                {
                    x = vetor.array[aux_posicao];
                    aux_VET[i] = x;
                    if (aux_posicao == vetor.capacidade - 1) //Se aux chegar no final do vetor->array volta-lo pro comeco
                    {
                        aux_posicao = 0;
                    }
                    aux_posicao++;
                }

                for (int i = 0; i < vetor.tamanho; i++)
                {
                    vetor.array[i] = aux_VET[i];
                }

                vetor.inicio = &vetor.array[0];
                vetor.fim = &vetor.array[vetor.tamanho-1];

                // ///DEBUG
                // printf("Organizou:\n");
                // for (int i = 0; i < vetor.capacidade; i++)
                // {
                //     if (vetor.array[i])
                //     {
                //         printf("%d ", vetor.array[i]);
                //     }
                // }
                // printf("\n");
                // ///
            }
            insertLast(&vetor, inteiro);
        }

        if (strcmp(comando, "print-first") == 0)
        { //PRINT-FIRST

            printFirst(vetor);
        }

        if (strcmp(comando, "remove-first") == 0)
        { //REMOVE-FIRST

            removeFirst(&vetor);
        }

        if (strcmp(comando, "insert-first") == 0)
        { //INSERT-FIRST
            scanf(" %d", &inteiro);
            if (vetor.tamanho == vetor.capacidade) //ORGANIZAR
            {
                int x, aux_posicao, aux_VET[vetor.tamanho];

                for (int i = 0; i < vetor.capacidade; i++)
                {
                    if (vetor.array[i] == *vetor.inicio)
                    {
                        aux_posicao = i; // Encontrar a posicao do vetor inicio
                        break;
                    }
                }

                for (int i = 0; i < vetor.tamanho; i++) //Copiar o vetor de forma organizada para aux_VET
                {
                    x = vetor.array[aux_posicao];
                    aux_VET[i] = x;
                    if (aux_posicao == vetor.capacidade - 1) //Se aux chegar no final do vetor->array volta-lo pro comeco
                    {
                        aux_posicao = 0;
                    }
                    aux_posicao++;
                }

                for (int i = 0; i < vetor.tamanho; i++)
                {
                    vetor.array[i] = aux_VET[i];
                }

                // ///DEBUG
                // printf("Organizou:\n");
                // for (int i = 0; i < vetor.capacidade; i++)
                // {
                //     if (vetor.array[i])
                //     {
                //         printf("%d ", vetor.array[i]);
                //     }
                // }
                // printf("\n");
                // ///
            }
            insertFirst(&vetor, inteiro);   
        }

        // printf("\n");
        // for (int i = 0; i < vetor.capacidade; i++)
        // {
        //     if(vetor.array[i]){
        //         printf("%d ", vetor.array[i]);
        //     }
        // }    
        // printf("\nTamanho: %d \nCapacidade: %d\n", vetor.tamanho, vetor.capacidade);       


    }
}