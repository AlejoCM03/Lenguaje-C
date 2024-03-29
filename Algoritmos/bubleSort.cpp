
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int lista[10];
    
    for(int i=0; i<10; i++){
        lista[i] = rand()%100; //numeros aleatorios
    }
    
    for(int i=0; i<10; i++){
        printf("%d  ", lista[i]);
    }
    
    for(int i=0; i<10; i++){
      
        int aux;
        
        for(int j=0; j<9; j++){
        	
            if(lista[j] > lista[j+1]){
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
    
    printf("\n\n");
    
    for(int i=0; i<10; i++){
        printf("%d  ", lista[i]);
    }
    
    return 0;
}

