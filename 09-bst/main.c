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
    -   REMOVER;
    -   INTERVALO X & Y;
*/

int main()
{
    raiz = NULL;
    aux = NULL;
    while (scanf(" %s", comando))
    {
        
        if (strcmp(comando, "terminar") == 0)
        { // Quit
            FREE(raiz);
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
        
            if (busca(raiz, chave))
            {
                printf("%d pertence\n", chave);

            }else
            {
                printf("%d nao pertence\n", chave);
            }
            
             
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
        }   // POS-ORDEM
        if (strcmp(comando, "pre-ordem") == 0){
            if (!raiz)
            {
                printf("vazia\n");
            }else{
                PreOrdem(raiz); // Pre-ordem
                printf("\n");
            }
        }   //  PRE-ORDEM
        if (strcmp(comando, "em-ordem") == 0){
            if (!raiz)
            {
                printf("vazia\n");
            }else{
                EmOrdem(raiz); // Em-ordem
                printf("\n");
            }
        }   // EM-ORDEM
        if (strcmp(comando, "largura") == 0) {
            if (!raiz)
            {
                printf("vazia\n");
            }else{
                Largura(raiz, atual, aux); // Largura
                printf("\n");
            }
        }   // LARGURA




        if (strcmp(comando, "maximo") == 0){
            aux = MAX(raiz);
            if (!raiz)
            {
                printf("vazia\n");
            }
            else
            {
               printf("%d\n", aux->key);
            }
        }   //MAXIMO
        if (strcmp(comando, "minimo") == 0){
            aux = MIN(raiz);
            if (!raiz)
            {
                printf("vazia\n");
            }
            else
            {
               printf("%d\n", aux->key);
            }
        }   //MINIMO
        if (strcmp(comando, "sucessor") == 0){
            scanf(" %d", &chave);
            aux = busca(raiz, chave);
            
            if (!aux)
            {
                printf("nao ha\n");
            }
            else
            {
                aux2 = sucessor(raiz,aux);
                if (aux2)
                {
                    printf("%d\n", aux2->key); 
                }else
                {
                    printf("nao ha\n");
                }
            }

        } //SUCESSOR

        if (strcmp(comando, "predecessor") == 0){
            scanf(" %d", &chave);
            aux = busca(raiz, chave);

            if (!aux)
            {
                printf("nao ha\n");
            }
            else
            {
                aux2 = predecessor(raiz, aux);
                if (aux2)
                {
                    printf("%d\n", aux2->key);
                }
                else
                {
                    printf("nao ha\n");
                }
            }    
        } //PREDECESSOR
    }
}