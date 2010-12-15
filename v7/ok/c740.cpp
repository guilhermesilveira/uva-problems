#include <iostream>
#include <string.h>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int main() {
	char c[2][40],lin[100];
	cin.getline(c[0],40);
	cin.getline(c[1],40);
	int i,j,k,l,v;
	int dois[5];
	dois[0]=1; dois[1]=2; dois[2]=4; dois[3]=8; dois[4]=16;
	int estado = 0;
//	cout << c[0] << " " << c[1] << endl;
	while((cin >> lin)) {
		estado = 0;
		l = strlen(lin) / 5;
		FOR(i,l) {
			v = 0;
			FOR(j,5) {
				if(lin[i*5+j]=='1') v += dois[4-j];
			}
			if(v==31) estado = 1;
			else if(v==27) estado = 0;
			else cout << c[estado][v];
		}
		cout << endl;
	}
	return 0;
}

