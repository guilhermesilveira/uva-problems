#include <iostream>
#include <stdio.h>

using namespace std;

int alvo;
int n;
int num[500];
bool chosen[500];
bool b;

void tenta(int l,int atual) {

	if(atual==alvo) {
		bool c = false;
		for(int i=0;i!=l;i++) {
			if(chosen[i]) {
				if(c) putchar('+');
				printf("%d",num[i]);
				c = true;
			}
		}
		putchar('\n');
		b = true;
		return;
	}

	// fim
	if(l==n) return;

	// tenta adicionando
	// se eu ignorei o anterior e ele era diferente desse, nao preciso tentar denovo!
	if(l==0 || num[l-1]!=num[l] || chosen[l-1]) {
		chosen[l] = true;
		tenta(l+1,atual+num[l]);
		chosen[l] = false;
	}
	
	// tenta sem ele
	tenta(l+1,atual);

}

int main() {

	while(true) {

		cin >> alvo >> n;

		if(!alvo && !n) break;
		for(int i=0;i!=n;i++) { cin >> num[i]; chosen[i] = false; }

		b = false;
		cout << "Sums of " << alvo << ":" << endl;
		tenta(0,0);
		if(!b) cout << "NONE" << endl;
		
	}

	return 0;

}
