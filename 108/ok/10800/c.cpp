#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int ins = 0;
char s[100];
int v[100];
char m[200][100];

#define FOR(a,b) for(a=0;a<b;a++)

void st() {

	cout << "Case #" << ++ins << ":"<< endl;
	cin >> s;

	int i,j,k;
	k = strlen(s);

	int mi = 100, ma = 100, at = 100;

	FOR(i,200) {
		FOR(j,k) m[i][j] = ' ';
		m[i][k] = '\0';
	}
	
	FOR(i,k) {

		if(s[i]=='R') m[at][i] = '/';
		else if(s[i]=='F') m[at-1][i] = '\\';
		else m[at][i] = '_';

		if(s[i]=='R') at++;
		if(s[i]=='F') at--;

		if(at<mi) mi = at;
		if(at>ma) ma = at;

		v[i] = at;

	}

	bool ja = false;
	for(i=ma;i>=mi;i--) {
		int l = i + 100;
		for(j=k-1;j>=0;j--) {
			if(m[i][j]!=' ') break;
		}
		if(!ja && j==-1) continue;
		ja = true;
		m[i][j+1] = '\0';
		cout << "| " << m[i] << endl;
	}
	
	cout << "+-";
	FOR(i,k) cout << '-';
	cout << "-" << endl;

}

int main() {

	int t;
	cin >> t;
	while(t--) st();
	return 0;

}
