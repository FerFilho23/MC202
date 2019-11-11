#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"
#define LEFT(i) (2*i)
#define RIGHT(i) (LEFT(i)+1)

void FREE(heap *H){
   free(H->array);
   free(H);
   return;
}   //FREE

void construir_heap(heap **H, int size)
{
    scanf(" %d", &size); //Ler o tamanho do array

    H = malloc(sizeof(heap *));
    H->array = malloc(sizeof(int) * (1 + size));
    H->heap_size = 0;
    H->array_size = size;

    for (int i = 1; i <= H->array_size; i++)    //Inserir os elementos no array
    {
        scanf("%d", &H->array[i]);
        H->heap_size++;
    }
    for (int i = size/2; i > 0; i--)
    {
        MAXheapify(H, i);
    }
    
    

    return;
}

void MAXheapify(heap **H, int pai){

    int L, R;
    int largest = pai;
    L = LEFT(pai);
    R = RIGHT(pai);

    if (L <= H->heap_size && H->array[L] > H->array[largest]) //Se o filho da ESQUERDA estiver dentro do escopo do heap e for maior que o pai 
    {
        largest = L;
    }
    if (R <= H->heap_size && H->array[R] > H->array[largest]) // Se o filho da DIREITA "  "  " "
    {
        largest = R;
    }
    if (largest != pai)   //Se o maior nao for o pai
    {
        troca(H, pai, largest);
        MAXheapify(H, largest);
    }

    return;
}

void print_array(heap *H){
    for (int i = 1; i < H->array_size; i++)
    {
        printf("%d ", H->array[i]);
    }
    printf("\n");
}

void troca(heap *H, int i, int j){
    int aux;
    aux = H->array[i];
    H->array[j] = H->array[i];
    H->array[i] = aux;
    return;
}