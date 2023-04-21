#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena_vetor(int n, char vet[][21]){
    char aux[21];
    
    for(int i=0; i < n-1; i++){
        for(int j=0; j < n-1; j++){
            if (strcmp(vet[j], vet[j+1]) > 0){
                strcpy(aux, vet[j]);
                strcpy(vet[j], vet[j+1]);
                strcpy(vet[j+1], aux);
            }
        }
    }
}


int main(){
    int n, i, c;
    char nomes[100][21];
    
    scanf ("%d %d", &n, &c);
    for (i=0;i<n;i++){
        scanf("%s", nomes[i]);
    }
    ordena_vetor(n, nomes);
	
    printf("%s\n", nomes[c-1]);
    return 0;
}
