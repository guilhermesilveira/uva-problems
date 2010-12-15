#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MAXD (1000)
#define QUOTE (10000)
#define QUOTE_SIZE (4)

void imprime(int *a, int tama);
int mult(int *a, int tama, int num,int *c);
int somaA(int *a, int tama, int *b, int tamb);
int soma(int *a, int tama, int *b, int tamb, int *tamc);
int sub(int *a, int tama, int *b, int tamb,int *c);
int comp(int *a, int tama, int *b, int tamb);
int traduz(char *num, int *c);
void tenta(int *b,int tam);

int main() {

	int um[MAXD],umt=1;
	um[0] = 1;
	
	int ant[MAXD], antT;
	int *at = new int[MAXD];
	int atT;
	int temp[MAXD], tempT;
	
	int k,i,j,m;
	while((cin >> k)) {
		if(k==1) {
			cout << "1" << endl;
		} else if(k==2) {
			cout << "1" << endl;
		} else if(k==3) {
			cout << "2" << endl;
		} else {
			ant[0] = at[0] = 1;
			atT = antT = 1;
			for(m=3;m<=k;m++) {
			  int cont = 0, tamc;
			  for (i = j = 0; i < atT && j < antT; i++,j++) {
			  	temp[i] = at[j];
			    at[i] += ant[j]+cont;
			    cont = at[i]/10000;
			    at[i] %= 10000;
			  }
			  while (i < atT) {
			  	temp[i] = at[i];
			    at[i] += cont;
			    cont = at[i]/10000;
			    at[i] %= 10000;
			    i++;
			  }
			  if (cont)  {
			    at[i+1] = cont;
			  }
			  tamc = i;
			  while (j < antT) {
			    at[j] += ant[j]+cont;
			    cont = at[i]/10000;
			    at[j] %= 10000;
			    j++;
			  }
			  if (cont)  {
			    at[j++] = cont;
			   // cout << j << endl;
			  }
			  antT = tamc;
			  for(i=0;i!=antT;i++) ant[i] = temp[i];
			  atT = j > i ? j : i;
			  /*cout << cont << ",";
			  imprime(ant,antT);
			  cout << " e ";
			  imprime(at,atT);
			  cout << ", m" << m << endl;*/
			}
			imprime(at,atT);
		    cout << endl;
		}
//		cout << endl;
	}

    return 0;

}

int soma(int *a, int tama, int *b, int tamb, int *c) {
  int i,j,cont = 0, tamc;
  for (i = j = 0; i < tama && j < tamb; i++,j++) {
    c[i] = a[i]+b[j]+cont;
    cont = c[i]/10000;
    c[i] = c[i]%10000;
  }
  while (i < tama) {
    c[i] = a[i]+cont;
    cont = c[i]/10000;
    c[i] = c[i]%10000;
    i++;
  }
  while (j < tamb) {
    c[j] = b[j]+cont;
    cont = c[i]/10000;
    c[j] = c[i]%10000;
    j++;
  }
  if (cont) 
    c[j++] = cont;
  tamc = j;
  return tamc;
}

int somaA(int *a, int tama, int *b, int tamb) {
  int i,j,cont = 0, tamc;
  for (i = j = 0; i < tama && j < tamb; i++,j++) {
    a[i] += b[j]+cont;
    cont = a[i]/10000;
    a[i] %= 10000;
  }
  while (i < tama) {
    a[i] += cont;
    cont = a[i]/10000;
    a[i] %= 10000;
    i++;
  }
  while (j < tamb) {
    a[j] += b[j]+cont;
    cont = a[i]/10000;
    a[j] %= 10000;
    j++;
  }
  if (cont) 
    a[j++] = cont;
  tamc = j;
  return tamc;
}

/*  a maior que b */
int sub(int *a, int tama, int *b, int tamb,int *c) {
  int tamc;
  int i,j,cont = 0;
  for (i = j = 0; i < tama && j < tamb; i++,j++) {
    c[i] = a[i]-b[j]-cont;
    if (c[i] < 0) {
      cont = 1;
      c[i] += 10000;
    }
    else
      cont = 0;
  }
  while (i < tama) {
    c[i] = a[i]-cont;
    if (c[i] < 0) {
      cont = 1;
      c[i] += 10000;
    }
    i++;
  }
  tamc = i;
  while(tamc > 1 && c[tamc-1] == 0)
    tamc--;
  return tamc;
}

int mult(int *a, int tama, int num,int *c) {
  int i,cont = 0, tamc = tama;
  for (i = 0; i < tama; i++) {
    c[i] = num*a[i] + cont;
    cont = 0;
    if (c[i] >= QUOTE) {
        cont = (c[i] / QUOTE);
        c[i] = c[i] % QUOTE;
        if (i + 1 == tamc) {
        	c[i+1] = cont;
            tamc++;
        }
    }
  }
  return tamc;
}

int comp(int *a, int tama, int *b, int tamb) {
  int i;
  if (tama > tamb)
    return 1;
  else if (tama < tamb)
    return -1;
  for (i = tama-1; i>= 0; i--) {
    if (a[i] > b[i])
      return 1;
    else if (a[i] < b[i])
      return -1;
  }
  return 0;
}

void imprime(int *a, int tama) {
  int i = tama-1;
  printf("%d",a[i]);
  for (i--; i>= 0; i--) {
    printf("%04d",a[i]);
  }
}

int traduz(char *num, int *c) {
  int i,j,tam,k, tamc=0;
  tam = strlen(num);
  for (i = tam-1; i >= 0; i--) {
    c[tamc] = 0;
    k = 1;
    for (j = 0; j < QUOTE_SIZE && i >= 0; j++,i--) {
      c[tamc] = c[tamc] + k*(num[i]-'0');
      k *= 10;
    }
    i++;
    tamc++;
  }
  return tamc;
}
