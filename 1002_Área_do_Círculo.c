#include <stdio.h>
#include <math.h>

//Cálcula a área de um circulo
int main() {
 
   double pi,area,raio;
   pi=3.14159;
   scanf("%lf", &raio);
   area=pi*pow(raio, 2);
   printf("A=%.4f\n", area);
   
   return 0;
}