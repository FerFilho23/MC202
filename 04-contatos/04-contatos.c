/*==========================================*
 *= Fernando dos R. S. Filho - RA: 256453  =*
 *= MC202 - Turma A                        =*
 *= Laboratorio 04 - Contatos              =*
 *==========================================*/

#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
    int ID;
    char telefone[13];
    char niver[9];
    char nome[51];
    char endereco[101];
} Pessoa;

int insercao(Pessoa contato[], int num_contatos)
{ //Insercao
    
    scanf(" %[^\n]", contato[num_contatos].nome);
    scanf(" %[^\n]", contato[num_contatos].endereco);
    scanf(" %s", contato[num_contatos].telefone);
    scanf(" %s", contato[num_contatos].niver);
    contato[num_contatos].ID = 1;

    printf("Contato para %s inserido.\n", contato[num_contatos].nome);

    return 0;
}

int print(Pessoa contato[], int num_contatos)
{ //Print

    printf("Listagem:\n");

    if (!num_contatos) // Se NÃO tiver contato alocado
    {

        printf("Nenhum contato.\n");
        return 0;

    } else {           // Se tiver contato alocado, printar os contatos de acordo com o número de contatos alocados 

        for (int x = 1; x <= num_contatos; x++) // Imprimir na ordem
        {
            printf("(%d) %s\t%s\t%s\t%s\n", x, contato[x].nome, contato[x].endereco, contato[x].telefone, contato[x].niver);
            
        }
    }

    return 0;
}

int busca(Pessoa contato[], int num_contatos)
{ //Busca
    int busca = 0, cont = 0;
    char nome[51];
    char *ptr;

    scanf(" %[^\n]", nome);
    printf("Resultado da busca:\n");


    for (int x = 1; x <= num_contatos; x++)
    {
        ptr = strstr(contato[x].nome, nome);

        if (ptr) // Analisar o nome a ser buscado
        {           
          
            busca++; // Calcular o num de contatos para imprimir a quebra de linha

        }
    }
        
    if (!busca) // Se NÃO houver a busca de nenhum contato
    {

        printf("Nenhum contato.\n");
    } else {    // Se houver contato 

        for (int x = 1; x <= num_contatos; x++)
        {
            ptr = strstr(contato[x].nome, nome);

            if (ptr) // Analisar o nome a ser buscado
            {
                printf("(%d) %s\t%s\t%s\t%s\n", x, contato[x].nome, contato[x].endereco, contato[x].telefone, contato[x].niver);
                cont++;

                if (busca > 1 && cont< busca) // Imprimir quebra de linha para mais de 1 contato encontrado
                {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}

int remover(Pessoa contato[], int num_contatos)
{ //Remocao

    int removidos = 0;
    char nome[51];

    scanf(" %[^\n]", nome);

    for (int x = 1; x <= num_contatos; x++)
    {

        if (strcmp(contato[x].nome, nome) == 0)
        {
            contato[x].ID = 0; // Marcar a posicao dos contatos removidos para ordenacao 
            removidos++;
        }
    }

    for (int i = num_contatos; i >= 1; i--)
    {
        if (!contato[i].ID){
           
            for (int j = i; j <= num_contatos ; j++)
            {
                contato[j] = contato[j + 1];
            }
        }
    }
    
    
    printf("Contatos de %s removidos: %d.\n", nome, removidos);

    return removidos;
}

int main()
{

    Pessoa contato[1001] = {0};
    char operacao[1];
    int num_contatos = 0;

    while (scanf(" %s", operacao))
    {

        if (strcmp(operacao, "f") == 0)
        { // Quit

            return 0;
        }

        if (strcmp(operacao, "i") == 0)
        { // Insercao

            num_contatos++;
            insercao(contato, num_contatos);
        }

        if (strcmp(operacao, "p") == 0)
        { // Print        

            print(contato, num_contatos);
        }

        if (strcmp(operacao, "r") == 0)
        { // Remocao

            num_contatos = num_contatos - remover(contato, num_contatos);
        }

        if (strcmp(operacao, "b") == 0)
        { // Busca

            busca(contato, num_contatos);
        }

        printf("\n");
    }
}