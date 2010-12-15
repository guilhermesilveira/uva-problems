#include <stdio.h>
#include <iostream>

using namespace std;

int n,h;

char linha[100];

void doIt(int level,int falta1) {
	if(n==level) {
		if(!falta1) {
			printf("%s\n",linha);
		}
		return;
	}
	if(n-level<falta1) return;
	linha[level] = '0';
	doIt(level+1,falta1);
	if(falta1!=0) {
		linha[level] = '1';
		doIt(level+1,falta1-1);
	}
}

int main() {
	int t,inst=0;
	cin >> t;
	while(t--) {
		cin >> n >> h;
		linha[n] = '\0';
		if(inst++!=0) cout << endl;
		doIt(0,h);
	}
	return 0;
	
}
