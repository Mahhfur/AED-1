#include <stdio.h>
#include <stdlib.h>

struct No{
	int chave;
	struct No *dir;
	struct No *esq;
}; typedef struct No no;

//insere um nó na arvore
no* insere(no *arv, int x){

	if (arv==NULL){

		arv = (no*) malloc(sizeof(no));
		arv->chave = x;
		arv->esq = arv->dir = NULL;

	}
	else if (arv->chave > x)
		arv->esq = insere(arv->esq, x);

	else
		arv->dir = insere(arv->dir, x);

	return arv;
}

void Posfixa(no *arv) {
	if(arv!=NULL){
		Posfixa(arv->esq);
		Posfixa(arv->dir);
		printf(" %d", arv->chave);
	}
}

void Infixa(no *arv) {
	if(arv!=NULL){
		Infixa(arv->esq);
		printf(" %d", arv->chave);
		Infixa(arv->dir);
	}
}

void Prefixa(no *arv) {
	if(arv!=NULL){
		printf(" %d", arv->chave);
		Prefixa (arv->esq);
		Prefixa(arv->dir);
	}
}


int main(){
	int i,j, num, nos, casos, ca=0;
	scanf("%d", &casos);

	for (i=0; i<casos; i++){
		no *arvore = NULL;
		scanf("%d", &nos);

		for (j = 0; j < nos; j++){
			scanf("%d", &num);
			arvore = insere(arvore, num);
		}
		printf("Case %d:\n", ++ca);
		printf("Pre.:");
		Prefixa(arvore);
		printf("\n");
		printf("In..:");
		Infixa(arvore);
		printf("\n");
		printf("Post:");
		Posfixa(arvore);
		printf("\n\n");
	}
  return 0;
}




