//ejercicio nivel basico

#include<stdio.h>

typedef struct{
	
	char nombre[20];
	long numCel;
	char correo[20];
		
}Contacto;


int main(){
	
	int numContact; //define el numero de contactos
	printf("Dame el numero de contactos a agendar: ");
	scanf("%d", &numContact);
	
	Contacto contacto[numContact];
	printf("\n");
	
	for(int i=0; i<numContact; i++){
		printf("Dame el nombre: ");
		scanf("%s", contacto[i].nombre);//ingresa el nombre
		
		printf("Dame su numero de telefono: ");
		scanf("%ld", &contacto[i].numCel);//ingresa el telefono
		
		printf("Dame el correo electronico: ");
		scanf("%s", contacto[i].correo);//ingresa el correo
		printf("\n");
	}
	
	printf("\n");
	for(int i=0; i<numContact; i++){ //imprime la agenda
		printf("Nombre: %s\n", contacto[i].nombre);
		printf("Telefono: %ld\n", contacto[i].numCel);
		printf("Correo electronico: %s\n",contacto[i].correo);
		printf("\n");
	}
	
	
	
}


