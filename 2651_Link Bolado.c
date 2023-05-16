#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100000

void minuscula(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int BoyerMoore1(char a[], int m, char b[], int n) {
    int T1[256], i, k, r, ocorrs;

    /* pré-processamento da palavra a */
    for (i = 0; i < 256; i++) T1[i] = m;
    for (i = 1; i <= m; i++) T1[a[i-1]] = m - i;

    /* busca da palavra a no texto b */
    ocorrs = 0; k = m-1;
    while (k <= n) {
        r = 0;
        while (m - r >= 1 && a[m-r-1] == b[k-r]) r += 1;
        if (m - r < 1) {
            ocorrs += 1;
            break;
        }
        if (k == n) k += 1;
        else k += T1[b[k+1]] + 1;
    }

    return ocorrs;
}


int main(void) {
    char s[MAX];
    char z[] = "zelda";
    int x, n;

    fgets(s, MAX, stdin);
    n = strlen(s);
    minuscula(s);

    x = BoyerMoore1(z, strlen(z), s, n);

    if (x >= 1) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}
