#include<stdio.h>
#include<stdlib.h>

//nodo de la cola doble
typedef struct nodo{
	int dato; 
	nodo *siguiente;//apuntador al elemento siguiente
	nodo *anterior;//apuntador al elemento anterior
}Nodo;

//cola doble
typedef struct{
	nodo *frente;//Apuntador cabecera
	nodo *final;//Apuntador trasero
	
} ColaD;

//creacion de nodo
Nodo* nuevoNodo(int dato){
	Nodo* UnNodo = (Nodo*)malloc(sizeof(Nodo));
	//Asignacion e inicializacion 
	UnNodo->dato = dato;
	UnNodo->siguiente = NULL;
	UnNodo->anterior = NULL;
	
	return UnNodo;
}

//creacion de cola
ColaD *CrearCola(){
	ColaD *doble = (ColaD*)malloc(sizeof(ColaD));
	//inicializacion de las variables
	doble->frente = NULL;
	doble->final = NULL;
		
	return doble; //retorna un tipo de dato ColaD
}


//funcion para insertar al frente
void insertarFrente(ColaD *doble, int dato){
	
	Nodo *temp = nuevoNodo(dato); //define el nodo a insertar
	
	if(doble->frente == NULL){
		doble->frente = doble->final = temp;
	}
	else{
		
		temp->siguiente = doble->frente;
		doble->frente->anterior = temp;
		doble->frente = temp;
	}
	
}


//funcion para insertar atras
void insertarFinal(ColaD *doble, int dato){
	Nodo *temp = nuevoNodo(dato);//define el nodo a insertat
	if(doble->final == NULL){
		doble->frente = doble->final = temp;
	}
	else{
		temp->anterior = doble->final;
		doble->final->siguiente = temp;
		doble->final = temp;
	}
	
}


void borrarFrente(ColaD *doble){
	if(doble->frente == NULL){
		printf("Cola doble vacia");
	}
	else{
		Nodo* temp = doble->frente;
		if(doble->frente == doble->final){
			doble->final = NULL;
			doble->frente = NULL;
		}
		else{
			
			doble->frente = doble->frente->siguiente;
			doble->frente->anterior = NULL;
		}
		
		printf("Dato eliminado: %d", temp->dato);
		free(temp);
		
	}
}


//funcion para borrar al final
void borrarFinal(ColaD *doble){
	
	if(doble->final == NULL){
		printf("la cola esta vacia");
	}
	else{
		Nodo *temp = doble->final;
		
		if(doble->final == doble->frente){
			doble->frente = NULL;
			doble->final = NULL;
		}
		else{
			doble->final = doble->final->anterior;
			doble->final->siguiente = NULL;
		}
		
		printf("Dato eliminado: %d", temp->dato);
		free(temp);
		
	}
}


void mostrarColaDoble(ColaD *doble){
	Nodo *indice = doble->frente;
	
	while(indice != NULL){
		printf("|%d|  ", indice->dato);
		indice = indice->siguiente;
	}
}



int main(){
	
	// Crear una cola doble
	ColaD *cola = CrearCola();
    // Insertar elementos al frente y al final de la cola doble
 
	int op, dato;
	
	do{
		printf("\n\t\tElige una opcion\n");
		printf("Insertar Frente(1)\tInsertar Final(2)\n");
		printf("Eliminar Frente(3)\tEliminar Final(4)\n");
		printf("Mostrar Elementos(5)\tSalir(6)\n");
		
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Dame el dato a ingresar: ");
				scanf("%d", &dato);
				insertarFrente(cola, dato);
				break;
				
			case 2:
				printf("Dame el dato a ingresar: ");
				scanf("%d", &dato);
				insertarFinal(cola, dato);
				break;
			
			case 3:
				borrarFrente(cola);
				break;
				
			case 4: 
				borrarFinal(cola);
				break;
				
			case 5:
				mostrarColaDoble(cola);
				break;
			
			case 6:
				printf("Saliendo...");
				break;
			
			default:
				printf("Opcion invalida");
				break;
		}
			
	}while(op>0 && op<6);
 
	return 0;
}

