/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 09/10 - BST                =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

//TODO:  Resolver BUG LARGURA

int main()
{
    raiz = NULL;
    aux = NULL;
    aux2 = NULL;

    while (scanf(" %s", comando))
    {
        
        if (strcmp(comando, "terminar") == 0){ 
            FREE(raiz);
            return 0;
        }// TERMINAR / FREE
       

        if (strcmp(comando, "inserir") == 0){ 

            scanf(" %d", &chave);
            inserir(&raiz, chave);

        }// Inserir


        if (strcmp(comando, "buscar") == 0){  
       
            scanf(" %d", &chave);
        
            if (busca(raiz, chave))
            {
                printf("%d pertence\n", chave);

            }else
            {
                printf("%d nao pertence\n", chave);
            }
             
        }// Buscar
        

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
                Largura(raiz); // Largura
                printf("\n");
            }
        }   // LARGURA


        //LAB 10

        if (strcmp(comando, "maximo") == 0){
           
            if (!raiz)
            {
                printf("vazia\n");
            }
            else
            {
                aux = MAX(raiz);
                printf("%d\n", aux->key);
            }
        }   //MAXIMO
        if (strcmp(comando, "minimo") == 0){
            
            if (!raiz)
            {
                printf("vazia\n");
            }
            else
            {
                aux = MIN(raiz);
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
                aux2 = sucessor(aux);
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
                aux2 = predecessor(aux);
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


        if (strcmp(comando, "remover") == 0){
            scanf(" %d", &chave);

            if (busca(raiz, chave))
            {
                raiz = remover(raiz, chave);
            }
        } //REMOVER


        if (strcmp(comando, "buscar-intervalo") == 0){
            
            scanf(" %d %d", &x1, &x2);

            if (!intervalo(raiz, x1, x2, i))
            {
                printf("nenhuma\n");
            }else
            {
                printf("\n");
            }
        } //INTERVALO
    }    
}