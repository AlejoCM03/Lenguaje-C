#include<stdio.h>

int main(){
	
	int numero = 400;
	int raiz = 0;
	int acum = 0;
	
	while(acum != numero){
		raiz += 1; 
		acum = raiz*raiz;
	}
	
	printf("La raiz de: %d es: %d", numero, raiz);
}
