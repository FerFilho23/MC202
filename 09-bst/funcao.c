#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

void FREE(folha *raiz){
    if (!raiz) return;

    FREE(raiz->E);
    FREE(raiz->D);

    free(raiz);

}

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
        if (new->key == filho->key)
        {
            return;
        }
        
        if (new->key > filho->key)
        {
            filho = filho->D;
        }
        else 
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
    if (!raiz) return;

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

void Largura(folha *raiz, folha *atual, folha *aux){
    if (!atual)
    {
        aux = raiz;
        aux->next = NULL;
        atual = aux;
    }

    while (atual){                  //DEQUEUE
        
        folha* p = atual;
        printf("%d ", p->key);
        
        if(p->E) {

            aux->next = p->E; //ENQUEUE
            aux = aux->next;            
        }

        if(p->D)  {

            aux->next = p->D; //ENQUEUE
            aux = aux->next;
        }
       atual = atual->next;
    }

} //LARGURA

void MAX(folha *raiz);
void MIN(folha *raiz);