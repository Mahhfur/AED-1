#include <stdio.h>

#define MAX_SIZE 100

char s[MAX_SIZE][MAX_SIZE];
int mapa[MAX_SIZE][MAX_SIZE];
int n, m, x, y, dirX, dirY;

//verifica se a coordenada esta dentro do mapa
int valido(int x, int y) {
    return x > -1 && y > -1 && x < n && y < m;
}

int main() {
    scanf("%d%d", &m, &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    while (valido(x, y)) {
      // Mapa esta em looping
			if (mapa[x][y]) {
           printf("!\n");
          return 0;
      }
      if (s[x][y] == '*') {
           printf("*\n");
           return 0;
      }
      if (s[x][y] == '>') {
          dirX = 0;
          dirY = 1;
      } 
		  else if (s[x][y] == '<') {
          dirX = 0;
          dirY = -1;
     } 
		  else if (s[x][y] == 'v') {
          dirX = 1;
          dirY = 0;
     } 
		  else if (s[x][y] == '^') {
			    dirX = -1;
          dirY = 0;
        }
		
        mapa[x][y] = 1;
        x += dirX;
        y += dirY;
    }
	  printf("!\n"); // Mapa inválido, não foi encontrado o baú
    return 0;
}
