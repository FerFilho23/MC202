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

    if (!*raiz)
    {
        *raiz = new;
        printf("inserir raiz\n");
        return;
    }

    folha *atual = *raiz;
    while (atual)
    {
        if (new->key > atual->key)
        {
            atual = atual->E;
        }
        else
        {
            atual = atual->D;
        }
    }

    atual = new;
    printf("inserir folha\n");
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
    if (chave > raiz->key){
        printf("Entrou na E\n");
        buscar(raiz->E, chave); //Recursão
    }else{
        printf("Entrou na D\n");
        buscar(raiz->D, chave);
    }   
}

void PosOrdem(folha **raiz)
{
    printf("ENTROU EM POS-ORDEM\n");
} //POS-ORDEM

void EmOrdem(folha **raiz)
{
    printf("ENTROU EM EM-ORDEM\n");
} //EM-ORDEM

void PreOrdem(folha **raiz)
{
    printf("ENTROU EM PRE-ORDEM\n");
} //PRE-ORDEM

void Largura(folha **raiz)
{
    printf("ENTROU EM LARGURA\n");
} //LARGURA