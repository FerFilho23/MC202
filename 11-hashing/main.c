/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 11 - Hashing               =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "declaracoes.h"
// #define DEBUG


int main()
{
    for (int i = 0; i < tabela_size; i++){
        identificadores[i] = -1; // ID vazio = -1
        strcpy(tabela[i], "0");  // CHAVE vazio= "0"
    } //Inicializar tabela hash e identificadores como vazios

    while (scanf(" %s", comando))
    {
        
        if (strcmp(comando, "i") == 0){ 

            scanf(" %s", cadeia);
           
            int k = djb2(cadeia);
            h1 = H1(k);
            h2 = H2(k);
        
            if (inserir(h1, h2, tabela, cadeia, id, identificadores)){
                id++;
            }
    
            #ifdef DEBUG
                printf("id novo: %d\n", id);
            #endif
        }// Inserir

        if (strcmp(comando, "b") == 0){

            scanf(" %s", cadeia);
           

            if (busca(cadeia, tabela, identificadores) != -1)
            {
                printf("%s encontrada, id %d\n", cadeia, busca(cadeia, tabela, identificadores));
            }else
            {
                printf("%s nao encontrada\n", cadeia);
            }
             
        }// Buscar

        if (strcmp(comando, "r") == 0){
            scanf(" %s", cadeia);

            remover(tabela, cadeia, identificadores);

        } //REMOVER

        if (strcmp(comando, "f") == 0){
            return 1;
        } //TERMINAR






        // for(int i = 0; i < tabela_size; i++){
        //     printf("%s ", tabela[i]);
        // }
        // printf("\n");
    }    
}