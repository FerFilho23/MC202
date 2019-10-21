/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 09/10 - BST                =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"


/* TODO:
    -   MAX & MIN;
    -   SUCESSOR & PREDECESSOR;
    -   REMOVER;
    -   INTERVALO X & Y;
*/

int main()
{
    raiz = NULL;
    atual = NULL;
    aux = NULL;
    while (scanf(" %s", comando))
    {
        
        if (strcmp(comando, "terminar") == 0)
        { // Quit
            // FREE(head);
            return 0;
        }
        
        if (strcmp(comando, "inserir") == 0)
        { // Inserir

            scanf(" %d", &chave);
            inserir(&raiz, chave);

        }

        if (strcmp(comando, "buscar") == 0)  
        { // Buscar
            scanf(" %d", &chave);
            buscar(raiz, chave);
        }

        if (strcmp(comando, "pos-ordem") == 0){
            if (!raiz)
            {
                printf("vazia\n");
            }else
            {
                PosOrdem(raiz); // Pos-ordem
                printf("\n");
            }
        }
        if (strcmp(comando, "pre-ordem") == 0){
            if (!raiz)
            {
                printf("vazia\n");
            }else{
                PreOrdem(raiz); // Pre-ordem
                printf("\n");
            }
        }
        if (strcmp(comando, "em-ordem") == 0){
            if (!raiz)
            {
                printf("vazia\n");
            }else{
                EmOrdem(raiz); // Em-ordem
                printf("\n");
            }
        }

        if (strcmp(comando, "largura") == 0) {
            if (!raiz)
            {
                printf("vazia\n");
            }else{
                Largura(raiz, atual, aux); // Largura
                printf("\n");
            }
        }

        if (strcmp(comando, "maximo") == 0)
        {
            if (!raiz)
            {
                printf("vazia\n");
            }
            else
            {
                MAX(raiz); // Largura
                printf("\n");
            }
        }
       
        if (strcmp(comando, "minimo") == 0)
        {
            if (!raiz)
            {
                printf("vazia\n");
            }
            else
            {
                MIN(raiz); // Largura
                printf("\n");
            }
        }
    }
}