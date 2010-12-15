#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define FOR(a,b,c) for(a=b;a<c;a++)

char l[50];
bool v[110][110];

void st() {

	int p,t,i,j,k,m;
	gets(l);
	sscanf(l,"%d %d",&p,&t);

	FOR(i,0,p) FOR(j,0,t) v[i][j] = false;

	while(true) {

		if(!(gets(l))) break;
		if(strlen(l)==0 || l[0]=='\r' || l[0]=='\n') break;
		sscanf(l,"%d %d",&i,&j);
		i--; j--;
//		cout << i << " " << j << endl;
		v[i][j] = true;

	}

/*	FOR(i,0,p) {
		FOR(j,0,t) cout << v[i][j] << " ";
		cout << endl;
	}*/

	k = 0;
	bool igual;
	FOR(i,0,p) {
//		cout << "tentando " << i << endl;
		FOR(j,0,i) {
			igual = true;
			FOR(m,0,t) {
				if(v[i][m]!=v[j][m]) {
					igual = false;
					break;
				}
			}
			if(igual) goto n;
		}
//		cout << i << endl;
		k++;
		n:;
	}
	cout << k << endl;

}

int main() {

	int t;
	cin >> t;
	scanf(" ");
	while(t--) {
		st();
		if(t!=0) cout << endl;
	}
	return 0;

}
