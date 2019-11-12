#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"
#define LEFT(i) (2*i)
#define RIGHT(i) (LEFT(i)+1)
#define DEBUG


heap* construir_heap(heap *H, int size)
{

    scanf(" %d", &size); //Ler o tamanho do array

    H = malloc(sizeof(heap *));
    if(!H) return H;

    H->array = malloc(sizeof(int) * (1 + size));
    if(!H->array) return H;

    H->heap_size = size;
    H->array_size = size;

    for (int i = 1; i <= H->array_size; i++)    //Inserir os elementos no array
    {
        scanf("%d", &H->array[i]);
    }

    for (int i = size/2; i > 0; i--)    //Transformar o array em um heap
    {
       H = MAXheapify(H, i);
    }
    
    return  H;
}

heap* MAXheapify(heap *H, int pai){

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
        H = troca(H, pai, largest);
        H = MAXheapify(H, largest);
    }

    return H;
}

heap* troca(heap *H, int i, int j){
    int aux;
    aux = H->array[j];
    H->array[j] = H->array[i];
    H->array[i] = aux;
    return H;
}

void FREE(heap *H){
   free(H->array);
   free(H);
   return;
}   //FREE

void print_array(heap *H){
    for (int i = 1; i <= H->array_size; i++)
    {
        printf("%d ", H->array[i]); //PRINT ARRAY
    }
    printf("\n");
}