#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "declaracoes.h"

#define m 4987
// #define DEBUG

long djb2( char *str){
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))    hash = ((hash << 5) + hash) + c; // hash * 32 + hash + c
    

    #ifdef DEBUG
        printf("DJB2: %lu\n", hash);
    #endif

    return hash % MAX_CADEIAS;
}   //Transformar string em num

int H1(int k){

    int h = k % m; //   h(k) = k mod m
    #ifdef DEBUG
        printf("h1(x) = %D\n", h);
    #endif
    

    return h;
} // Funcao hashing 1

int H2(int k){
    int h2 = 1 + (k %(m - 2));
    
    
    #ifdef DEBUG
        printf("h2 = %D\n", h2);
    #endif

    return h2;
} //Funcao hashing 2

int busca(char cadeia[], char tabela[tabela_size][MAX_CHAR], int identificadores[])
{
    for (int i = 0; i < 6000; i++)
    {
        if (strcmp(tabela[i], cadeia) == 0)
        {
            return identificadores[i];
        } 
    }
    
    
    return -1;
}   //BUSCAR 

int inserir(int h1, int h2, char tabela[tabela_size][MAX_CHAR], char cadeia[], int id, int identificadores[])
{
    #ifdef DEBUG
        printf("ENTROU EM INSERIR\n");
    #endif

    if (busca(cadeia, tabela, identificadores) != -1)   //A mesma chave so pode ser inserida uma vez
    { 
        #ifdef  DEBUG
            printf("cadeia ja inserida\n");
        #endif
       
        return 0;
    }
    else if (strcmp(tabela[h1], "0") != 0) // CASO DE COLISOES!!!
    {
        int i = 1;
        while (1)
        {            
            int h = (h1 + i*h2) % m;    //HASHING DUPLO
            
            if (strcmp(tabela[h], "0") == 0)    //Encontrar uma posicao vazia
            {
                strcpy(tabela[h], cadeia);
                identificadores[h] = id;
               
                return 1;
            }
            i++;    //Aumentar o incremento 
        }
    }
    
    strcpy(tabela[h1], cadeia);

    identificadores[h1] = id;

    #ifdef DEBUG
        printf("cadeia inserida na posicao %d: %s, com ID = %d\n", h1, tabela[h1], identificadores[h1]);
    #endif

    return 1;

}   //INSERIR

void remover(char tabela[tabela_size][MAX_CHAR], char cadeia[], int identificadores[])
{
    for (int i = 0; i < 6000; i++)
    {
        if (strcmp(tabela[i], cadeia) == 0)
        {
            identificadores[i] = -1;    // ID removido = -1  
            strcpy(tabela[i], "0");     // CHAVE removida= "0"
            return;
        }
    }
    return;
}   //REMOVER

