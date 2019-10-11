/*=========================================*
*= Fernando dos R. S. Filho - RA: 256453  =*
*= MC202 - Turma A                        =*
*= Laboratorio 05 -                       =*
*==========================================*/



#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    double n = 0, elementos = 0;
    
    scanf(" %lf", &n);

    elementos = (n*n+n)/2;

    double media = 0, DP = 0, **matriz, soma_media = 0, soma_DP = 0, vari = 0;

    /////// Construindo a matriz

        matriz = malloc(n * sizeof(double *)); // Alocacao de memoria para a primeira dimensao
        if (!matriz){
            return 0;
        }

        
        for (int i = 0; i < n; i++)             // Alocacao de memoria para as seguintes dimensoes 
        {
            matriz[i] = malloc((n+1) * sizeof(double)); // forma de uma matriz triangular inferior: matriz[n][n+1]
            
            if (!matriz[i])
            {
                while (i)
                    free(matriz[--i]);
                free(matriz);
                return 0;
            }
        }

    /////// Lendo as entradas para a matriz 

        for (int i = 0; i < n; i++)          
        {
            for (int j = 0; j < (i+1); j++)
            {
            
                scanf("%lf", &matriz[i][j]);

             }
        }
        
    

    /////// Calulando MEDIA e DESVIO PADRAO 

         for (int i = 0; i < n; i++)        
        {
            for (int j = 0; j < (i+1); j++)
            {
               soma_media += matriz[i][j]; 
            }
        }                  

       
        media = soma_media/elementos;
            
       for (int i = 0; i < n; i++)        
        {
            for (int j = 0; j < (i+1); j++)
            {
                soma_DP += ((matriz[i][j] - media) * (matriz[i][j] - media)); // DP
 
            }
           
        } 
        
        vari = soma_DP/elementos; // n é o tamanho do vetor  
        DP = sqrt(vari);

    /////// Printando a matriz com as devidas alteracoes 

        for (int i = 0; i < n; i++)        
        {
            for (int j = 0; j < (i+1); j++)
            {
                matriz[i][j] = (matriz[i][j]-media)/DP;
                printf("%.12lf ",matriz[i][j]);
            }
            printf("\n");
            free(matriz[i]);
        }
    
        free(matriz);

        printf("\n%0.12lf %0.12lf \n", media, DP);
}