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

    folha *new = malloc(sizeof(folha)); //Alocar memória 
    if (!new)   return;

    new->key = chave;   
    new->D = NULL;
    new->E = NULL;
    new->pai = NULL;
    folha *atual = *raiz;
    folha *prev = NULL;

    while (atual != NULL)  
    {
        prev = atual;
        if (new->key == atual->key) //IGNORAR chaves iguais 
        {
            return;
        }
        
        if (new->key > atual->key)  //Percorrer a arvore avaliando se a chave new é menor ou maior que os nos ja existentes
        {
           atual = atual->D;
        }
        else 
        {
            atual = atual->E;
        }
    }

    if (!prev)   //Arvore Vazia
    {
        *raiz = new;
    
        return;
    }
    else if (new->key < prev->key)
    {
        prev->E = new;
        prev->E->pai = prev;
    } else{
        prev->D = new;
        prev->D->pai = prev;
    }
    
    return;
}

folha* busca(folha *raiz, int chave)
{
    if (raiz == NULL ||raiz->key == chave)  return raiz;
    
    if (chave > raiz->key) return busca(raiz->D, chave); //Recursão
    else return busca(raiz->E, chave);
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



////// lab 10;

folha* MAX(folha *raiz){
    
    while (raiz->D != NULL) {
        raiz = raiz->D; 
    } 
  
    return raiz; 

}   //MAXIMO

folha* MIN(folha *raiz){
   
    while (raiz->E != NULL) { 
        raiz = raiz->E; 
    } 
  
    return raiz; 
    
}   //MINIMO

folha* sucessor(folha *raiz, folha *atual){

    // Caso atual->D exista, procurar o menor valor da subarvore D
    if (atual->D != NULL) return MIN(atual->D);

    // Se nao ha subarvore D, procurar o pai cujo filho = pai->D
    folha *p = atual->pai;
    while (p != NULL && atual == p->D)
    {
        atual = p;
        p = p->pai;
    }
    return p;
}    //SUCESSOR

folha* predecessor(folha *raiz, folha *atual){

    // Caso atual->E exista, procurar o maior valor da subarvore E
    if (atual->E != NULL)   return MAX(atual->E);

    // Se nao ha subarvore E, procurar o pai cujo filho = pai->E
    folha *p = atual->pai;
    while (p != NULL && atual == p->E)
    {
        atual = p;
        p = p->pai;
    }
    return p;

}   // PREDECESSOR