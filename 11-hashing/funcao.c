#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "declaracoes.h"
#define DEBUG

long djb2( char *str){
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))    hash = ((hash << 5) + hash) + c; // hash * 32 + hash + c
    

    #ifdef DEBUG
        printf("DJB2: %lu\n", hash);
    #endif

    return hash % MAX_CADEIAS;
}   //Transformar string em num

int h1(int k){

    int h = k % m; //   h(k) = k mod m
    #ifdef DEBUG
        printf("h1(x) = %D\n", h);
    #endif
    

    return h;
} // Funcao hashing 1

int hashingDUPLO(int k, int h1, int i){

    int h2 = 1 + (k %(m - 2));

    int h = (h1 + i*h2) % m;
    
    #ifdef DEBUG
        printf("hashing duplo = %D\n", h);
    #endif

    return h;
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



void inserir(long key_num, char tabela[tabela_size][MAX_CHAR], char cadeia[], int id, int identificadores[])
{
    #ifdef DEBUG
        printf("ENTROU EM INSERIR\n");
    #endif

    if (strcmp(tabela[key_num], cadeia) == 0)   //A mesma chave so pode ser inserida uma vez
    {
        #ifdef  DEBUG
            printf("cadeia ja inserida\n");
        #endif
        return;
    }
    // else if ()       CASO DE COLISOES!!!
    // {
    //     /* code */
    // }

    strcpy(tabela[key_num], cadeia);

    identificadores[key_num] = id;

    #ifdef DEBUG
        printf("cadeia inserida na posicao %ld: %s, com ID = %d\n", key_num, tabela[key_num], identificadores[key_num]);
    #endif

    return;

}   //INSERIR

void remover(char tabela[tabela_size][MAX_CHAR], char cadeia[], int id, int identificadores[])
{
    for (int i = 0; i < 6000; i++)
    {
        if (strcmp(tabela[i], cadeia) == 0)
        {
            identificadores[i] = -1;
            strcpy(tabela[i], "0");
            return;
        }
    }
    return;
}   //REMOVER

