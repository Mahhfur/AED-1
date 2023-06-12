#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct noArv {
    char letra;
    struct noArv* esquerda;
    struct noArv* direita;
} noArv;

noArv* criarNo(char letra) {
    noArv* novoNo = (noArv*)malloc(sizeof(noArv));
    novoNo->letra = letra;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

noArv* inserirNo(noArv* raiz, char letra) {
    if (raiz == NULL) {
        return criarNo(letra);
    } else if (letra < raiz->letra) {
        raiz->esquerda = inserirNo(raiz->esquerda, letra);
    } else if (letra > raiz->letra) {
        raiz->direita = inserirNo(raiz->direita, letra);
    }
    return raiz;
}

bool buscarNo(noArv* raiz, char letra) {
    if (raiz == NULL) {
        return false;
    } else if (raiz->letra == letra) {
        return true;
    } else if (letra < raiz->letra) {
        return buscarNo(raiz->esquerda, letra);
    } else {
        return buscarNo(raiz->direita, letra);
    }
}

void imprimirInfixa(noArv* raiz) {
    if (raiz != NULL) {
        imprimirInfixa(raiz->esquerda);
        printf("%c ", raiz->letra);
        imprimirInfixa(raiz->direita);
    }
}

void imprimirPrefixa(noArv* raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->letra);
        imprimirPrefixa(raiz->esquerda);
        imprimirPrefixa(raiz->direita);
    }
}

void imprimirPosfixa(noArv* raiz) {
    if (raiz != NULL) {
        imprimirPosfixa(raiz->esquerda);
        imprimirPosfixa(raiz->direita);
        printf("%c ", raiz->letra);
    }
}

void liberarArvore(noArv* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    char comando[20], letra;

    noArv* raiz = NULL;

    while (scanf("%s%*c", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf("%c", &letra);
            raiz = inserirNo(raiz, letra);
        } else if (strcmp(comando, "INFIXA") == 0) {
            imprimirInfixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            imprimirPrefixa(raiz);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf("%c", &letra);
            if (buscarNo(raiz, letra)) {
                printf("%c existe\n", letra);
            } else {
                printf("%c nao existe\n", letra);
            }
        } else {
            imprimirPosfixa(raiz);
            printf("\n");
        }
    }

    liberarArvore(raiz);

    return 0;
}
