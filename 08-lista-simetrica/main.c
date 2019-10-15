/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 07 - Dinamico              =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

// TODO: Implementar a funcao REVERTER

int main()
{
    head = NULL; 

    while (scanf(" %s", comando))
    {
        if (strcmp(comando, "t") == 0)
        { // Quit
            FREE(head);
            return 0;
        }
        
        if (strcmp(comando, "i") == 0)
        { // Inserir

            scanf(" %d %lf", &posicao, &valor);
            inserir(&head, valor, posicao);

        }

        if (strcmp(comando, "v") == 0)  ///Terminar
        { // Reverter
            scanf(" %d %d", &inicio, &termino);
            reverter(&head, inicio, termino);

            if (inicio == 0)
            {
                reverter(&head, inicio, termino);
            }
            
        }

        if (strcmp(comando, "p") == 0)
        { // Print
            print(&head);
        }
    }
}