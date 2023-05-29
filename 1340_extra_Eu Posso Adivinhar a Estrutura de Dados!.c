#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elemento{
	int num;
	struct Elemento *prox;
};
typedef struct Elemento No;

struct Pilha{
   No *topo; 
}; typedef struct Pilha Pilha;

void cria_pilha(Pilha *pi){
    if(pi != NULL){
      pi->topo = NULL; 
    }
}
void insere_elemento (Pilha *pi, int x) {
	No *novo = malloc(sizeof(No));
	
	novo->num=x;
	novo->prox=pi->topo;
	if (pi->topo == NULL) { // verificação para pilha vazia
        pi->topo = novo;
    }
	pi->topo= novo;
}	
	
void consulta_pilha(Pilha *pi){
	No* aux; 
	if(pi->topo == NULL){
	//	printf("\nPilha Vazia!!");
	}
	else{
		aux = pi->topo;
		do{
			printf(" %d ", aux->num);
			 fflush(stdout);
			aux = aux->prox;
		} while(aux != NULL);
	}
}
	

int remove_elemento_pilha(Pilha *pi) {
    if(pi->topo == NULL) {
       // printf("\nPilha Vazia!!");
    } 
    else {
        No* aux = pi->topo;
        pi->topo = aux->prox; 
				return aux->num;
        free(aux); 
    }
}

//FILA
struct Fila {
    No *inicio; 
    No *fim; 
};
typedef struct Fila Fila;

void cria_fila(Fila *fi) {
    fi->fim = NULL;
    fi->inicio = NULL;
}

void inserir_fila(Fila *fi, int x) {
    No *novo = (No*) malloc(sizeof(No));
    novo->num = x;
    novo->prox = NULL;
    if(fi->inicio == NULL) {
        fi->inicio = novo;
        fi->fim = novo;
    } else {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
}		

void imprime_fila(Fila *fi) {
    No *aux;
    if(fi->inicio == NULL) {
      //  printf("\nFila Vazia!!");
    } else {
        aux = fi->inicio;
        do {
            printf(" %d ", aux->num);
            aux = aux->prox;
        } while(aux != NULL);
    }
}

int busca_fila(Fila *fi, int x) {
    No* aux = fi->inicio;
    while(aux != NULL) {
        if(aux->num == x) {
            return x;
        } else {
            aux = aux->prox;
        }
    }
    return -1;
}

int remove_elemento_fila(Fila *fi) {
    No *aux;
    if(fi->inicio == NULL) {
     //   printf("\nFila Vazia!!");
    } else {
        aux = fi->inicio;
        fi->inicio = fi->inicio->prox;
				return aux->num;
        free(aux);
    }
}

//remove elemento da fila de prioridade
int remove_prioridade_fila(Fila *fi) {
    if(fi->inicio == NULL) {
        //printf("\nFila Vazia!!");
        return -1;
    }

    int maior_valor = fi->inicio->num;
    No *maior_no = fi->inicio;
    No *aux = fi->inicio->prox;

    while(aux != NULL) {
        if(aux->num > maior_valor) {
            maior_valor = aux->num;
            maior_no = aux;
        }
        aux = aux->prox;
    }

    aux = fi->inicio;
    if (fi->inicio == maior_no) {
        fi->inicio = aux->prox;
    } else {
        while (aux->prox != NULL && aux->prox != maior_no) {
            aux = aux->prox;
        }
        if (aux->prox == NULL) {
            //printf("\nElemento nao encontrado!");
            return -1;
        }
        if (fi->fim == maior_no) {
            fi->fim = aux;
        }
        aux->prox = aux->prox->prox;
    }

    int retorno = maior_no->num;
    free(maior_no);
    return retorno;
}

//compara duas filas
int compara_duas_filas(Fila* fila1, Fila* fila2) {
    No* no1 = fila1->inicio;
    No* no2 = fila2->inicio;

    // percorre as duas filas e compara cada elemento
    while (no1 != NULL && no2 != NULL) {
        if (no1->num != no2->num) {
            return 0; // filas diferentes
        }
        no1 = no1->prox;
        no2 = no2->prox;
    }

    return 1; // filas iguais
}

	
int main (){
	Pilha p;
	Fila f;
	Fila fp;
	Fila ft;
	Fila f1;
	Fila fp2;
	Fila p1;

	cria_fila(&p1);
	cria_fila(&fp2);
	cria_fila(&f1);
  cria_fila(&f);
	cria_fila(&fp);
	cria_fila(&ft);
	cria_pilha (&p);
	int n, i, a, b, x, y, t;

	while (scanf("%d", &n)!=EOF){
	for(i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		if(a==1){
			insere_elemento(&p, b);
			inserir_fila(&f, b);
			inserir_fila(&fp, b);
		}
		if(a==2){
			x= remove_elemento_fila(&f);
			inserir_fila (&f1, x);
			y=remove_prioridade_fila(&fp);
			//printf("%d\n", y);
			inserir_fila (&fp2,y);
			t=remove_elemento_pilha(&p);
		  inserir_fila(&p1, t);
			inserir_fila(&ft, b);
		}				
	}
	
	int fila=compara_duas_filas(&ft, &f1);
	int pilha=compara_duas_filas(&ft, &p1);
	int fila_prio=compara_duas_filas(&fp2, &ft);
	//imprime_fila(&fp2);
	//imprime_fila(&p1);
	//puts(" ");
	//printf("%d", y);
	if (fila==1 && pilha==0 && fila_prio== 0){
			printf("queue\n");
		 fflush(stdout);
		}
	
	if(fila==0 && pilha==1 && fila_prio== 0){
			printf("stack\n");
		 fflush(stdout);
		}

	if(fila==0 && pilha==0 && fila_prio== 1){
		printf("priority queue\n");
		 fflush(stdout);
	}
	if(fila==1 && pilha==1 && fila_prio== 1){
		printf("not sure\n");
		 fflush(stdout);
	}
	if(fila==1 && pilha==1 && fila_prio== 0){
		printf("not sure\n");
		 fflush(stdout);
	}
	if(fila==1 && pilha==0 && fila_prio== 1){
		printf("not sure\n");
		 fflush(stdout);
	}
	if(fila==0 && pilha==1 && fila_prio== 1){
		printf("not sure\n");
		 fflush(stdout);
	}
	if(fila==0 && pilha==0 && fila_prio== 0){
		printf("impossible\n");
		fflush(stdout);
	}	
	}
	return 0;
}
