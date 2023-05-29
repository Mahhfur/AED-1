#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAXSIZE 1200

unsigned dist[MAXSIZE];
unsigned grafo[MAXSIZE][MAXSIZE];

void dijkstra(int s, int n, unsigned g[MAXSIZE][MAXSIZE], unsigned *d) {
    bool vis[MAXSIZE];
	
    //nenhum vértice foi visitado ainda
		memset(vis, false, sizeof(vis));

    for (int i = 0 ; i <= n; ++i) {
        d[i] = UINT_MAX;
    }

    d[s] = 0;

    for (int i = 0; i <= n; ++i) {
        int v = -1;
        for (int j = 0; j <= n; ++j) {
            if (!vis[j] && (v == -1 || d[j] < d[v])) {
                v = j; // vértice não visitado com a menor distância d[v]
            }
        }
        if (d[v] == UINT_MAX) {
            break; // não há mais caminhos possíveis no grafo
        }

        vis[v] = true;

        for (int j = 0; j <= n; ++j) {
            if (d[v] != UINT_MAX && g[v][j] != UINT_MAX && d[v] + g[v][j] < d[j]) {
                d[j] = g[v][j] + d[v]; //vetor d contém as distâncias mínimas do vértice de origem para todos os outros vértices no grafo.
            }
        }
    }
}

int main() {
    int n, m, c, r, e;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                grafo[i][j] = UINT_MAX;
            }
        }

        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a][b] = grafo[b][a] = 1;
        }

        scanf("%d %d %d", &c, &r, &e);

			//todas as rotas que passam pela cidade Estadunido são definidas com um valor de "infinito" 
        for (int i = 0; i <= n; ++i) {
            grafo[e][i] = grafo[i][e] = UINT_MAX;
        }

        dijkstra(c, n, grafo, dist);

            printf("%d\n", dist[r]);
		}
    return 0;

}

