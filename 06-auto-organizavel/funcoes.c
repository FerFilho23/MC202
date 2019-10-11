#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int createList(int num, node** lista){

    node *new = malloc(sizeof(node));
    node *last = *lista;
    if (!new) return 0;

    new->number = num;
    new->contador = 0;
    new->next = NULL;

    if (*lista == NULL)
    {
        *lista = new;
        return 1;
    }
    
    while (last->next != NULL){
        last = last->next;
    }
    last->next = new;

    return 1;
}

int MTF(int req, node** listaMTF, int N){

    node *head = *listaMTF, *curr = *listaMTF, *prv = NULL;
    if (head->number != req){
    
        for (int i = 1; i <= N; i++)
        {
            

            if (curr->number==req)
            {
                prv->next = curr->next;
                curr->next = head;
                *listaMTF = curr;
                return i;  
            }

            prv = curr;
            curr = curr->next;
            
        }
    }else{
        return 1;
    }
    
    return 0;
}

int TR(int req, node** listaMTF, int N){

    int aux;
    node  *curr = *listaMTF, *prv = NULL;
    if (curr->number != req)
    {

        for (int i = 1; i <= N; i++){

            if (curr->number == req){
                aux  = prv->number;
                prv->number = curr->number;
                curr->number = aux;
                return i;
            }
            
            prv = curr;
            curr = curr->next;
        }
    }
    else
    {
        return 1;
    }

    return 0;
}

int C(int req, node** listaC, int N){
   
    node *head = *listaC, *curr = *listaC, *prv = NULL, *cont_ptr = *listaC;
    if (curr->number != req)
    {

        for (int i = 1; i <= N; i++)
        {

            if (curr->number == req)
            {
                curr->contador++;
                
                if (head->contador <= curr->contador){
                    prv->next = curr->next;
                    curr->next = head;
                    *listaC = curr;
                }else {
                
                    while (cont_ptr->next->contador > curr->contador){
                        cont_ptr = cont_ptr->next;
                    }
                    
                    prv->next = curr->next;
                    curr->next = cont_ptr->next;
                    cont_ptr->next = curr;
                }
                return i;
            }

            prv = curr;
            curr = curr->next;
        }
    }
    else
    {
        curr->contador++;
        return 1;
    }

    return 0;
}
void FREE(node *lista)
{

    node *aux;

    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        free(aux);
    }
    free(lista);
    return;
}