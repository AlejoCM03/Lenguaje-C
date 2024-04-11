#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int dato;
	nodo *siguiente;
} Nodo;

typedef struct{
	nodo *frente;
	int tam;
} ListaC;

Nodo *nuevoNodo(int dato){
	Nodo* unNodo = (Nodo*)malloc(sizeof(Nodo));
	
	unNodo->dato = dato;
	unNodo->siguiente = NULL;
	
	return unNodo;
}

ListaC *CrearLista(){
	ListaC *circular = (ListaC*)malloc(sizeof(ListaC));
	//inicializacion de las variables
	circular->frente = NULL;
	circular->tam = 0;
	
	return circular;
}

void insertar(ListaC *circular, int dato){
	Nodo *nuevo = nuevoNodo(dato);//crea el nodo a insertar
	
	if(circular->frente == NULL){
		circular->frente = nuevo;
		nuevo->siguiente = nuevo;
	}
	else{
		Nodo *indice = circular->frente;
		
		while(indice->siguiente != circular->frente){
			indice = indice->siguiente;
		}
		
		indice->siguiente = nuevo;
		nuevo->siguiente = circular->frente;
	}
	
	circular->tam++;
}


void eliminar(ListaC *circular, int dato){
	if(circular->frente == NULL){
		printf("La lista esta vacia \n");
	}
	
	Nodo* anterior = NULL;
	Nodo* indice = circular->frente;
	
	while(indice->dato != dato){
		if(indice->siguiente == circular->frente){
			printf("No se encontro el dato en la lista\n");
		}
		anterior = indice;
		indice = indice->siguiente;
	}
	
	if(anterior == NULL){
		if(indice->siguiente == circular->frente){
			circular->frente = NULL;
		}
		else{
			Nodo* final = circular->frente;
			while(final->siguiente != circular->frente){
				final = final->siguiente;
			}
			circular->frente = indice->siguiente;
			final->siguiente = circular->frente;
		}
	}
	else{
		anterior->siguiente = indice->siguiente;
	}
	
	free(indice);
	circular->tam--;
}

void buscar(ListaC *circular, int dato){
	if(circular == NULL){
		printf("Lista vacia\n");
	}
	Nodo *indice = circular->frente;
	int encontrado = 0;
	
	do{
		if(indice->dato == dato){
			printf("El dato: %d se encuentra en la lista\n", indice->dato);
			encontrado = 1;
		}
		indice = indice->siguiente;
	}while(indice != circular->frente || encontrado != 1);
	
	if(encontrado == 0){
		printf("El dato: %d no se encuentra en la lista\n", dato);
	}
}

void mostrar(ListaC *circular){
	if(circular->frente == NULL){
		printf("Lista Vacia\n");
	}
	
	Nodo* indice = circular->frente;
	
	do{
		printf("|%d| ", indice->dato);
		indice = indice->siguiente;
	}while(indice != circular->frente);
}

int main(){
	
	ListaC *listaCircular = CrearLista();
	int op, dato;
	
	do{
		printf("\nInsertar(1)\tEliminar(2)\tMostar(3)\n");
		printf("Buscar(4)\tSalir(5)\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("Dame el dato a ingresar: ");
				scanf("%d", &dato);
				insertar(listaCircular, dato);
				break;
				
			case 2:
				printf("Dame el dato a eliminar: ");
				scanf("%d", &dato);
				eliminar(listaCircular, dato);
				break;
				
			case 3:
				printf("Elementos de la lista: \n");
				mostrar(listaCircular);
				printf("\n");
				break;
				
			case 4:
				printf("Dame el dato a buscar: \n");
				scanf("%d", &dato);
				buscar(listaCircular, dato);
				break;
				
			case 5:
				printf("Saliendo...\n");
				break;
				
			default:
				printf("Opcion invalida\n");
				break;
		}
	}while(op>0 && op<5);
	
	return 0;
	
}
