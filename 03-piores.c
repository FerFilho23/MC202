#include <stdio.h>
#include <string.h>
#include <errno.h>

int busca(char keywords[], char desculpas[]) {

    char *ptr = strstr(keywords, desculpas);

    if (ptr != NULL)                             // Palavra-chave encontrada
    {
        return 1;
    }

    return 0;
}


int main () {

    int KeyWords_num, Desculpas_num, max_pior = 0, num_conjunto = 1;         //Variaveis 
    char piores[100] = {0};           //qnt de palavras-chaves encontradas no índice de cada desculpa

    while (scanf("%d %d", &KeyWords_num, &Desculpas_num) != EOF) // Lendo K e E
    {
        char keywords[KeyWords_num][21], desculpas[Desculpas_num][101];
        
        for (int i = 1; i <= KeyWords_num; i++) {               // Lendo as keywords
        
            scanf(" %[^\n]", &keywords[i][0]);
           // printf("%s\n", keywords[i]);
        }
        
        for (int i = 1; i <= Desculpas_num; i++) {               // Lendo as desculpas

            scanf(" %[^\n]", &desculpas[i][0]);
           // printf("%s\n", desculpas[i]);
        }

        for (int i = 1; i <= Desculpas_num; i++){            //Para cada desculpa, buscar as palavras chaves
            for (int j = 1; j <= KeyWords_num; j++){
                if (busca(keywords[j], desculpas[i])){          //Se a palavra-chave for encontrada, aumentar 1 no indice "i" da desculpa
                
                    piores[i] += 1;
                }
            }
        }

        for (int i = 1; i <= Desculpas_num; i++) {            // Definir a desculpa com maior número de palavras-chaves 
            max_pior = 0;
            
            if(piores[i]>max_pior) {
                max_pior = piores[i];
            }
        }
        

        printf("Conjunto de desculpas #%d\n", num_conjunto);
        
        for (int i = 1; i <= Desculpas_num; i++){             //Imprimir as desculpas com o maior número de palavras-chaves
        
            if (piores[i] == max_pior) {

                printf("%s\n", desculpas[i]);
            }
        }
        
        printf("\n");

        num_conjunto += 1;
    }
}