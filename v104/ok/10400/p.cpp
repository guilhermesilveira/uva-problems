#include <iostream>

using namespace std;

int p;
long pn[101];
long alvo;
char si[101];

char v[111][66000];

bool tenta(int n, long tot) {

	if(v[n][tot+32005]!=0) return false;
	v[n][tot+32005] = 1;

	if(n==p) {
		if(tot==alvo) {
			return true;
		} else {
			return false;
		}
	}

	if(tot+pn[n]<=32000) {
		si[n] = '+';
		if(tenta(n+1,tot+pn[n])) return true;
	}

	if(tot-pn[n]>=-32000) {
		si[n] = '-';
		if(tenta(n+1,tot-pn[n])) return true;
	}

	if(tot*pn[n]>=-32000 && tot*pn[n]<=32000) {
		si[n] = '*';
		if(tenta(n+1,tot*pn[n])) return true;
	}

	if(pn[n]!=0 && tot % pn[n]==0) {
		si[n] = '/';
		if(tenta(n+1,tot/pn[n])) return true;
	}
	
	return false;

}

void start() {

	int i,j,k;
	cin >> p;
	for(i=0;i!=p+2;i++) for(j=0;j!=65000;j++) v[i][j] = 0;
	for(i=0;i!=p;i++) {
		cin >> pn[i];
	}
	cin >> alvo;

	if(tenta(1,pn[0])) {
		cout  << pn[0];
		for(i=1;i<p;i++) {
			cout << si[i] << pn[i];
		}
		cout << "=" << alvo << endl;
	} else {
		cout << "NO EXPRESSION" << endl;
	}
	
}

int main() {

	int t,i,j;
	cin >> t;
	while(t--!=0) {
		start();
	}

	return 0;

}
