#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMS 20

typedef struct nodo 
{
    int dato;
    struct nodo *sig;  
} Nodo;

typedef struct {
    Nodo *front;
    Nodo *final;
    Nodo *actually;
} Dqueue;


void initialize(Dqueue *dqueue){
    dqueue -> front = NULL;
    dqueue -> final = NULL;
    dqueue -> actually = NULL;
}

int isEmpty(Dqueue *dqueue){
    return (dqueue->front == NULL);
}

int isFull(Dqueue *dqueue){
    return (dqueue->front == dqueue->final);
}

void enqueue(Dqueue *dqueue, int item){

    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = item;
    nuevo->sig = NULL;

    if(dqueue->front == NULL){
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
        printf("La cola circular esta vacia\n");
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
        printf("La cola esta vacia\n");
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
        printf("|%d| \n",indice->dato);
        indice = indice->sig;
    }
}

	

int main(){
	Dqueue Cdoble;
	initialize(&Cdoble);

	int op, item;
	
	printf("------COLA DOBLE (DOUBLE QUEUE)------\n\n");
	do{
		printf("Insertar(1)\tEliminar Frente(2)\tEliminar Final(3)\n");
		printf("Ver tamanio(4)\tMostrar(5)\tSalir(6)\n\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("Dame el valor a insertar: ");
				scanf("%d",&item);
				enqueue(&Cdoble, item);
				break;
				
			case 2:
				printf("Eliminando al frente...\n");
				printf("El valor eliminado es: %d\n",dequeueInit(&Cdoble));
				break;
			
			case 3:
				printf("Eliminando al final...\n");
				printf("El valor eliminado es: %d\n", dequeueFinal(&Cdoble));
				break;
				
			case 4: 
				printf("Hay %d elementos\n", size_Dqueue(&Cdoble));
				break;
			
			case 5:
				display(&Cdoble);
				break;
			
			case 6:
				printf("Salir...\n");
				break;
				
			default:
				printf("Opcion Invalida...\n");
				break;
		}			
	}while(op != 6);
	
	return 0;
}
