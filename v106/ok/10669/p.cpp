#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MAXD (1000)
#define QUOTE (10000)
#define QUOTE_SIZE (4)

int *tres[2000];
int tress[2000];
int *doispot[2000];
int doispots[2000];

int posi = 0;
int *posb = new int[2000];

void imprime(int *a, int tama);
int mult(int *a, int tama, int num,int *c);
int soma(int *a, int tama, int *b, int tamb, int *tamc);
int sub(int *a, int tama, int *b, int tamb,int *c);
int comp(int *a, int tama, int *b, int tamb);
int traduz(char *num, int *c);
void tenta(int *b,int tam);

int dois[100],doist=1;
int um[100],umt=1;

int main() {

	tres[0] = new int[MAXD];
    tres[0][0] = 1;
    tress[0] = 1;
    
	tres[1] = new int[MAXD];
    tres[1][0] = 3;
    tress[1] = 1;

	doispot[0] = new int[MAXD];
    doispot[0][0] = 1;
    doispots[0] = 1;
    
	doispot[1] = new int[MAXD];
    doispot[1][0] = 2;
    doispots[1] = 1;

	dois[0] = 2;
	dois[0] = 1;

    for (int i = 2; i != 2000; i++) {
	   tres[i] = new int[MAXD];
       tress[i] = mult(tres[i-1], tress[i-1], 3, tres[i]);
	   doispot[i] = new int[MAXD];
       doispots[i] = mult(doispot[i-1], doispots[i-1], 2, doispot[i]);
       //imprime(tres[i],tress[i]);
       //printf("\n\n");
    }
    
    char s[40];
    int *val = new int[MAXD];
    while((scanf("%s",s))==1) {
    	int tam = traduz(s,val);
    	if(tam==1 && val[0]==0) {
    		break;
    	} else if(tam==1 && val[0]==1) {
    		cout << "{ } " << endl;
    	} else if(tam==1 && val[0]==2) {
    		cout << "{ 1 } " << endl;
    	} else {
//    		imprime(val,tam);
//    		cout << " :: {";
    		cout << "{";
	        posi = 0;
	        tenta(val,tam);
	        for (int i = 0; i != posi; i++) {
	            if (i != 0) {
	                cout << ", ";
	            } else {
	                cout << " ";
	            }
	            imprime(tres[posb[i]],tress[posb[i]]);
	        }
    		cout << " }" << endl;
    	}
    }
    
    return 0;

}

void tenta(int *b,int tam) {
//	imprime(b,tam);
//	printf(" tentando\n");
//        System.out.println("tentando b = " + b.toString());
        if (tam==1 && b[0]==1) {
            return;
        } else if (tam==1 && b[0]==0) {
            //System.out.println("ZERO, SAINDO");
            return;
        } else if (tam==1 && b[0]==2) {
            posb[posi++] = 0;
            //System.out.println(", o valor 1, ");
            return;
        }

        int *temp = new int[100];
        int tempt;

        int *val = new int[100];
        val[0] = 2;
        int valt = 1;

		int aelevar = 1;

        int doisEl = 0;
        
        // maior ou maior ou igual?
        while (comp(val,valt,b,tam) < 0) {
            aelevar++;
            doisEl++;
            //imprime(doispot[doisEl],doispots[doisEl]);
            //cout << " somando" << endl;
            tempt = soma(doispot[doisEl],doispots[doisEl],val,valt,temp);
//            int *a = temp;
//            int at = tempt;
//            temp = val;
//            val = a;
//            valt = at;
//			imprime(temp,tempt);
//			cout << endl;
			val = temp;
			valt = tempt;
			temp = new int[100];
        }
        

//		cout << "primeiro maior: ";
	//	imprime(val,valt);
		//cout << endl;
		//cout << "tirando (-): ";
		//imprime(doispot[doisEl-1],doispots[doisEl-1]);
		//cout << endl;
		tempt = sub(b,tam,doispot[doisEl],doispots[doisEl],temp);
        tenta(temp,tempt);
        posb[posi++] = aelevar-1;
    }
    
int c[MAXD],tamc;

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
