#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Le uma palavra e a criptografa 

int main() {
    char vet1[50];
    char vet2[50];
    int v, i, n, w;
    scanf("%d", &n);
    for (w = 0; w < n; w++) {
        scanf("%s", vet1);
        int l = strlen(vet1);
        scanf("%d", &v);
        for (i = 0; i < l; i++) {
            vet2[i] = vet1[i] - v;
            if (vet2[i] < 65) {
                vet2[i] += 26;
            }
        }
        vet2[l] = '\0';
        printf("%s\n", vet2);
        for (int M = 0; M < l; M++) {
            vet2[M] = 0;
        }
    }
    return 0;
}