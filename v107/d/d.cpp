#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

char lin[1000];
char rep[300];
char decr[300];
int len;

void start() {
	char c;
	for(int i=0;i!=300;i++) {
		decr[i] = 0;
	}
	int max = len / 2;
	int mex = 0,k,def = 0,defpos=0;
	for(int i=0;i!=max;i++) {
		c = lin[i];
		// acha o primeiro c que esta na esquerda, sai mechendo ele para a direita
		bool achei = false;
//		cout << lin << " procura " << c << " entre " << (len-i-1)<< " - " << mex << endl;
		for(int j=len-i-1;j>i;j--) {
			if(lin[j]==c) {
				//cout << "achei em " << j << endl;
				achei = true;
				for(k=j;k<len-i-1;k++) {
	//				cout << k << endl;
					lin[k] = lin[k+1];
					mex++;
				}
				lin[len-i-1] = c;
				break;
			}
		}
		if(!achei) {
			// essa eh a que vai para o meio... como ignorar???
			for(k=i;k<len/2;k++) {
				lin[k] = lin[k+1];
				mex++;
			}
			lin[len/2] = c;
		}
	}
	cout << mex << endl;
}

bool poss() {
	cin >> lin;
	len = strlen(lin);
	for(int i='a';i<='z';i++) rep[i] = 0;
	for(int i=0;i!=len;i++) {
		rep[lin[i]]++;
	}
	bool a = false;
	for(int i='a';i<='z';i++) {
		if(rep[i]%2!=0) {
			if(a || len%2==0) return false;
			a = true;
			rep[i] = rep[i] / 2 + 1;
		} else {
			rep[i] /= 2;
		}
	}
	return true;
}

int main () {
	
	int t;
	scanf("%d\n",&t);

	while(t--) {
		if(!poss()) cout << "Impossible" << endl;
		else start();
	}
	
	return 0;
	
}
