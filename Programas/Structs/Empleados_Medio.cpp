//ejercicio nivel medio
#include<stdio.h>
#include<string.h>

typedef struct{
	char nombre[50];
	int numeroEmpleado;
	float salario;
	char depto[50];
}Empleado;

void agregarEmpleado(Empleado empl[], int *numEmpl);
void listarDepto(Empleado empl[], int numEmpl, const char *deptoBusq);
float calcularNomina(const Empleado empl[], int numEmpl, const char *deptoBusq);

int main(){
	Empleado empleados[30]; //indica la cantidad maxima de empleados
	int numEmpleados = 0;
	int op;
	char deptoBuscado[30];
	float nomina;
	
	do{
		printf("----------Gestion de empleados por departamento----------\n\n");
		printf("(1)Agregar Empleado\t(2)Empleados por departamento\n");
		printf("(3)Calcular nomina de departamento\t(4)Salir\n");
		scanf("%d", &op); 
		
		switch(op){
			case 1: 
				if(numEmpleados < 30){
					agregarEmpleado(empleados,&numEmpleados);
				}else{
					printf("No se pueden regristrar mas empleados");
				}
				break;
				
			case 2:
				printf("Departamento a buscar: ");
				scanf("%s", deptoBuscado);
				listarDepto(empleados, numEmpleados, deptoBuscado);
				break;
				
			case 3:
				printf("Nombre de departamento para calcular la nómina:");
				scanf("%s", deptoBuscado);
				nomina = calcularNomina(empleados, numEmpleados, deptoBuscado);
				printf("Departamento: %s, Nomina: %.2f\n", deptoBuscado, nomina);
				break;
				
			case 4:
				printf("Salir...");
				break;
			
			default:
				printf("Opcion invalida\n");
				break;
		}
		
	}while(op != 4);
	
	return 0;
}


void agregarEmpleado(Empleado empl[], int *numEmpl){
	printf("\n");
	printf("Ingrese nombre de empleado: ");
	scanf("%s", empl[*numEmpl].nombre);
	printf("Ingrese numero de empleado: ");
	scanf("%d", &empl[*numEmpl].numeroEmpleado);
	printf("Ingrese salario: ");
	scanf("%f", &empl[*numEmpl].salario);
	printf("Departamento al que pertenece: ");
	scanf("%s", empl[*numEmpl].depto);
	(*numEmpl)++;
	printf("\nEmpleado registrado con exito\n\n");
}

void listarDepto(Empleado empl[], int numEmpl, const char *deptoBusq){
	printf("\n");
	printf("Empleados del departamento %s: ", deptoBusq);
	bool encontrado = false;
	
	printf("\n");
	for(int i=0; i<numEmpl; i++){
		if(strcmp(empl[i].depto, deptoBusq) == 0){
			printf("Nombre: %s\n", empl[i].nombre);
            printf("Número de empleado: %d\n", empl[i].numeroEmpleado);
            printf("Salario: %.2f\n", empl[i].salario);
            encontrado = true;
		}
	}
	if(!encontrado){
		printf("No hay ningun empleado en el departamento\n\n");
	}
}

float calcularNomina(const Empleado empl[], int numEmpl, const char *deptoBusq){
	
	float nom = 0.0;
	
	for(int i=0; i<numEmpl; i++){
		if(strcmp(empl[i].depto, deptoBusq) == 0){
			nom += empl[i].salario; 
		}
	}
	
	return nom;
}

