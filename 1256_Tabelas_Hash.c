#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Lista {
    No* primeiro;
    No* ultimo;
} Lista;

void inserir(Lista* hash, int chave, int tamanho) {
    No* novoNo = (No*)malloc(sizeof(No));
	
    int indice = chave % tamanho;

    if (hash[indice].primeiro)
        hash[indice].ultimo->proximo = novoNo;
    else
        hash[indice].primeiro = novoNo;

    hash[indice].ultimo = novoNo;
    novoNo->proximo = NULL;
    novoNo->dado = chave;
}

int main() {
    int quantidadeCasos;

    scanf("%d", &quantidadeCasos);

    for (int caso = 0; caso < quantidadeCasos; ++caso) {
        int tamanhoHash, quantidadeNumeros;

        scanf("%d %d", &tamanhoHash, &quantidadeNumeros);

        Lista* hash = (Lista*)malloc(tamanhoHash * sizeof(Lista));
        if (!hash)
            exit(1);

        for (int i = 0; i < tamanhoHash; ++i)
            hash[i].primeiro = NULL, hash[i].ultimo = NULL;

        for (int i = 0; i < quantidadeNumeros; ++i) {
            int numero;
            scanf("%d", &numero);
            inserir(hash, numero, tamanhoHash);
        }

        for (int i = 0; i < tamanhoHash; ++i) {
            printf("%d -> ", i);
            No* no = hash[i].primeiro;
            while (no) {
                printf("%d -> ", no->dado);
                no = no->proximo;
            }
            printf("\\\n");
        }

        free(hash);

        if (caso < quantidadeCasos - 1)
            printf("\n");
    }

    return 0;
}
