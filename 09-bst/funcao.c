#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

void FREE(folha *raiz){



}

void inserir(folha **raiz, int valor){
    printf("INSERIR: %d\n", valor);
}

void buscar(folha **raiz, int valor){
    folha *atual = *raiz;
    folha *prev = NULL;

    printf("BUSCAR: %d\n", valor);
}

void PosOrdem(folha **raiz){
    printf("ENTROU EM POS-ORDEM\n");
} //POS-ORDEM


void EmOrdem(folha **raiz){
    printf("ENTROU EM EM-ORDEM\n");
}  //EM-ORDEM


void PreOrdem(folha **raiz){
    printf("ENTROU EM PRE-ORDEM\n");
} //PRE-ORDEM


void largura(folha **raiz){
    printf("ENTROU EM LARGURA-ORDEM\n");
}  //LARGURA