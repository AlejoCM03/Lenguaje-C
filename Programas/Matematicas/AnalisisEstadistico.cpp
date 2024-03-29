
#include <stdio.h>
#include<stdlib.h>

int main()
{
    
    int arr[50] = {0, 45, 65, 80, 85, 80, 20, 45, 17, 73, 35, 59, 57, 45, 10, 67, 65, 42, 10, 40, 65,48, 15, 65, 52, 75, 35, 100, 57, 65, 45, 57, 42, 48, 70, 35, 35, 42, 25, 38, 25, 80, 85, 100, 28, 25, 65, 85, 25, 35};
    
    int inter1[16], inter2[16], inter3[16], inter4[16], inter5[16];
    
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;
    
    for(int i = 0; i<50; i++){
        
        if(arr[i] >= -0.1 && arr[i] <= 19.94){
            inter1[cont1] = arr[i];
            cont1 ++;
        }
        else if(arr[i] >= 19.94 && arr[i] <= 39.98){
            inter2[cont2] = arr[i];
            cont2 ++;
        }
        else if(arr[i] >= 39.98 && arr[i] <= 60.02){
            inter3[cont3] = arr[i];
            cont3 ++;
        }
        else if(arr[i] >= 60.02 && arr[i] <= 80.06){
            inter4[cont4] = arr[i];
            cont4 ++;
        }
        else if(arr[i] >= 80.06 && arr[i] <= 100.1){
            inter5[cont5] = arr[i];
            cont5 ++;
        }
        
    }
    
    
    printf("\nIntervalo 1\n");
    int sum1 = 0;
    for(int i = 0; i<cont1; i++){
        printf("%d  ", inter1[i]);
        sum1 += inter1[i];
    }
    printf("\n Marca: %d\n", (sum1/cont1));

	int sum2 = 0;
    printf("\nIntervalo 2\n");
	    for(int i = 0; i<cont2; i++){
        printf("%d  ", inter2[i]);
        sum2 += inter2[i];
	}
	printf("\n Marca: %d\n", (sum2/cont2));
	
	int sum3 = 0;
	printf("\nIntervalo 3\n");
	for(int i = 0; i<cont3; i++){
        printf("%d  ", inter3[i]);
        sum3 += inter3[i];
    }
    printf("\n Marca: %d\n", (sum3/cont3));
 
 	int sum4 = 0;
    printf("\nIntervalo 4\n");
    for(int i = 0; i<cont4; i++){
        printf("%d  ", inter4[i]);
    	sum4 += inter4[i];
	}
	printf("\n Marca: %d\n", (sum4/cont4));

	int sum5 = 0;
    printf("\nIntervalo 5\n");
    for(int i = 0; i<cont5; i++){
        printf("%d  ", inter5[i]);
		sum5 += inter5[i];    
	}
	printf("\n Marca: %d\n", (sum5/cont5));
    
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int repeticiones[n] = {0};
    
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                repeticiones[i]++;
            }
        }
    }
    
    printf("Elemento\tRepeticiones\n");
    for (int i = 0; i < n; i++) {
        if (repeticiones[i] != 0) {
            printf("%d\t%d\n", arr[i], repeticiones[i]);
        }
    }
    
    return 0;
}

