#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

char lista[200][20];
int tam[200];
int conectado[201][201];
int n;

int busca(char *a, int ini, int fim);

int comp(const void *a, const void *b) {
  char *aa = (char *)a;
  char *bb = (char *)b;
  return strcmp(aa,bb);
}

int diferenca(char *s1, int t1, char *s2, int t2) {
	if(t1!=t2) return -1;
	int d = 0;
	for(int i=0;i!=t1;i++) {
		if(s1[i]!=s2[i]) {
			d++; if(d!=1) return d;
		}
	}
	return d;
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

void limpa(char *s) {
    int tam = strlen(s);
    if (s[tam-2] == '\r') { s[tam-2] = '\0'; return; }
    if (s[tam-1] == '\n') s[tam-1] = '\0';
}

void start() {

  int i,j,k,l,m, ior, idest;
  char zor[20], dest[20], line[100];

  n = 0;

  while(true) {
    fgets(lista[n],20, stdin);
    if (lista[n][0] == '*') break;
    limpa(lista[n]);
    n++;
  }

  qsort(lista, n, sizeof(lista[0]), comp);
  
  for(i=0;i!=n;i++) {
  	tam[i] = strlen(lista[i]);
  }

  for(i=0;i!=n;i++) {
  	conectado[i][i] = 1;
	for(j=i+1;j<n;j++) {
		if(diferenca(lista[i],tam[i],lista[j],tam[j])==1) {
			conectado[i][j] = 1;
			conectado[j][i] = 1;
		} else {
			conectado[i][j] = 1000;
			conectado[j][i] = 1000;
		}
	}
  }

  for(k=0;k!=n;k++) {
	  for(i=0;i!=n;i++) {
		for(j=0;j!=n;j++) {
			if(conectado[i][k]==1000 || conectado[k][j]==1000) continue;
			if(conectado[i][k] + conectado[k][j] < conectado[i][j]) {
				conectado[i][j] = conectado[i][k]+conectado[k][j];
				conectado[j][i] = conectado[i][k]+conectado[k][j];
			}	
		}
	  }
  }

  l = 0;
  int o = 0;
  while(true) {
  ini:
    zor[0] = 1;
    if(!(fgets(line,200,stdin))) break;
    if(line[0]=='\n') break;
    sscanf(line,"%s %s",zor, dest);
    if (zor[0] == 1) break;
    
    limpa(zor); limpa(dest);
    
    if(strcmp(zor,dest)==0) goto zero;
    
    if (strlen(zor) != strlen(dest)) {
      assert(false);
      goto zero;
    }
    
    ior = busca(zor, 0, n-1);
    if (ior == -1 || strcmp(lista[ior], zor) != 0) {
      assert(false);
      goto zero;
    }
    
    idest = busca(dest, 0, n-1);
    if (idest == -1 || strcmp(lista[idest], dest) != 0) {
      assert(false);
      goto zero;
    }

    if ((i=conectado[ior][idest]) >= 1000) {
    zero:
    	printf("%s %s 0\n",zor,dest);
    } else 
    	printf("%s %s %d\n",zor,dest,i);

  }

}

int main() {
	int t;
	scanf("%d",&t); while(t--) { scanf(" "); start(); if(t!=0) putchar('\n'); }
	return 0;
}
