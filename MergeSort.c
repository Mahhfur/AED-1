#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 20000

void Intercala(int p, int q, int r, int v[]){
	int i, j, k, *w;
	w = malloc ((r-p) * sizeof(int));
	i=p;
	j=q; 
	k=0;
	while(i < q && j < r){
		if (v[i] <= v[j]) w[k++] = v[i++];
		else w[k++] = v[j++];
	}
	while (i < q) w[k++] = v[i++];
	while (j < r) w[k++] = v[j++];
	for (i=p; i<r; i++) v[i] = w[i-p];
	free(w);
}
void MergeSort(int p, int r, int v[]){
	if (p < r-1) {
		int q = (p+r)/2;
		MergeSort(p, q, v);
		MergeSort(q, r, v);
		Intercala(p, q, r, v);
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
    MergeSort(0, TAMANHO, vetor);

    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)* 1000;
    printf("Tempo decorrido: %lf milissegundos\n", tempo_decorrido);

    return 0;
}
