/*
 * 0221 9236665
 * 19:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char lista[26000][18];
int passou[26000], len[26000];
int n = 0;

int comp(const void *a, const void *b) {
  return strcmp((char *)a,(char *)b);
}

int busca(char *a, int ini, int fim) {
  int meio = (ini+fim)/2;
  if (ini > fim)
    return -1;
  int k = strcmp(lista[meio],a);
  if (k == 0)
    return meio;
  else if (k < 0)
    return busca(a, meio+1, fim);
  else 
    return busca(a, ini, meio-1);
}

int main() {

  int i,j,k,l,m, tam, u,z;
  char zor[20];
  while(scanf("%s",lista[n])==1) {
    n++;
  }

  qsort(lista, n, sizeof(lista[0]), comp);
  
  for (i = 0; i < n; i++) {
    passou[i] = 1;
    len[i] = strlen(lista[i]);
  }
  
  m = 1;
  
  z = n-1;

  for(i=0;i!=z;i++) {
  
  	if(passou[i] > m) m = passou[i];

  	tam = len[i];
  	for(j=0;j<=tam;j++) zor[j] = lista[i][j];
  	
  	// altera esta linha
  	for(j=0;j!=tam;j++) {
  		for(zor[j]++;zor[j]<='z';zor[j]++) {
  			if((l=busca(zor,i,n-1))!=-1) {
  				if(passou[l]<passou[i]+1) passou[l]=passou[i] + 1;
  			}
  		}
  		zor[j] = lista[i][j];
  	}

  	// remove o desta posicao
  	for(j=tam-1;j!=-1;j--) {
  		zor[j] = lista[i][j+1];
 		if((l=busca(zor,i,n-1))!=-1 && passou[l]<passou[i]+1) 
 			passou[l]=passou[i] + 1;
  	}
  	
  	// adiciona um nesta posicao
	zor[tam+1] = '\0';
  	for(j=0;j!=tam;j++) zor[j+1] = lista[i][j];
  	for(j=0;j!=tam;j++) {
		for(zor[j]=zor[j+1];zor[j]<='z';zor[j]++) {
			if((l=busca(zor,i,n-1))!=-1) {
				if(passou[l]<passou[i]+1) passou[l]=passou[i] + 1;
			}
		}
		zor[j] = lista[i][j];
  	}
  
    // adiciona na ultima posicao
	for(zor[tam]='a';zor[tam]<='z';zor[tam]++) {
		if((l=busca(zor,i,n-1))!=-1) {
			if(passou[l]<passou[i]+1) passou[l]=passou[i] + 1;
		}
	}
  	
  }
  
  printf("%d\n",m);
  
  return 0;

}
