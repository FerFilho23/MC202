#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

// void FREE(folha *raiz){

// }

void inserir(folha **raiz, int chave)
{
    // printf("INSERIR: %d\n", chave);

    folha *new = malloc(sizeof(folha));
    if (!new)   return;

    new->key = chave;
    new->D = NULL;
    new->E = NULL;

    folha *filho = *raiz;
    folha *pai = NULL;

    while (filho != NULL)
    {
        pai = filho;
        if (new->key > filho->key)
        {
            filho = filho->D;
        }
        else if (new->key < filho->key)
        {
            filho = filho->E;
        }
    }

    if (!pai)
    {
        *raiz = new;
        return;
    }
    else if (new->key < pai->key)
    {
        pai->E = new;
    } else{
        pai->D = new;
    }
    
    return;
}

void buscar(folha *raiz, int chave)
{
    // printf("BUSCAR: %d\n", chave);
    if (raiz == NULL)
    {
        printf("%d nao pertence\n", chave);
        return;
    }

    if (raiz->key == chave)
    {
        printf("%d pertence\n", chave);
        return;
    }
    if (chave > raiz->key) buscar(raiz->D, chave); //Recursão
    else buscar(raiz->E, chave);
       
}

void PosOrdem(folha *raiz)
{
    if (!raiz) return;

    PosOrdem(raiz->E);

    PosOrdem(raiz->D);

    printf("%d ", raiz->key);
} //POS-ORDEM

void EmOrdem(folha *raiz)
{
    if (!raiz){ return;}

    EmOrdem(raiz->E);
    printf("%d ", raiz->key);
    EmOrdem(raiz->D);

} //EM-ORDEM

void PreOrdem(folha *raiz)
{
    if (!raiz) return; 
    printf("%d ", raiz->key);
    PreOrdem(raiz->E); 
    PreOrdem(raiz->D); 
} //PRE-ORDEM

void Largura(folha *raiz, queue** lista)
{
    printf("ENTROU EM LARGURA\n");
    
    Enqueue(raiz, lista);
    
    while (lista){


    }

} //LARGURA