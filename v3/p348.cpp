#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/* algoritmo iterativo para a solucao do problema */
void metodoIterativo (int n);

/* gera a expressao */
void geraExpressao (int n);

int k[32][32];

int
main (int numargs, char **arg)
{


  int n, instancia = 0;
  while(true) {
  	
  	cin >> n;
  	if(n==0) break;
  	
    /* cabecalho */
    cout << "Case " << ++instancia << ": ";
    metodoIterativo (n);
    cout << endl;

  }

  return 0;

}

void
metodoIterativo (int n)
{

  int i, j, kAtual;
  unsigned long long menor, atual;
	unsigned long long m[33][33];
	unsigned long long d[33];
  for (i = 0; i != n; i++) {
  	cin >> d[i];
  	cin >> atual;
    for (j = 0; j != n; j++) {
    	k[i][j] = 0;
    }
    m[i][i] = 0;
  }
  d[i] = atual;

  /* para cada j */
  for (j = 0; j != n; j++) {

    /* para cada i, decrescendo */
    for (i = j - 1; i >= 0; i--) {

      menor = 4219999999;
      k[i][j] = -1;

      /* acha o menor valor para essa posicao e guarda */
      for (kAtual = i; kAtual != j; kAtual++) {

        atual =
          m[i][kAtual] + m[kAtual + 1][j] + d[i] * d[kAtual +
                                                     1] * d[j +
                                                            1];
        if (atual < menor) {
          menor = atual;
          k[i][j] = kAtual;
        }

      }
      
      if(k[i][j]==-1) while(true);

      m[i][j] = menor;

    }

  }

    /* expressao */
    geraExpressao (n);

}

void
geraExpressaoPasso (int n, 
                    int i, int j)
{
	
  if (i == j) {
    cout << "A" << (i+1);
    return;
  }
  
  cout << "(";
  geraExpressaoPasso (n, i, k[i][j]);
  cout << " x ";
  geraExpressaoPasso (n, k[i][j] + 1, j);
  cout << ")";

}

void geraExpressao (int n) {
  geraExpressaoPasso (n, 0, n - 1);
}


