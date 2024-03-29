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
	int cont;
} Cqueue;

void initialize(Cqueue *cqueue){
	cqueue->front = NULL;
	cqueue->final = NULL;
	cqueue->cont = 0;
}

int isEmpty(Cqueue *cqueue){
	return (cqueue->cont == 0);
}

void enqueue(Cqueue *cqueue, int item){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->dato = item;
	//aqui se define la cola circular
	nuevo->sig = cqueue->front; 
	
	if(isEmpty(cqueue)){
		cqueue->front = nuevo;
		cqueue->final = nuevo;
	}
	else{
		cqueue->final->sig = nuevo;
		cqueue->final = nuevo;
	}
	cqueue->cont ++;
}

int dequeue(Cqueue *cqueue){
	Nodo *eliminar = cqueue->front;
	int x;
	
	if(isEmpty(cqueue)){
		printf("La cola esta vacia\n");
		return -1;
	}
	else{
		x = cqueue->front->dato;
		if(cqueue->front == cqueue->final){
			cqueue->front = NULL;
			cqueue->final = NULL;
		}
		else{
			cqueue->front = cqueue->front->sig;
		}
	}
	cqueue->cont --;
	return x;
}

int size_Cqueue(Cqueue *cqueue){
	return cqueue->cont;
}

void display(Cqueue *cqueue){
	Nodo *indice = cqueue->front;
	
	do{
		printf("|%d| ",indice->dato);
		indice = indice->sig;
	}while(indice != cqueue->front);
}


int main(){
	
	Cqueue cq;
	initialize(&cq);
	
	enqueue(&cq, 7);
	enqueue(&cq, 14);
	enqueue(&cq, 21);
	enqueue(&cq, 28);
	enqueue(&cq, 35);
	
	display(&cq);
	printf("\n"),
	dequeue(&cq);
	
	display(&cq);
}





