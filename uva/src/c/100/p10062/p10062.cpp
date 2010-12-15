/* @JUDGE_ID: 39315ZN 10062 C++ "Do it" */

#include <stdio.h>
#include <vector.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct caracter {
	int c;
	int vezes;
};

bool ordenadora(const caracter &c1, const caracter &c2) {
	return c1.vezes==c2.vezes? c1.c>c2.c : c1.vezes < c2.vezes;
}

int ordena(int aparicoes[256]) {
	
	vector<caracter> ordenados;

	for(int i=0;i!=256;i++) {
		if(aparicoes[i]>0) {
			caracter c;
			c.c = i;
			c.vezes = aparicoes[i];
			ordenados.insert(ordenados.end(),c);
		}
	}
	
	sort(ordenados.begin(),ordenados.end(),ordenadora);
	
	for(int i=0;i!=ordenados.size();i++) {
		cout << (ordenados[i].c) << " " << ordenados[i].vezes << endl;
	}
	
	return 0;
}

int main(int argc, char **argv) {
	
	int i = 0;

	char linha[1001];
	int aparicoes[256];
	int primeiraLinha = 1;
	
	while(scanf("%s\n",linha)==1) {
		
		if(primeiraLinha!=1) {
			cout << endl;
		}
		
		for(i=0;i!=256;i++) {
			aparicoes[i]=0;
		}
		
		for(i=0;linha[i]!=0;i++) {
			if(linha[i]>=32 && linha[i]<=127)
				aparicoes[linha[i]]++;
		}
		
		ordena(aparicoes);
		
		primeiraLinha = 0;
		
	}
	
	return 0;
	
}

