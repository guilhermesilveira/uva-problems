#include <iostream>
#include <math.h>

using namespace std;
long long k,n;

void start2() {
}

void start() {

	bool certo = false;
	long n;
	for(n=(long) (sqrt(k))+2;n>0;n--) {
	//	cout << "tentando com " << n << " people" << endl;
		long long tot = k;
		for(int j=1;j<=n;j++) {
//			cout << "resto: " << (tot%n) << endl;
			if(tot % n != 1) {
				//cout << "hmmm" << endl;
				// nao deu certo...
				goto fora;
			}
			tot = tot - (tot/n) -1;
		}
		if(tot%n==0) {
			// achei
			certo = true;
			break;
		}
		fora:;
	}
	
	cout << k << " coconuts";
	if(certo) {
		cout << ", " << n << " people and 1 monkey" << endl;
	} else {
		cout << ", no solution"<< endl;
	}

}

int main() {

	while(true) {
	cin >> k;
	if(k==-1) break;
	start();
	}


	return 0;

}
