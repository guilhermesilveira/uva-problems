#include <iostream>

using namespace std;

int n,k;

bool readInput();
void start();
unsigned long long calculaValor(int *tabuleiro);

int main(char **argv,int argc) {

	while(readInput()) {
	
		cout << n << " x " << n << endl << k << " bishops" << endl;

		if(k==0) {
			cout << "0" << endl; // ???
		} else {
			start();
		}

	}

	return 0;

}

void start() {

	

}

unsigned long long calculaValor(int *tabuleiro) {
	unsigned long long l = 0;
	for(int i=0;i!=k;i++) {
		// soma o tabuleiro elevado a
		l += doisElevadoA[i];
	}
	return l;
}


bool readInput() {

	cin >> n >> k;
	return !(n==0 && k==0);

}
