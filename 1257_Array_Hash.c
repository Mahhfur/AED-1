#include <stdio.h>
#include <string.h>

int main() {
    int n, i, linhas, j, soma, tam, k;
    char str[60];

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        soma = 0;
        scanf("%d", &linhas);
        getchar();

        for (j = 0; j < linhas; j++) {
            fgets(str, sizeof(str), stdin);
            tam = strlen(str);

            for (k = 0; k < tam; k++) {
                if (str[k] != '\n') {
                    soma = soma + (str[k] - 'A') + j + k;
                }
            }
        }
        printf("%d\n", soma);
    }

    return 0;
}