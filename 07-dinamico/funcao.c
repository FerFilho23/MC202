#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

void insertFirst(Vet* vetor, int inteiro){
   
    if (vetor->tamanho == 0)        // Vetor NULO
    {
        vetor->tamanho++;
        vetor->array[0] = inteiro;
        vetor->inicio = &vetor->array[0];
        vetor->fim = vetor->inicio;
        return;
    }

    if(vetor->tamanho == vetor->capacidade){      //Se o vetor encher, DOBRAR sua capacidade total
        // Dobrar capacidade do vetor
    
        int *aux_ptr;
        aux_ptr = realloc(vetor->array, sizeof(vetor->array) * 2);
        if (aux_ptr == NULL)
            return;
        vetor->array = aux_ptr;
        vetor->capacidade = vetor->capacidade * 2;
    } 

    for (int i = 0; i < vetor->capacidade; i++)    //Procurar a posicao do elemento inicial e adicionar o novo elemento inicial na posicao anterior 
    {


        if (vetor->array[i]== *vetor->inicio)
        {
            if(i == 0){           //Se a primeira posiçao for a do elemento inicial, a ultima posicao sera a do novo inicial 

                vetor->array[vetor->capacidade-1] = inteiro;
                vetor->inicio = &vetor->array[vetor->capacidade-1];
                vetor->tamanho++;
                return; 
            }
            vetor->array[i-1] = inteiro;
            vetor->inicio = &vetor->array[i-1];
            vetor->tamanho++;
            return;
        }
        


    } 




}
void insertLast(Vet* vetor, int inteiro){

    if (vetor->tamanho == 0)        // Vetor NULO
    {
        vetor->tamanho++;
        vetor->array[0] = inteiro;
        vetor->fim = &vetor->array[0];
        vetor->inicio = vetor->fim;
        return;
    }
    

    if(vetor->tamanho == vetor->capacidade){      //Se o vetor encher, DOBRAR sua capacidade total
        // Dobrar capacidade do vetor
        int *aux_ptr;
        aux_ptr = realloc(vetor->array, sizeof(vetor->array) * 2);
        if (aux_ptr == NULL)
            return;
        vetor->array = aux_ptr;
        vetor->capacidade = vetor->capacidade * 2;
    } 
    


    for (int i = 0; i < vetor->capacidade; i++)    //Procurar a posicao do elemento final e adicionar o novo elemento final na posicao seguinte 
    {


        if (vetor->array[i]== *vetor->fim)
        {
            if(i == vetor->capacidade-1){           //Se a ultima posiçao for a do elemento final, a primeira posicao sera a do novo final 

                vetor->array[0] = inteiro;
                vetor->fim = &vetor->array[0];
                vetor->tamanho++;
                return; 
            }
            vetor->array[i+1] = inteiro;
            vetor->fim = &vetor->array[i+1];
            vetor->tamanho++;
            return;
        }
        


    }
}
int isEmpty(Vet vetor){

    if(vetor.tamanho == 0){
        printf("yes\n");
        return 1;
    } else{
        printf("no\n");
        return 0;
    }
    

};

void printFirst(Vet vetor){
    if (vetor.tamanho == 0)
    {
        return ;
    }
    printf("%d\n", *vetor.inicio);
    return;
};
void printLast(Vet vetor){
    if (vetor.tamanho == 0)
    {
        return;
    }

    printf("%d\n", *vetor.fim);
    return;
};

void removeFirst(Vet* vetor){

    if (vetor->tamanho <= 0)
    {
        return;
    }
    
    for (int i = 0; i < vetor->capacidade; i++)    //Procurar a posicao do elemento final, remove-lo e transformar o anterior em final 
        {


            if (vetor->array[i]== *vetor->inicio)
            {
                if(i == vetor->capacidade-1){                             //Se a ultima posiçao for a do elemento inicial, a primeira se tornara a do novo inicial 
                    vetor->inicio = &vetor->array[0];
                    vetor->tamanho--;
                    break;
                }
                vetor->inicio = &vetor->array[i+1];
                vetor->tamanho--;
                break;
            }
    }

    if (4 * vetor->tamanho == vetor->capacidade)
    { //Se o vetor diminuir para 1/4, dividir sua capacidade total
        // Dobrar capacidade do vetor
        int *aux_ptr;
        aux_ptr = realloc(vetor->array, 0.5*sizeof(vetor->array));
        if (aux_ptr == NULL)
            return;
        vetor->array = aux_ptr;
        vetor->capacidade = vetor->capacidade / 2;
    }
    return;

}
void removeLast(Vet* vetor){
    if (vetor->tamanho <= 0)
    {
        return;
    }

    for (int i = 0; i < vetor->capacidade; i++)    //Procurar a posicao do elemento final, remove-lo e transformar o anterior em final 
    {


        if (vetor->array[i]== *vetor->fim)
        {
            if(i == 0){                             //Se a primeira posiçao for a do elemento final, a ultima se tornara a do novo final 
                vetor->fim = &vetor->array[vetor->capacidade-1];
                vetor->tamanho--;
               
                break;    
            }
            vetor->fim = &vetor->array[i-1];
            vetor->tamanho--;
            
            break;
        }
    }

    if (4 * vetor->tamanho == vetor->capacidade)
    { //Se o vetor diminuir para 1/4, dividir sua capacidade total
        // Dobrar capacidade do vetor
        int *aux_ptr;
        aux_ptr = realloc(vetor->array, sizeof(vetor->array) * 0.5);
        if (aux_ptr == NULL)
            return;
        vetor->array = aux_ptr;
        vetor->capacidade = vetor->capacidade / 2;
    }
    return;
}

