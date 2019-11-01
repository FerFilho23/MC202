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
#define DEBUG

/*TODO:
    - Escolher entre encadeamento dentro da cadeia e sondagem 
    -   implementar a funcao inserir 
    -    "      "        "   buscar
    -   "       "        "   remover 
    - DAR O FREE!!
*/
int main()
{
    

    while (scanf(" %s", comando))
    {

        if (strcmp(comando, "f") == 0)
        {
            // FREE(/**/);
            return 1;
        }// FREE
       

        if (strcmp(comando, "i") == 0){ 

            scanf(" %s", cadeia);
           

            h1(djb2(cadeia));

            // inserir(&raiz, chave);

        }// Inserir

        if (strcmp(comando, "b") == 0)
        {

            scanf(" %s", cadeia);
           

            // if (busca(raiz, chave))
            // {
            //     printf("%d pertence\n", chave);

            // }else
            // {
            //     printf("%d nao pertence\n", chave);
            // }
             
        }// Buscar

        if (strcmp(comando, "r") == 0)
        {
            scanf(" %s", cadeia);
          

            
        } //REMOVER

    }    
}