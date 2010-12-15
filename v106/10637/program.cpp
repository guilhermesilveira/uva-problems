#include <stdio.h>
#include <iostream>

using namespace std;

int valores[31];
bool coprimes[101][101];
int S, t;

bool gcd(int b,int a) {

	int c;
	if(b > a) {
		c = b;
		b = a;
		a = b;
	}
	while(a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	
	return b == 1;

}

void tentaLevel(int anterior, int levelAtual, int atual) {
	
	// chegamos no ultimo nivel
	if(levelAtual == t) {
		
		int ultimoValor = S - atual, i;
		
		if(ultimoValor < anterior) {
			return;
		}
		
		for(i = 1; i != t; i++) {
			if(!coprimes[valores[i]][ultimoValor]) {
				return;
			}
		}
		
		// valido
		for(i = 1; i != t; i++) {
			printf("%d ", valores[i]);
		}
		printf("%d\n", ultimoValor);
		
		return;
		
	}
	
	int max = S - atual, i2;
	bool wasAble = false;
	
	if(anterior == 1) {
		anterior--;
	}

	for(int i = anterior + 1; i != max; ) {

		// se com (i*(t-levelAtual)) estourar, para aqui ja
		if(i * (t - levelAtual) > max) {
			break;
		}
		
		for(i2 = 1; i2 != levelAtual; i2++) {
			if(!coprimes[valores[i2]][i]) {
				goto prox;
			}
		}

		valores[levelAtual] = i;
		tentaLevel(i, levelAtual + 1, atual + i);

		prox:
		i++;

	}

}

int main(char **argv,int argc) {

	register int casos, c, i, a, b;
	bool val;
	
	for(i = 1; i != 101; i++ ) {

		for(casos = i; casos != 101; casos++ ) {

			a = casos;
			b = i;
			while((c = a % b) != 0) {
				a = b;
				b = c;
			}
			coprimes[i][casos] = (b == 1);

		}
		
	}
	
	c = 0;

	scanf(" %d",&casos);
	while(casos--!=0) {

		printf("Case %d:\n",++c);
		scanf(" %d %d", &S, &t);

		if(t == 1) {
			printf("%d\n", S);
			continue;
		}

		tentaLevel(1, 1, 0);

	}

	return 0;

}
