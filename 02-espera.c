#include <stdio.h>
#define MAX 10000

float espera_med (float espera[], int N) {

    float sum1 = 0; 
    for (int i = 0; i < N; i++)
    {
        sum1 += espera[i];

    }
    
    return sum1/N;
}



int espera_10 (float espera[], int N) {
    int sum2 = 0;

    for (int i = 0; i < N; i++)
    {
        if (espera[i]>10)
        {
            sum2 += 1;
        }
        
    }
    
    return sum2;

}

int main() {

    int C, N, T, D, aux, caixa = 0, FREE = -1, caixa_livre[MAX] = {0}; // Declaring the variables
    float espera[MAX] = {0};
    scanf ("%d %d", &C, &N); // Reading the number os clerks and clients  
    //printf ("%d %d", C, N);  //DEBUG

    for (int cliente = 0; cliente < N; cliente++){   // i is the clients "ID"
     
        scanf ("%d %d", &T ,&D);
        //printf ("%d %d", T, D);  //DEBUG

        for (int j = 0; j < C; j++) { // FREE clerks !!!
            if (T >= caixa_livre[j]){  
                caixa_livre[j] = T + D; 
                FREE = 1;
                break;
            } 
            FREE = 0;
        }
        
        if (FREE == 0){                         // OCCUPIED clerks!!
            aux = caixa_livre[0];
            for (int k = 0; k < C; k++) {  

                if(caixa_livre[k] <= aux){   // Searching for the lowest waiting time
                    aux = caixa_livre[k];
                    caixa = k;
                } 
                
            }
            
            espera[cliente] = aux - T; //Calculating the waiting time & the clerks' vacancy time
            caixa_livre[caixa] += D;
        }
    }

    printf ("Espera media para %d clientes: %.1f minutos\n", N, espera_med(espera, N));
    printf("Numero de clientes que esperaram mais que 10 minutos: %d\n",espera_10(espera, N));
    

    return 0;

}