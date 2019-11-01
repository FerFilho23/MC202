#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "declaracoes.h"
#define DEBUG

unsigned long djb2( char *str){
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))    hash = ((hash << 5) + hash) + c; // hash * 32 + hash + c
    

    #ifdef DEBUG
        printf("DJB2: %lu\n", hash);
    #endif

    return hash % MAX_CADEIAS;
}   //Transformar string em num


int h1(int k){

    

    int h = k % 4987; //   h(k) = k mod m
    #ifdef DEBUG
        printf("h1(x) = %D\n", h);
    #endif
    

    return h;
} // Funcao hashing 1



void FREE(){
   
}   //FREE


void inserir(){

   
}   //INSERIR


void busca(){
    
}   //BUSCAR




void remover (){

}   //REMOVER

