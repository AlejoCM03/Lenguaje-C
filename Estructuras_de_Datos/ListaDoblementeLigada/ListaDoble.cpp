#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int dato;
	nodo *siguiente;
	nodo *anterior;
} Nodo;


typedef struct{
	Nodo *frente;
	
} ListaD;


Nodo *nuevoNodo(int dato){
	Nodo *unNodo = (Nodo*)malloc(sizeof(Nodo));
	
	unNodo->dato = dato;
	unNodo->siguiente = NULL;
	unNodo->anterior = NULL;
	
	return unNodo;
}


ListaD *crearLista(){
	ListaD *doble = (ListaD*)malloc(sizeof(ListaD));
	
	doble->frente = NULL;
	
	return doble;
}

void insertarInicio(ListaD *doble,int dato){
	Nodo *nuevo = nuevoNodo(dato);
	
	if(doble->frente == NULL){
		doble->frente = nuevo; 
	}
	else{
		nuevo->siguiente = doble->frente;
		doble->frente->anterior = nuevo;
		doble->frente = nuevo;
	}
}


void insertarFinal(ListaD *doble,int dato){
	Nodo *nuevo = nuevoNodo(dato);
	
	if(doble->frente == NULL){
		doble->frente = nuevo;
	}
	else{
		Nodo *temporal = doble->frente;
		
		while(temporal->siguiente != NULL){
			temporal = temporal->siguiente;
		}
		
		temporal->siguiente = nuevo;
		nuevo->anterior = temporal;
	}
}


void eliminar(ListaD *doble, int dato){
	if(doble->frente == NULL){
		printf("La lista esta vacia\n");
		return;
	}

	Nodo *actual = doble->frente;
	Nodo *anterior = NULL;
	int encontrado = 0;

	do{
		if(actual->dato == dato){
			encontrado = 1;
			break;
		}
		anterior = actual;
		actual = actual->siguiente;
	}while(actual != doble->frente);

	if(encontrado){
		if(actual == doble->frente){
			if(actual->siguiente == doble->frente){
				free(actual);
				doble->frente = NULL;
			}else{
				Nodo *ultimo = doble->frente->anterior;
				doble->frente = doble->frente->siguiente;
				ultimo->siguiente = doble->frente;
				doble->frente->anterior = ultimo;
				free(actual);
			}
		}else{
			anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = anterior;
			free(actual);
		}
	}else{
		printf("El dato no se encuentra en la lista\n");
	}

}


void buscar(ListaD *doble, int dato){
	if(doble == NULL){
		printf("Lista vacia\n");
	}
	Nodo *indice = doble->frente;
	int encontrado = 0;
	
	while(indice != NULL || encontrado != 1){
		if(indice->dato == dato){
			printf("El dato: %d se encuentra en la lista\n", indice->dato);
			encontrado = 1;
		}
		indice = indice->siguiente;
	}
	
	if(encontrado == 0){
		printf("El dato: %d no se encuentra en la lista\n", dato);
	}
}


void mostrar(ListaD *doble){
	if(doble->frente == NULL){
		printf("Lista Vacia\n");
	}
	
	Nodo* indice = doble->frente;
	
	while(indice != NULL){
		printf("|%d| ", indice->dato);
		indice = indice->siguiente;
	}
}


int main(){
	
	ListaD *listaDoble = crearLista();
	int op, dato;
	
	do{
		printf("\nInsertar al Frente(1)\tInsertar al Final(2)\tEliminar(3)\nMostar(4)\t");
		printf("Buscar(5)\tSalir(6)\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("Dame el dato a ingresar: ");
				scanf("%d", &dato);
				insertarInicio(listaDoble, dato);
				break;
				
			case 2:
				printf("Dame el dato a ingresar: ");
				scanf("%d", &dato);
				insertarInicio(listaDoble, dato);
				break;
				
			case 3:
				printf("Dame el dato a eliminar: ");
				scanf("%d", &dato);
				eliminar(listaDoble, dato);
				break;
				
			case 4:
				printf("Elementos de la lista: \n");
				mostrar(listaDoble);
				printf("\n");
				break;
				
			case 5:
				printf("Dame el dato a buscar: \n");
				scanf("%d", &dato);
				buscar(listaDoble, dato);
				break;
				
			case 6:
				printf("Saliendo...\n");
				break;
				
			default:
				printf("Opcion invalida\n");
				break;
		}
	}while(op>0 && op<6);
	
	return 0;
	
}

