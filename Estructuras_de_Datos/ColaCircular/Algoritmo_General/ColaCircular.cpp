#include<stdio.h>
#include<stdlib.h>

//nodo de la cola circular
typedef struct nodo{
	int dato; 
	nodo *siguiente;//apuntador al elemento siguiente
	nodo *anterior;//apuntador al elemento anterior
}Nodo;

//cola circular
typedef struct{
	nodo *frente;//Apuntador cabecera
	nodo *final;//Apuntador trasero
	int tam;//numero de elementos en la cola doble
} ColaC;

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
ColaC *CrearCola(){
	ColaC *circular = (ColaC*)malloc(sizeof(ColaC));
	//inicializacion de las variables
	circular->frente = NULL;
	circular->final = NULL;
	circular->tam = 0;
	
	return circular; //retorna un tipo de dato ColaC
}


//funcion para insertar al frente
void insertarFrente(ColaC *circular, int dato){
	
	Nodo *temp = nuevoNodo(dato); //define el nodo a insertar
	
	if(circular->frente == NULL){
		circular->frente = circular->final = temp;
	}
	else{
	
		temp->siguiente = circular->frente;
		circular->frente->anterior = temp;
		circular->frente = temp;
	}
	
	circular->tam++; //aumenta el numero de elementos
}


//funcion para insertar atras
void insertarFinal(ColaC *circular, int dato){
	Nodo *temp = nuevoNodo(dato);//define el nodo a insertat
	if(circular->final == NULL){
		circular->frente = circular->final = temp;
	}
	else{
		temp->siguiente = circular->final;
		circular->final->siguiente = temp;
		circular->final = temp;
	}
	circular->tam++;//aumenta el numero de elementos
}


//funcion para borrar al final
void borrarFrente(ColaC *circular){
	if(circular->frente == NULL){
		printf("Cola circular vacia");
	}
	else{
		Nodo* temp = circular->frente;
		if(circular->frente == circular->final){
			circular->final = NULL;
			circular->frente = NULL;
		}
		else{
			
			circular->frente = circular->frente->siguiente;
		}
		
		printf("Dato eliminado: %d", temp->dato);
		free(temp);
		circular->tam--;//disminuye el numero de elementos
	}
}


//funcion para borrar al final
void borrarFinal(ColaC *circular){
	
	if(circular->final == NULL){
		printf("la cola esta vacia");
	}
	else{
		Nodo *temp = circular->final;
		
		if(circular->final == circular->frente){
			circular->frente = NULL;
			circular->final = NULL;
		}
		else{
			circular->final = circular->final->anterior;
		}
		
		printf("Dato eliminado: %d", temp->dato);
		free(temp);
		circular->tam--;//disminuye el numero de elementos
	}
}

void mostrarColaCircular(ColaC *circular){
	Nodo *indice = circular->frente;
	
	for(int i=0; i<circular->tam; i++){
		printf("|%d| ", indice->dato);
		indice = indice->siguiente;
	}
	
}

int main(){
	
	// Crear una cola doble
	ColaC *cola = CrearCola();
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
				mostrarColaCircular(cola);
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








