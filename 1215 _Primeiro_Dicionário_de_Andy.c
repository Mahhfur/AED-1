#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char palavras[201];
} string;

bool stringSrc(char *, string *, unsigned);
void qSortAlphaParcial(string *dicionario, int tam);
void qSortAlphaParcialInterno(string *dicionario, int inicio, int fim);

int main() {
    unsigned i, j, k = 0;
    char tempEntrada[201], tempSaida[201];
    string dicionario[5050];

    memset(dicionario, 0, sizeof(dicionario));

    while (scanf(" %[^\n]", tempEntrada) != EOF) {
        i = j = 0;
        while (tempEntrada[i]) {
            while (isalpha(tempEntrada[i]))
                tempSaida[j++] = tolower(tempEntrada[i++]);

            if (tempEntrada[i] == '\0') {
                tempSaida[j] = '\0';

                if (!stringSrc(tempSaida, dicionario, k))
                    strcpy(dicionario[k++].palavras, tempSaida);

                j = 0;

                memset(tempSaida, 0, sizeof(tempSaida));
                break;
            }

            tempSaida[j] = '\0';

            while (!isalpha(tempEntrada[i])) {
                i++;
                if (tempEntrada[i] == '\0')
                    break;
            }

            if (!stringSrc(tempSaida, dicionario, k))
                strcpy(dicionario[k++].palavras, tempSaida);

            j = 0;
            memset(tempSaida, 0, sizeof(tempSaida));
        }

        memset(tempEntrada, 0, sizeof(tempEntrada));
    }

    qSortAlphaParcial(dicionario, k);

    j = 0;
    if (strcmp(dicionario[0].palavras, "\0") == 0)
        j = 1;

    for (; j < k; j++)
        printf("%s\n", dicionario[j].palavras);

    return 0;
}

bool stringSrc(char *str, string *dicionario, unsigned tam) {
    unsigned i;

    for (i = 0; i < tam; i++) {
        if (strcmp(dicionario[i].palavras, str) == 0)
            return true;
    }

    return false;
}

void qSortAlphaParcialInterno(string *dicionario, int inicio, int fim) {
    string pivo;
    string temp;
    int i, j;

    if (fim - inicio > 0) {
        if (inicio < fim) {
            i = inicio;
            j = fim;
            pivo = dicionario[(i + j) / 2];

            do {
                while (strcmp(dicionario[i].palavras, pivo.palavras) < 0)
                    i++;
                while (strcmp(dicionario[j].palavras, pivo.palavras) > 0)
                    j--;

                if (i <= j) {
                    temp = dicionario[i];
                    dicionario[i] = dicionario[j];
                    dicionario[j] = temp;
                    i++;
                    j--;
                }

            } while (i <= j);

            qSortAlphaParcialInterno(dicionario, inicio, j);
            qSortAlphaParcialInterno(dicionario, i, fim);
        }
    }
}

void qSortAlphaParcial(string *dicionario, int tam) {
    qSortAlphaParcialInterno(dicionario, 0, tam - 1);
}
