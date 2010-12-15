#include <stdio.h>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctype.h>

using namespace std;

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

class StrArray {
public:
    char **s;
    int tot;
    StrArray(int i){
        s = (char **) malloc(sizeof(char *)*i);
        clear();
    }
    void clear() {
        tot = 0;
    }
    void add(char *c) {
        s[tot++] = c;
    }
    void split(char *st, char c) {
        clear();
        bool b = false;
        char *start = st;
        while((*st)!='\0') {
            if((*st)!=c) {
                if(!b) {
                    start = st;
                    b = true;
                }
            } else {
                (*st) = '\0';
                if(b) {
                    b = false;
                    add(start);
                }
            }
            st++;
        }
        if(b) add(start);
    }
    int *toInt() {
        int *z = (int *) malloc(sizeof(int) * tot);
        for(int i=0;i!=tot;i++) z[i] = atoi(s[i]);
        return z;
    }
    long *toLong() {
        long *z = (long *) malloc(sizeof(long) * tot);
        for(int i=0;i!=tot;i++) z[i] = atol(s[i]);
        return z;
    }
};

	StrArray leit = StrArray(1000);
	
class Grupo {
public:
	int tot;
	int ind[11];
	char pal[32][11];
	int mini;
	char nome[201];
	void clear() {
		tot = 0;
	}
};

int gc;
int tot;
Grupo grupos[21];

bool comp(char *c1,char *c2) {
}

map<string,Grupo *> mapa;

void start() {

	cin >> gc;
	
	//cout << gc << endl;
	
	int i,j,k,l,m, tam, ior, idest;
	tot = 0;
	for(i=0;i!=gc;i++) {
		grupos[i].clear();
		cin >> grupos[i].nome >> j >> grupos[i].mini;
		while(j--) {
			cin >> grupos[i].pal[j];
			//cout << grupos[i].pal[j] << endl;
			tot++;
		}
	}
	
	char li[131];
	cin.getline(li,110);
	while(true) {
		cin.getline(li,110);
		int len = strlen(li);
		if(len==0 || li[0]=='\n' || li[0]=='\r') break;
//		cout << li << endl;
		leit.clear();
		leit.split(li,' ');
		for(int i=0;i!=leit.tot;i++) {
			//cout << leit.s[i] << endl;
		}
	}

}

int main() {

	cin >> n;
	while(n--) {
		start();
	}
	
	return 0;
	
}
