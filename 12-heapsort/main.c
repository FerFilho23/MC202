/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 12 - Heapsort               =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

int main()  //HEAPSORT
{
    heap *H = NULL;

    H = construir_heap(H, size);
    
    H = removeMAX(H);

    print_array(H);
    FREE(H);
    return 1;
}