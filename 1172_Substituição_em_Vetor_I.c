#include <stdio.h>

//retira os 0 e negativos de um vetor e substitui por 1
void buscar_neg_zero(int vet[]){
	int i;
	for (i=0;i<10;i++){
		if (vet[i]==0 || vet[i]<0){
			vet[i]=1;
		}
	}
	return;
}

int main(void) {
	int vet [10], i;
	for (i=0;i<10;i++){
		scanf("%d", &vet[i]);
	}
	buscar_neg_zero(vet);
	for (i=0;i<10;i++){
		printf("X[%d] = %d\n", i, vet[i]);
	}
	
  return 0;
}