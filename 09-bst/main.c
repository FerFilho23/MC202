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

    - Criar a estrutura da arvore (funcoes.c declaracoes.h);
    - Funcao inserir;
    -   "    buscar;
    -   funcoes -> pos- pre- em-ordem e largura;


*/
int main()
{
    head = NULL; 

    while (scanf(" %s", comando))
    {
        if (strcmp(comando, "terminar") == 0)   //Terminar
        { 
            // FREE(head);
            return 0;
        }
        
        if (strcmp(comando, "inserir") == 0)    // Inserir
        { 

            scanf(" %d", &valor);
            // inserir(valor);
            printf("INSERIR: %d\n", valor);
        }

        if (strcmp(comando, "buscar") == 0)     // Buscar
        { 
            scanf(" %d", &valor);
            // buscar(valor);
            printf("BUSCAR: %d\n", valor);
        }

        if (strcmp(comando, "pos-ordem") == 0)  // Pos-ordem
        { 
            // PosOrdem();
            printf("ENTROU EM POS-ORDEM\n");
        }
        
        if (strcmp(comando, "pre-ordem") == 0) // Pre-ordem
        {
            // PreOrdem();
            printf("ENTROU EM PRE-ORDEM\n");
        }
        
        if (strcmp(comando, "em-ordem") == 0) // Em-ordem
        {
            // EmOrdem();
            printf("ENTROU EM EM-ORDEM\n");
        }

        if (strcmp(comando, "largura") == 0) // Largura
        {
            // Largura();
            printf("ENTROU EM LARGURA\n");
        }
    }
}