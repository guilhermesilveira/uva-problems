#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char val[10], c;
int valp = 0;
int valor;

bool le(int t) {
	bool b = false;
	valp = 0;
	valor = 0;
	int tz = 1;
	while(valp!=t) {
		if(c=='0' || c=='1') {
			val[valp++] = c;
			if(c=='0') {
				b = true;
			}
		}
		scanf("%c",&c);
	}
	while(--valp!=-1) {
		if(val[valp]=='1') {
			valor += tz;
		}
		tz *= 2;
	}
	return b;
}

int main(int argv,char **args) {
	
	int v[10] = {-1,0,1,4,11,26,57,120,120+127,247+255};
	char h[40000];
	char t[400000];
	int len,i,j,k,pos;
	while((cin.getline(h,40000,'\n'))) {
		//cout << "nova mensagem: " << h << endl;
		while(true) {
			// le caracter a caracter
			le(3);
			k = valor;
			if(k==0) break;
			val[3] = 0;
			//cout << val << "," << k << endl;
			while(le(k)) {
				val[k] = '\0';
				//cout << "lido: " << val << "::" << (v[k] + valor) <<endl;
				cout << h[(v[k] + valor)];
				// valor
			}
		}
		cout << endl;
		scanf(" \n ");
	}
	return 0;
	
}
