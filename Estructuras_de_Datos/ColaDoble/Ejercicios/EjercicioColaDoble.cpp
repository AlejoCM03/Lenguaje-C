#include<stdio.h>
#include<stdlib.h>

//hacer una estructura para nodos
typedef struct nodo{
	int dato;
	//enlace al siguiente nodo
	struct nodo *sig;
} Nodo;

typedef struct{
	Nodo *front;
	Nodo *final;
} Dqueue;

void initialize(Dqueue *dqueue){
	dqueue->front = NULL;
	dqueue->final = NULL;
}


int isEmpty(Dqueue *dqueue){
	return (dqueue->front == NULL);
}

int isFull(Dqueue *dqueue){
	return (dqueue->front == dqueue->final);
}


void enqueue(Dqueue *dqueue, int item){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->dato = item;
	//aqui se define la cola doble
	nuevo->sig = NULL; 
	
	if(isEmpty(dqueue)){
		dqueue->front = nuevo;
		dqueue->final = nuevo;
	}
	else{
		dqueue->final->sig = nuevo;
		dqueue->final = nuevo;
	}
}

int dequeueInit(Dqueue *dqueue){
	int x;
	
	if(isEmpty(dqueue)){
		printf("La cola esta vacia");
		return -1;
	}
	else{
		x = dqueue->front->dato;
		Nodo *aux;
		if(dqueue->front == dqueue->final){
			dqueue->front = NULL;
			dqueue->final = NULL;
		}
		else{
			aux = dqueue->front;
			dqueue->front = dqueue->front->sig;
		}
		free(aux);
	}
	
	return x;
}


int dequeueFinal(Dqueue *dqueue){
	Nodo *indice;
	int x;
	
	if(isEmpty(dqueue)){
		return -1;
	}
	else{
		indice = dqueue->front;
		while(indice->sig != NULL){
			indice = indice->sig;
			if(indice->sig == dqueue->final){
				x = dqueue->final->dato;
				dqueue->final = indice;
				indice->sig = NULL;
			}
		}
	}
	return x;
}

int size_Dqueue(Dqueue *dqueue){
	int count;
	
	Nodo *indice = dqueue->front;
	while(indice->sig != NULL){
		count ++;
		indice = indice->sig;
	}
	
	return count;
}

void display(Dqueue *dqueue){
	Nodo *indice = dqueue->front;
	
	while(indice != NULL){
		printf("|%d| ", indice->dato);
		indice = indice->sig;
	}
}


int main(){
	Dqueue dq;
	initialize(&dq);
	
	enqueue(&dq, 3);
	enqueue(&dq, 6);
	enqueue(&dq, 9);
	enqueue(&dq, 12);
	enqueue(&dq, 15);
	
	display(&dq);
	
	dequeueInit(&dq);
	dequeueFinal(&dq);
	dequeueFinal(&dq);
	printf("\n");
	display(&dq);
	
	return 0;
}

