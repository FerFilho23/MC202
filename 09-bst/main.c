/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 09 - BST                   =*
*==========================================*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

/* TODO: 
    - Funcao inserir;
    -   "    buscar;
    -   funcoes -> pos- pre- em-ordem e largura;
*/

int main()
{
    raiz = NULL;

    while (scanf(" %s", comando))
    {
        if (strcmp(comando, "terminar") == 0)   //Terminar
        { 
            // FREE(raiz);
            return 0;
        }
        
        if (strcmp(comando, "inserir") == 0)    // Inserir
        { 
            scanf(" %d", &valor);
            inserir(&raiz, valor);
        }

        if (strcmp(comando, "buscar") == 0)     // Buscar
        { 
            scanf(" %d", &valor);
            buscar(&raiz, valor);
        }

        if (strcmp(comando, "pos-ordem") == 0) PosOrdem(&raiz); // Pos-ordem
        
        if (strcmp(comando, "pre-ordem") == 0) PreOrdem(&raiz); // Pre-ordem
        
        if (strcmp(comando, "em-ordem") == 0)  EmOrdem(&raiz); // Em-ordem
        
        if (strcmp(comando, "largura") == 0)   Largura(&raiz); // Largura
    }
}