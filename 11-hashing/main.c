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

/*TODO:
    - considerar colisões 
    - acertar a questao dos IDs
*/

int main()
{

    while (scanf(" %s", comando))
    {

        if (strcmp(comando, "i") == 0){ 

            scanf(" %s", cadeia);
           
            int aux = djb2(cadeia);
            key_num = h1(aux);
        
            inserir(key_num, tabela, cadeia, id, identificadores);
           
            id++;

        }// Inserir



        if (strcmp(comando, "b") == 0)
        {

            scanf(" %s", cadeia);
           

            if (busca(cadeia, tabela, identificadores) != -1)
            {
                printf("%s encontrada, id %d\n", cadeia, busca(cadeia, tabela, identificadores));
            }else
            {
                printf("%s nao encontrada\n", cadeia);
            }
             
        }// Buscar

        if (strcmp(comando, "r") == 0)
        {
            scanf(" %s", cadeia);

            remover(tabela, cadeia, id, identificadores);
            id = id -1;

        } //REMOVER

        if (strcmp(comando, "f") == 0)
        {
            return 1;
        } //TERMINAR
    }    
}