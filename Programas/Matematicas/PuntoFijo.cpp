#include<stdio.h>
#include<math.h>

double g(double x){
	return acos(sqrt(x)/2);
}

void puntoFijo(double x0, int n){
	
	double x1 = 0.0;
	for(int i=0; i<=n; i++){
		x1 = g(x0);
		double error = abs((x1-x0)/x1)*100;
		printf("\nError: %0.4lf\n", error);
		
		x0 = x1;
		printf("\nx%d = %0.4lf\n", i,x1);
	}
}

int main(){
	double x0 = 0.0;
	int n = 0; 
	
	printf("Dame el valor inicial: ");
	scanf("%f", &x0);
	
	printf("Dame el numero de iteraciones: ");
	scanf("%d", &n);
	
	puntoFijo(x0, n);
	
	return 0;
	
}

