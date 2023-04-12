/*ler em uma única linha a lista de amigos de Luiggy L, contendo somente o primeiro nome e separados por um espaço em branco.
Na segunda linha deve ser informada a nova lista de amigos N. 
Na última linha, o nome do amigo S da rede que deseja indicar também essa nova lista de amigos N. Caso não queira indicar para ninguém a nova lista de amigos, basta digitar na última linha a palavra “nao”.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
  char info[50];
  struct no *prox;
};
typedef struct no No;

struct listaDE {
  No *primeiroNo, *ultimoNo;
  int tamanhoLista;
};
typedef struct listaDE Lista;

//inicializa a lista
void Inicializa(Lista *L) {
  L->primeiroNo = NULL;
  L->ultimoNo = NULL;
  L->tamanhoLista = 0;
};

//insere no final da lista
void insere_final(Lista *L, char nome[]) {
  No *novoNo = malloc(sizeof(No));
  strcpy(novoNo->info, nome);
  novoNo->prox = NULL;

  if (L->tamanhoLista == 0) {
    L->primeiroNo = novoNo;
    L->ultimoNo = novoNo;
  } else {
    L->ultimoNo->prox = novoNo;
    L->ultimoNo = novoNo;
  }

  L->tamanhoLista++;
}

void imprime(Lista *l);

//insera uma lista nl no final da lista l
void inserirlista_lista(Lista *l, Lista *nl){
	if (l->primeiroNo == NULL) {
		l->primeiroNo = nl->primeiroNo;
	} 
	else {
		l->ultimoNo->prox=nl->primeiroNo;
	}
	l->tamanhoLista += nl->tamanhoLista;
}

//coloca a novaLista na lista l, antes do Indicacao 
void indicaAmigo(Lista *l, char Indicacao[], Lista *novaLista) {
    No *aux = l->primeiroNo;
	
	// Indicação  é a primeira pessoa da lista
	if (strcmp(aux->info, Indicacao) == 0) {
      inserirlista_lista(novaLista, l);
			imprime(novaLista);
  } 
		
		// Indicação não é a primeira pessoa da lista
	else { 
			while (aux->prox!=NULL && strcmp(aux->prox->info, Indicacao) != 0) {
        aux=aux->prox;
    }
    No *aux2= aux->prox;
		aux->prox=novaLista->primeiroNo;
		novaLista->ultimoNo->prox=aux2;
    
		imprime(l);
    }
}

//printa a lista
void imprime(Lista *l) {
  No *noAux = l->primeiroNo;
  while (noAux-> prox!= NULL) {
    char* nome = strtok(noAux->info, "\n");
    printf("%s ", nome);
    noAux = noAux->prox;
  }
  char* name = strtok(noAux->info, "\n");
  printf("%s", name);
  printf("\n");
}

int main(){
    char* lista_atual[1000];
    char* nova_lista[1000];
    char amigo_indicado[50];
    int i;
    Lista listaAmigos, listaNovosAmigos;
    Inicializa(&listaAmigos);
    Inicializa(&listaNovosAmigos);

  //le a lista atual
    fgets(lista_atual, 100, stdin);
    char* token = strtok(lista_atual, " \n");
    while (token != NULL) {
        insere_final(&listaAmigos, token);
        token = strtok(NULL, " \n");
    }

	//le a lista nova
     fgets(nova_lista, 100, stdin);
     token = strtok(nova_lista, " \n");
     while (token != NULL) {
    	 insere_final(&listaNovosAmigos, token);
     	 token = strtok(NULL, " \n");
    }

 // Lê o nome do amigo que receberá a nova lista como indicação de amigos
    fgets(amigo_indicado, 50, stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = 0; // remove o caractere de nova linha

//se nao houver indicado junta as listas
    if (strcmp(amigo_indicado, "nao") == 0)  {
 	 		inserirlista_lista(&listaAmigos, &listaNovosAmigos);
			imprime(&listaAmigos);
    }
    else{
		indicaAmigo(&listaAmigos, amigo_indicado, &listaNovosAmigos);
	
    }
}
