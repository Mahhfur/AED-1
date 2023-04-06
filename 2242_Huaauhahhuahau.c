#include <stdio.h>
#include <string.h>

//Confere quais risadas sao engraçadas ou não de acordo com os critérios do problema proposto: risadas digitais mais engracadas são aquelas em que as sequências de vogais são iguais quando lidas na ordem natural (da esquerda para a direita) ou na ordem inversa (da direita para a esquerda), ignorando as consoantes.

int main() {
    char risada[51], vogais[51];
    char vogais_inverso[51] = { '\0' };
    int i, m = 0, n = 0;
  
    scanf("%s", risada);

    for (i = 0; risada[i] != '\0'; i++) {
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u') {
            vogais[m] = risada[i];
            m++;
        }
    }
    vogais[m] = '\0';  
  
    for (i = m - 1; i >= 0; i--) {
        vogais_inverso[n] = vogais[i];
        n++;
    }
    vogais_inverso[n] = '\0';  
  

    if (strcmp(vogais, vogais_inverso) == 0) {
        printf("S\n");
    }
    if (strcmp(vogais, vogais_inverso) != 0){
        printf("N\n");
    }
    return 0;
}
