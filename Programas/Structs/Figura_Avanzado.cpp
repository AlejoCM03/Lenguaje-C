//ejercicio nivel avanzado

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definici�n de la estructura para representar un punto en un plano 2D
typedef struct{
    int x;
    int y;
}Punto;

// Definici�n de la estructura para representar un tri�ngulo
typedef struct {
    Punto *vertices[3]; // Un tri�ngulo tiene 3 v�rtices, cada uno es un puntero a Punto2D
    char nombre[20];
}Triangulo;

int main() {
    // Declarar un tri�ngulo
    Triangulo triangulo;

    // Declarar e inicializar puntos 2D para los v�rtices del tri�ngulo
    Punto puntoA = {0, 0};
    Punto puntoB = {3, 0};
    Punto puntoC = {0, 4};

    // Asignar los puntos a los v�rtices del tri�ngulo usando punteros
    triangulo.vertices[0] = &puntoA;
    triangulo.vertices[1] = &puntoB;
    triangulo.vertices[2] = &puntoC;

    // Asignar un nombre al tri�ngulo
    strcpy(triangulo.nombre, "Tri�ngulo ABC");

    // Acceder a las coordenadas de los v�rtices usando punteros
    printf("Coordenadas de los v�rtices de %s:\n", triangulo.nombre);
    for (int i = 0; i < 3; i++) {
        printf("V�rtice %d - x: %d, y: %d\n", i + 1, triangulo.vertices[i]->x, triangulo.vertices[i]->y);
    }

    return 0;
}

