#include <iostream>

using namespace std;

#define MAX_PRIME2 (500001)

#define UP (1000001)

int *primo = new int[200000];
int primos = 1;

long *eh;
long long ld[1000001];

void gera2() {

	ld[1] = 1;
	ld[2] = 2;
	ld[3] = 6;
	for(int i=4;i!=1000001;i++) {
		ld[i] = ld[i-1];
		if(eh[i]==2 && ld[i]%5==0) {
			ld[i] /= 5;
		} else if(eh[i]==5 && ld[i]%2==0) {
			ld[i] /= 2;
		} else if(eh[i] > 0) {
			ld[i] = ld[i] * eh[i];
			ld[i] = ld[i] % 1000000000;
		}
	}

}

void gera3() {

	long long i,j;
	
	for( i=0;i!=UP;i++) {
		eh[i] = -1;
	}

	primos = 0;
	for(i=2;i!=UP;i++) {
		// se for primo
		if(eh[i]==-1) {
			// marca os multiplos como nao primos
			for( j = i + i; j <= UP; j += i) {
				eh[j] = -2;
			}
			// marca as potencias como especiais
			for( j = i; j <= UP && j > 0; j *= i) {
				eh[j] = i;
			}
			primo[primos++] = i;
		}
	}

}

int main() {

	eh = new long[1000001];
	gera3();
	gera2();
	while(true) {
		long t;
		cin >> t;
		if(t==0) break;
		cout << (ld[t] % 10) << endl;
	}
	
	return 0;

}
