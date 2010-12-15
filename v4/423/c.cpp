#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

long conectado[201][201];
int n;

void start() {

  int i,j,k,m;
  long l;
    char c[30];

  for(i=0;i!=n;i++) {
    conectado[i][i] = 0;
  	for(j=0;j!=i;j++) {
  		scanf(" %s",c);
  		if(c[0]=='x') {
  			l = -1;
  		} else {
  			l = atol(c);
  		}
  		conectado[i][j] = l;
  		conectado[j][i] = l;
  	}
  }
  
  for(k=0;k!=n;k++) {
	  for(i=0;i!=n;i++) {
		for(j=0;j!=n;j++) {
			if(conectado[i][k]==-1 || conectado[k][j]==-1) continue;
			if(conectado[i][j]==-1 || conectado[i][k] + conectado[k][j] < conectado[i][j]) {
				conectado[i][j] = conectado[i][k]+conectado[k][j];
				conectado[j][i] = conectado[i][k]+conectado[k][j];
			}	
		}
	  }
  }
  
  l = -1;
  
  for(i=0;i!=n;i++) {
  	if(conectado[0][i]>l) l = conectado[0][i];
//  	cout << conectado[0][i] << " ";
  }
  cout << l << endl;

}

int main() {
	scanf(" %d",&n);
	start();
	return 0;
}
