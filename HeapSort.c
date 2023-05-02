#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5000

void InsereEmHeap(int m, int v[]){
	int f = m+1;
	while(f > 1 && v[f/2] < v[f]){
		int t = v[f/2];
    v[f/2] = v[f];
    v[f] = t;
    f = f/2;
  }
}

void SacodeHeap(int m, int v[]){
	int t, f = 2;
	while(f <= m){
    if(f < m && v[f] < v[f+1]){
      ++f;
    }
    if(v[f/2] >= v[f]){
      break;
    }
    t = v[f/2];
    v[f/2] = v[f];
    v[f] = t;
		f*=2;
  }
}

void HeapSort(int n, int v[]){
	int m, t;
	for (m = 1; m < n; m++){
		InsereEmHeap(m, v);
  }
	for(m = n; m > 1; m--){
		t = v[1];
    v[1] = v[m];
    v[m] = t;
    SacodeHeap(m-1, v);
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
    HeapSort(TAMANHO, vetor);

    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)* 1000;
    printf("Tempo decorrido: %lf milissegundos\n", tempo_decorrido);

    return 0;
}
