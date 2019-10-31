#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"
#define MAX_SIZE 500

void FREE(folha *raiz){
    if (!raiz) return;

    FREE(raiz->E);
    FREE(raiz->D);

    free(raiz);

}   //FREE


void inserir(folha **raiz, int chave){

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
} //INSERIR


folha* busca(folha *raiz, int chave){
    if (raiz == NULL ||raiz->key == chave)  return raiz;
    
    if (chave > raiz->key) return busca(raiz->D, chave); //Recursão
    else return busca(raiz->E, chave);
} //BUSCAR


void PosOrdem(folha *raiz){
    if (!raiz)  return;

    PosOrdem(raiz->E);
    PosOrdem(raiz->D);
    printf("%d ", raiz->key);

} //POS-ORDEM
void EmOrdem(folha *raiz){
    if (!raiz)  return;

    EmOrdem(raiz->E);
    printf("%d ", raiz->key);
    EmOrdem(raiz->D);

} //EM-ORDEM
void PreOrdem(folha *raiz){
    if (!raiz)  return;
    
    printf("%d ", raiz->key);
    PreOrdem(raiz->E); 
    PreOrdem(raiz->D); 

} //PRE-ORDEM

void Largura(folha *raiz){
    int tail, head;

    folha **lista = CriarLista(&head, &tail);   //Array de nos
    folha *aux = raiz;
    
    while (aux)
    {
        
        printf("%d ", aux->key);
        
        if (aux->E) ENQUEUE(lista, &tail, aux->E);   

        if (aux->D) ENQUEUE(lista, &tail, aux->D);
        
        
        aux = DEQUEUE(lista, &head);
    }

    //FREE LISTA

    free(lista);
    return;

} //LARGURA

folha **CriarLista(int *head, int *tail){

    folha **lista = malloc(MAX_SIZE*sizeof(folha*));

    *head = *tail = 0;

    return lista;
}

void ENQUEUE(folha **lista, int *tail, folha *aux)
{

   lista[*tail] = aux;
   (*tail)++;
}       //ENQUEUE


folha *DEQUEUE(folha **lista, int *head){
   
    (*head)++;
    return lista[*head - 1];
}     //DEQUEUE

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


folha* sucessor(folha *atual){

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

folha* predecessor(folha *atual){

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


folha* remover (folha *raiz, int chave){

    //Raiz NULL
    if (raiz == NULL) return raiz;

    //Buscar o no a ser removido
    if (chave < raiz->key) raiz->E = remover(raiz->E, chave);
    else if (chave > raiz->key) raiz->D = remover(raiz->D, chave);

    // Achado o no
    else
    {
        // no com 0 ou 1 filho
        if (raiz->E == NULL)
        {
            folha *aux = raiz->D;
            FREE(raiz);
            return aux;
        }
        else if (raiz->D == NULL)
        {
            folha *aux = raiz->E;
            FREE(raiz);
            return aux;
        }

        // No com 2 filho : usar o sucessor para fazer a substituicao 
        folha *aux = MIN(raiz->D);
        raiz->key = aux->key;

        
        raiz->D = remover(raiz->D, aux->key);
    }

    return raiz;
}


int intervalo(folha *raiz, int x1, int x2, int i){
    if (!raiz){
        return i;
    }

    if (x1 < raiz->key) i = intervalo(raiz->E, x1, x2, i);

    if (raiz->key >= x1 && raiz->key <= x2)
    {
        printf("%d ", raiz->key);  
        i ++;
    }

    if (x2 > raiz->key) i = intervalo(raiz->D, x1, x2, i);
    
    return i;
}



