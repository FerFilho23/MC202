/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 09 - BST                   =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

/* TODO: 

        - corrigir o bug da funcao inserir/buscar: nao insere folhas;
        - implementar funcoes de: pos- pre- em- ordem e largura;

*/
int main()
{
    raiz = NULL; 

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
            // if(!raiz) printf("NULL\n");
            inserir(&raiz, chave);

        }

        if (strcmp(comando, "buscar") == 0)  
        { // Buscar
            scanf(" %d", &chave);
            // if (!raiz) printf("NULL\n");
            buscar(raiz, chave);
        }

        if (strcmp(comando, "pos-ordem") == 0) PosOrdem(&raiz); // Pos-ordem

        if (strcmp(comando, "pre-ordem") == 0) PreOrdem(&raiz); // Pre-ordem

        if (strcmp(comando, "em-ordem") == 0)  EmOrdem(&raiz); // Em-ordem

        if (strcmp(comando, "largura") == 0)   Largura(&raiz); // Largura
    }
}