#include <stdio.h>
#include <math.h>
#include <string.h>
 
//Le duas palavras e retorna a combinação das duas
int main() {
  int n,l, k, f;
  int i = 0, j = 0;
  char vet1[50];
  char vet2[50];
  char vet3[100];
	
  scanf("%d", &n);

  for(int x = 0; x < n; x++){

    scanf("%s %s", vet1, vet2);
		int len1 = strlen(vet1);
		int len2 = strlen(vet2);

    for(i = 0, f = 0, k=0; i <= len1 || f<= len2; i++, f++){
			if (i < len1){ 
				vet3[k++] = vet1[i]; }
      if (f < len2) {
				vet3[k++] = vet2[f];}
			vet3[k] = '\0';
			
		}
		len1= 0;
		len2= 0;
    printf("%s\n", vet3);

    for(int M = 0; M < 100; M++){
          vet3[M] = 0;
      }
    }
    return 0;
}
