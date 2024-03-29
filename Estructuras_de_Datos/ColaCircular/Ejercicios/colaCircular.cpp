#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int data;
    struct nodo *sig;
} Nodo;

typedef struct{
    Nodo *front;
    Nodo *final; 
    int cont;
} Cqueue;


void initialize(Cqueue *cqueue){
    cqueue -> front = NULL;
    cqueue -> final = NULL;
}

int isEmpty(Cqueue *cqueue){ 
    return (cqueue->front == NULL); 
} 
 
void enqueue(Cqueue *cqueue, int item){

    Nodo *nuevo = (Nodo*) malloc (sizeof(Nodo));
    nuevo->data = item;
    nuevo->sig = cqueue->front;

    if(isEmpty(cqueue)){
        cqueue -> front = nuevo;
        cqueue -> final = nuevo;
    }
    else{
        cqueue -> final -> sig = nuevo;
        cqueue -> final = nuevo;
    }
    cqueue->cont++;

}

int dequeue(Cqueue *cqueue){
    Nodo *del = cqueue->front;
    int x;

    if(isEmpty(cqueue)){ 
        printf("La cola esta vacia\n"); 
        return -1;
    }
    else{
        x = cqueue->front->data;
        if(cqueue->front == cqueue->final){
            cqueue->front = NULL;
            cqueue->final = NULL;
        } 
        else{
            cqueue->front = cqueue->front->sig;
        }
        free(del);

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
        printf("|%d|", indice->data);
        indice = indice->sig;

        if(indice == cqueue->front){
            printf("-->|%d|", indice->data);
            printf("\n");
        }
        
    }while(indice != cqueue->front);
}

int main(){
    Cqueue cq; 
    initialize(&cq); 
    
    int op, item; 
    
    printf("------COLA CIRCULAR (CIRCULAR QUEUE)------\n\n"); 
    do{ 
    printf("Insertar(1)\tEliminar(2)\n"); 
    printf("Ver tamanio(3)\tMostrar(4)\tSalir(5)\n\n"); 
    scanf("%d",&op); 
    
    switch(op){ 
    case 1: 
        printf("Dame el valor a insertar: "); 
        scanf("%d",&item); 
        enqueue(&cq, item); 
        break; 
        
    case 2: 
        printf("Eliminando...\n"); 
        printf("El valor eliminado es: %d\n",dequeue(&cq)); 
        break; 
        
    case 3:  
        printf("Hay %d elementos\n", size_Cqueue(&cq)); 
        break; 
        
    case 4: 
        display(&cq); 
        break; 
        
    case 5: 
        printf("Salir...\n"); 
        break; 
        
    default: 
        printf("Opcion Invalida...\n"); 
        break; 
    }    
    }while(op != 5); 
    
    return 0; 
}
