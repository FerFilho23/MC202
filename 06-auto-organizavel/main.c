/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 06 - Auto-organizavel      =*
*==========================================*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "declaracoes.h"

int main()
{
    listaMTF = NULL;
    listaTR = NULL;
    listaC = NULL;



    scanf(" %d", &N);           //READ N & R
    scanf(" %d", &R);

    for (int i = 1; i <= N; i++){    // CREATE LISTS
    
        if (!createList(i, &listaMTF))
        {
            return 0;
        }

        if (!createList(i, &listaTR))
        {
            return 0;
        }

        if (!createList(i, &listaC))
        {
            return 0;
        }
    }

    for (int i = 1; i <= R; i++){

        scanf(" %d", &requisicao[i]);

        custoMTF += MTF(requisicao[i], &listaMTF, N);          //MOVE_TO_FRONT
        custoTR += TR(requisicao[i], &listaTR, N);           //TRANSPOSE
        custoC += C(requisicao[i], &listaC, N);            //COUNT
    }

    FREE(listaMTF);
    FREE(listaTR);
    FREE(listaC);


    printf("%d %d %d\n", custoMTF, custoTR, custoC);

    return 0;
}