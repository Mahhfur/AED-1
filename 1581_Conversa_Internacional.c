#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 20

int main() {
    int n, i, k, j;
    char strings[MAX_STRINGS][MAX_LENGTH];
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        while (getchar() != '\n');

        for (j = 0; j < k; j++) {
            fgets(strings[j], sizeof(strings[j]), stdin);
            strings[j][strcspn(strings[j], "\n")] = '\0';
        }

        int ingles_presente = 0;
        for (j = 1; j < k; j++) {
            if (strcmp(strings[j], strings[0]) != 0) {
                ingles_presente = 1;
                break;
            }
        }

        if (ingles_presente)
            printf("ingles\n");
        else
            printf("%s\n", strings[0]);
    }

    return 0;
}