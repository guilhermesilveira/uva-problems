#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int minv;
char sc[100];

void tenta(int so) {
	
	if(so<minv) minv = so;
	if(so==0 || minv==0) return;
	
	for(int i=0;i!=11;i++) {
		if(sc[i]=='o') {
			if(sc[i+1]=='o') {
				if(i!=0) {
					if(sc[i-1]=='-') {
					sc[i-1] = 'o';
					sc[i] = '-';
					sc[i+1] = '-';
					tenta(so-1);
					sc[i-1] = '-';
					sc[i] = 'o';
					sc[i+1] = 'o';
					}
				}
				if(i+1!=11) {
					if(sc[i+2]=='-') {
					sc[i] = '-';
					sc[i+1] = '-';
					sc[i+2] = 'o';
					tenta(so-1);
					sc[i] = 'o';
					sc[i+1] = 'o';
					sc[i+2] = '-';
					}
				}
			}
		}
	}
	
}

int main() {
	
	int c, so;
	scanf(" %d ", &c);
	while(c--) {
	//	string s;
		gets(sc);
//		cin >> s;
		//sc = s.c_str();
		int i;
		so = 0;
		for(i=0;i!=12;i++) {
			if(sc[i]=='o') so++;
		}
		minv = so;
		//cout << minv << endl;
		tenta(so);
		cout << minv << endl;
	}
	return 0;
	
}

