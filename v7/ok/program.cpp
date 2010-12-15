#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int num[1000000][2];
int c = 0;
bool b[10];
int t;

void tenta2(int i,int l) {
	if(l==5) {
		if(t % i != 0) return;
//		cout << t << " e " << i << endl;
		num[c][0] = t;
		num[c++][1] = i;
		return;
	}
	for(int j=0;j!=10;j++) {
		if(b[j]==false) {
			b[j] = true;
			tenta2(i * 10 + j, l + 1),
			b[j] = false;
		}
	}
}

void tenta(int i, int l) {
	if(l==5) {
		t = i;
		for(int j=0;j!=10;j++) {
			if(!b[j]) {
				b[j] = true;
				tenta2(j,1);
				b[j] = false;
			}
		}
		return;
	}
	for(int j=0;j!=10;j++) {
		if(b[j]==false) {
			b[j] = true;
			tenta(i * 10 + j, l + 1),
			b[j] = false;
		}
	}
}

void write() {
	for(int i=0;i!=10;i++) {
		b[i] = true;
		tenta(i,1);
		b[i] = false;
	}
}

string tos(int i) {
	string s = "";
	int k;
	while(i!=0) {
		k = i % 10;
		i /= 10;
		s = ((char)(k + '0')) + s;
	}
	while(s.size()!=5) {
		s = "0" + s;
	}
	return s;
}

int main(char **argv,int argc) {

	write();
//	cout << c << endl;

	int n,i,t=0;
	while(true) {
		cin >> n;
		if(n==0) break;
		if(t++!=0) cout << endl;
		bool b = false;
		for(i=0;i!=c;i++) {
			if(num[i][0] / num[i][1] == n) {
				cout << tos(num[i][0]) << " / " << tos(num[i][1]) << " = " << n << endl;
				b = true;
			}
		}
		if(!b) {
			cout << "There are no solutions for " << n << "." << endl;
		}
	}

	return 0;

}

