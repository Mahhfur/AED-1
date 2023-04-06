#include <stdio.h>
#include <math.h>

//Fórmula de Bhaskara
int main() {
 
   float A, B, C, delta, raiz1, raiz2;
   scanf ("%f %f %f", &A, &B, &C);
   delta= pow(B,2)-(4*A*C);
   raiz1=(-(B)+sqrt(delta))/(2*A);
   raiz2=(-(B)-sqrt(delta))/(2*A);
	if(A==0.0 || delta<0){
		printf("Impossivel calcular\n");
	}
	else {
		printf("R1 = %.5f\nR2 = %.5f\n", raiz1, raiz2);
	}
   
    return 0;
}