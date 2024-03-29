//ejercicio nivel avanzado

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definición de la estructura para representar un punto en un plano 2D
typedef struct{
    int x;
    int y;
}Punto;

// Definición de la estructura para representar un triángulo
typedef struct {
    Punto *vertices[3]; // Un triángulo tiene 3 vértices, cada uno es un puntero a Punto2D
    char nombre[20];
}Triangulo;

int main() {
    // Declarar un triángulo
    Triangulo triangulo;

    // Declarar e inicializar puntos 2D para los vértices del triángulo
    Punto puntoA = {0, 0};
    Punto puntoB = {3, 0};
    Punto puntoC = {0, 4};

    // Asignar los puntos a los vértices del triángulo usando punteros
    triangulo.vertices[0] = &puntoA;
    triangulo.vertices[1] = &puntoB;
    triangulo.vertices[2] = &puntoC;

    // Asignar un nombre al triángulo
    strcpy(triangulo.nombre, "Triángulo ABC");

    // Acceder a las coordenadas de los vértices usando punteros
    printf("Coordenadas de los vértices de %s:\n", triangulo.nombre);
    for (int i = 0; i < 3; i++) {
        printf("Vértice %d - x: %d, y: %d\n", i + 1, triangulo.vertices[i]->x, triangulo.vertices[i]->y);
    }

    return 0;
}

