#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

void FREE(node *head){
    node *prev = NULL;
    while (head != NULL)
    {
         if (head->A == prev)
        {
            prev = head;
            head = head->B;
        }
        else
        {
            prev = head;
            head = head->A;
        };

        free(prev);
    }
    free(head);
    return;
}

void inserir(node** head, double valor, int posicao){
    node *new = malloc(sizeof(node));
    if (!new) return ;
    
    node *atual = *head;
    node *prev = NULL;

    new->data = valor;
    new->B = NULL;
    new->A = NULL;
    

    if (*head == NULL)  // Se a lista estiver vazia 
    {
        *head = new;
        return ;
    }

    if (posicao == 0)   // Colocar o elemento na posicao 0
    {
        new->B = atual;
        if (atual->A == prev)
        {
            atual->A = new;
        }else
        {
            atual->B = new;
        }
        
        *head = new;
        return;
    }
    
    for (int i = 0; i <= posicao; i++)   // Colocar o elemento no final da lista, na sua posicao 
    {
        if (atual->A == prev)
        {
            if (atual->B != NULL)
            {
                prev = atual;
                atual = atual->B;
                
                continue;
            }
            
            atual->B = new;
            new->A = atual;
            return;
        }

        if (atual->B == prev)
        {
            if (atual->A != NULL)
            {
                prev = atual;
                atual = atual->A;
                continue;
            }
            atual->A = new;
            new->B = atual;
            return;
        }
    }

    new->A = prev;// Colocar elemento no meio de dois outros
    new->B = atual;

    if (prev->A != atual){
       prev->B = new;
    }else
    {
        prev->A = new;
    }

    if (atual->A == prev)
    {
       atual->A = new;
       
    }else
    {
        atual->B = new;
    }
}

void print(node** head){
    node* atual = *head;
    node *prev = NULL;

    while(atual != NULL){
        printf("%0.4f ", atual->data);
        
        if(atual->A == prev){
            prev = atual;
            atual = atual->B;
        }else {
            prev = atual;
            atual = atual->A;
        }
    }
    printf("\n");
}

void reverter(node** head, int inicio, int termino){
    node *atual_inicio = *head;
    node *prev_inicio = NULL;

    node *atual_termino = *head;
    node *prev_termino = NULL;

    if (inicio == termino) return;

    for (int i = 0; i < inicio; i++)    // Encontrar atual_inicio e prev_inicio;
    {
        if (atual_inicio->A == prev_inicio)
        {
            if (atual_inicio->B == NULL)
            {
                break;
            }
            prev_inicio = atual_inicio;
            atual_inicio = atual_inicio->B;
        }else{
            if (atual_inicio->A == NULL)
            {
                break;
            }
            prev_inicio = atual_inicio;
            atual_inicio = atual_inicio->A;
        }
    }

    for (int i = 0; i < termino; i++) // Encontrar atual_termino e prev_termino;
    {
        if (atual_termino->A == prev_termino)
        {
            if (atual_termino->B == NULL)
            {
                break;
            }
            prev_termino = atual_termino;
            atual_termino = atual_termino->B;
        }
        else
        {
            if (atual_termino->B == NULL)
            {
                break;
            }
            prev_termino = atual_termino;
            atual_termino = atual_termino->A;
        }
    }
    
    if (prev_inicio)
    {
        if (prev_inicio->A == atual_inicio){ // Movendo o apontador do prev_inicio para o atual_termino
        
            prev_inicio->A = atual_termino;
        }
        if (prev_inicio->B == atual_inicio)
        {
            prev_inicio->B = atual_termino;
        }
    }

    if (atual_inicio->A == prev_inicio) // INICIO->A
    {
        if (atual_termino->B != prev_termino)//TERMINO->B
        {
            if (!atual_termino->B)
            {
                atual_inicio->A = NULL;
                atual_inicio->B = atual_termino;
                atual_termino->B = prev_inicio;

            }else
            {
                atual_inicio->A = atual_termino->B;
            
            
                if (atual_termino->B->A == atual_termino)//TERMINO->B->A
                {
                    atual_termino->B->A = atual_inicio;
                }
                else if (atual_termino->B->B == atual_termino) //TERMINO->B->B
                {
                    atual_termino->B->B = atual_inicio;  //TERMINO->B->B
                }
            }
            atual_termino->B = prev_inicio;
        }
        
        else  if (atual_termino->A != prev_termino)  //TERMINO->A
        {
            if (!atual_termino->A)
            {
                atual_inicio->A = NULL;
                atual_inicio->B = atual_termino;
                atual_termino->A = prev_inicio;

            }else
            {
            
                atual_inicio->A = atual_termino->A;

                if (atual_termino->A->A== atual_termino)//TERMINO->A->A
                {
                    atual_termino->A->A = atual_inicio;
                    
                }
                else if (atual_termino->A->B == atual_termino)//TERMINO->A->B
                {
                    atual_termino->A->B = atual_inicio;
                    
                }
            }
            atual_termino->A = prev_inicio;
        }
    }  

    else  if (atual_inicio->B == prev_inicio)//INICIO->B 
    {
        if (atual_termino->B != prev_termino)   //TERMINO->B
        {   
            if (!atual_termino->B)
            {
                atual_inicio->B = NULL;
                atual_inicio->A = atual_termino;
                atual_termino->B = prev_inicio;
            }else
            {
                atual_inicio->B = atual_termino->B;
                
                if (atual_termino->B->A == atual_termino)//TERMINO->B->A
                {
                    atual_termino->B->A = atual_inicio;
                  
                }
                else  if(atual_termino->B->B == atual_termino) //TERMINO->B->B
                {
                    atual_termino->B->B = atual_inicio;
                    
                }     
            }
            atual_termino->B = prev_inicio;
        }
        else if (atual_termino->A != prev_termino)  //TERMINO->A
        {
            if (!atual_termino->A)
            {
                atual_inicio->A = NULL;
                atual_inicio->B = atual_termino;
            }else
            {
                atual_inicio->B = atual_termino->A;
                if ( atual_termino->A->B == atual_termino)//TERMINO->A->B
                {
                    atual_termino->A->B = atual_inicio;
                }
                else if (atual_termino->A->A == atual_termino) //TERMINO->A->A
                {
                    atual_termino->A->A = atual_inicio;
                }
            }
            atual_termino->A = prev_inicio;
        }
        
    }

    if (inicio == 0)
    {
        *head = atual_termino;
        return;
    }
}