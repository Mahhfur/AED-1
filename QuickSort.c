#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 20000

int Separa(int p, int r, int v[]){
	int c, j, k, t;
	c = v[r];
	j = p;
	for (k = p; k < r; k++)
		if(v[k]<=c){
			t = v[j], v[j] = v[k], v[k] = t;
			j++;
		}
	v[r] = v[j], v[j] = c;
	return j;
}

void QuickSort(int p, int r, int v[]){
	int j;
	if (p < r) {
		j = Separa(p, r, v);
		QuickSort(p, j-1, v);
		QuickSort(j+1, r, v);
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
    QuickSort(0, TAMANHO, vetor);

    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)* 1000;
    printf("Tempo decorrido: %lf milissegundos\n", tempo_decorrido);

    return 0;
}
