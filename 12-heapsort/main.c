/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 12 - Heapsort               =*
*==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

/*TODO:
    -       arrumar a mutabilidade 
    -   implementar o heapsort
*/
int main()  //HEAPSORT
{
    heap *H;

    construir_heap(H, size);
    // for (int i = H->array_size; i < 2; i++)
    // {
    //     removeMAX(H, 1, i);
    //     // MAXheapify(H, );
    // }

    print_array(H);
    // FREE(H);
    return 1;
}