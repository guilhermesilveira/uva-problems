#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char lista[26000][20];
int passou[26000], fila[26000];
int pai[26000], n;

int busca(char *a, int ini, int fim);

int comp(const void *a, const void *b) {
  char *aa = (char *)a;
  char *bb = (char *)b;
  return strcmp(aa,bb);
}

void imprime(int atual) {
 
  if (atual != pai[atual]) {
    imprime(pai[atual]);
  }
  
  printf("%s\n",lista[atual]);
  
  return;
  
}

int bfs(int sor, int dest) {

  int i,j,k, atual, ifila, ffila;
  int tam, ind;
  char aux[20];

  fila[0] = sor;
  ifila = 0;
  ffila = 1;
  passou[sor] = 1;
  pai[sor] = sor;

  while(ifila < ffila) {
    atual = fila[ifila++];
    tam = strlen(lista[atual]);
    
    for (i = tam-1; i >= 0; i--) {
      for (j = 'z'; j >= 'a'; j--) {
	for (k = 0; k < tam; k++)
	  aux[k] =lista[atual][k];
	aux[k] = '\0';
	aux[i] = j;
	/* printf("%s\n",aux);*/
	ind = busca(aux, 0, n-1);
	if (ind == -1)
	  continue;
	else if (passou[ind] == 0 && strcmp(aux, lista[ind]) == 0) {
	  fila[ffila++] = ind;
	  passou[ind] = 1;
	  pai[ind] = atual;
	  if (ind == dest)
	    return 1;
	}
      }
    }
  }

  return 0;
}


int busca(char *a, int ini, int fim) {
  int meio = (ini+fim)/2;
  int k;
  if (ini > fim)
    return -1;

  k = strcmp(lista[meio],a);
  if (k == 0)
    return meio;
  else if (k < 0)
    return busca(a, meio+1, fim);
  else 
    return busca(a, ini, meio-1);
}

int main() {

  int i,j,k,l,m, tam, ior, idest;
  char zor[20], dest[20];

  n = 0;

  while(true) {
    fgets(lista[n],20, stdin);
    if (lista[n][0] == '\n') break;
    tam = strlen(lista[n]);
    if (lista[n][tam-1] == '\n') lista[n][tam-1] = '\0';
    n++;
  }

  qsort(lista, n, sizeof(lista[0]), comp);

  l = 0;
  while(true) {
  ini:
    zor[0] = 1;
    scanf("%s %s",zor, dest);
    if (zor[0] == 1) break;
    if (l) putchar('\n');
    l = 1;
    
    if (strlen(zor) != strlen(dest)) {
      printf("No solution.\n");
      continue;
    }
    
    ior = busca(zor, 0, n-1);
    if (ior == -1 || strcmp(lista[ior], zor) != 0) {
      printf("No solution.\n");
      goto ini;
    }
    
    idest = busca(dest, 0, n-1);
    if (idest == -1 || strcmp(lista[idest], dest) != 0) {
      printf("No solution.\n");
      goto ini;
    }

    for (i = 0; i < n; i++) {
      passou[i] = 0;
      pai[i] = i;
    }

    if (bfs(ior, idest) == 0) printf("No solution.\n");
    else imprime(idest);

  }

  return 0;

}
