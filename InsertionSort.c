#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 20000

void InsertionSort(int n, int v[]){
	int i, j, x;
	for (j=1; j<n; j++){
		x = v[j];
		for(i = j-1; i >= 0 && v[i] > x; i--)
			v[i+1] = v[i];
		v[i+1] = x;
	}
}

int main() {
	  int vetor[TAMANHO];
    clock_t inicio, fim;
    double tempo_decorrido;

		int i;
	
		// cria um vetor aleatório
    srand(64); 

    for (i = 0; i < TAMANHO; i++) {
      vetor[i] = rand() % 1000;
    }

    inicio = clock();

    // Código a ser medido
    InsertionSort(TAMANHO, vetor);

    fim = clock();

    tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido: %lf segundos\n", tempo_decorrido);
	
    return 0;
}
