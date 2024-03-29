//de 100 numeros aleatorios, guardar los primos en CD
//y los numeros pares en CC

#include<stdio.h>
#include<stdlib.h>

//hacer una estructura para nodos
typedef struct nodo{
	int dato;
	//enlace al siguiente nodo
	struct nodo *sig;
} Nodo;

typedef struct{
	Nodo *frontC;
	Nodo *finalC;
	int cont;
} Cqueue;

typedef struct{
	Nodo *frontD;
	Nodo *finalD;
} Dqueue;


void initCirc(Cqueue *cq){
	cq->frontC = NULL;
	cq->finalC = NULL;
	cq->cont = 0;
}

void initDoble(Dqueue *dq){
	dq->frontD = NULL;
	dq->finalD = NULL;
}

void insertCircular(Cqueue *cq, int x){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->dato = x;
	nuevo->sig = cq->frontC;
	
	if(cq->frontC == NULL){
		cq->frontC = nuevo;
		cq->finalC = nuevo;
	}
	else{
		cq->finalC->sig = nuevo;
		cq->finalC = nuevo;
	}
	
	cq->cont++;
}

void insertDoble(Dqueue *dq, int x){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->dato = x;
	nuevo->sig = NULL;
	
	if(dq->frontD == NULL){
		dq->frontD = nuevo;
		dq->frontD = nuevo;
	}
	else{
		dq->finalD->sig = nuevo;
		dq->finalD = nuevo;
	}
	
}


void mostrar(Dqueue *dq, Cqueue *cq){
	Nodo *indiceC = cq->frontC;
	Nodo *indiceD = dq->frontD;
	
	printf("\n---Numeros Primos---\n");
	do{
		printf("|%d| ", indiceC->dato);
		indiceC = indiceC->sig;
	}while(indiceC != cq->frontC);
	
	printf("\n---Numeros Pares---\n");
	while(indiceD != NULL){
		printf("|%d| ", indiceD->dato);
		indiceD = indiceD->sig;
	}
}


int main(){
	
	Dqueue dq;
	Cqueue cq;
	
	initDoble(&dq);
	initCirc(&cq);
	
	int arr[100];
	int div;
	
	for(size_t i=0; i<100; i++){
		arr[i] = i+1;
	}
	
	for(size_t i=0; i<100; i++){
		if(arr[i]%2 == 0){
			insertDoble(&dq, arr[i]);
		}
	}
	
	//numeros primos
	for(size_t i=0; i<100; i++){
		
		for(div = 2; div <= arr[i]/2; div++){
			if(arr[i]%div == 0){
				break;
			}
		}
		
		if(div > arr[i]/2){
			insertCircular(&cq, arr[i]);
		}
	}
	printf("paro");
	mostrar(&dq, &cq);
	
	
	
}





