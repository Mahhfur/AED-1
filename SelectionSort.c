#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 20000

void SelectionSort(int n, int v[]){
  int i, j, min, x;
  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j < n; j++){
      if(v[j] < v[min]){
        min = j;
      }
    }
    x = v[i];
    v[i] = v[min];
    v[min] = x;
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
    SelectionSort(TAMANHO, vetor);

    fim = clock();

    tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido: %lf segundos\n", tempo_decorrido);

    return 0;
}
