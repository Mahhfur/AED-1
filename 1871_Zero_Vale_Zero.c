#include <stdio.h>

//Remove zeros de um numero
int removeZeros(int num) {
    int novoNum = 0;
    int mult = 1;

    while (num > 0) {
        int digito = num % 10;
        num /= 10;
        if (digito != 0) {
            novoNum += digito * mult;
            mult *= 10;
        }
    }

    return novoNum;
}

int main() {
    int m, n;

    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) {
            break;
        }

        int soma = m + n;
        int somaSemZeros = removeZeros(soma);

        printf("%d\n", somaSemZeros);
    }

    return 0;
}