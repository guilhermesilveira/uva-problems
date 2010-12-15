#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

char pal[3][1000];
int l[3];
int k = 0;
bool ja[300][300];
#define FOR(a,b) for(int a=0;a<b;a++)

bool tenta(int a,int b,int c) {
	if(c==l[2]) return true;
	if(ja[a][b]) return false;
//	cout << a << "  " << b << endl;
	ja[a][b] = 1;
	if(pal[0][a]==pal[2][c]) if(tenta(a+1,b,c+1)) return true;
	if(pal[1][b]==pal[2][c]) if(tenta(a,b+1,c+1)) return true;
	return false;
}

bool pos() {
	
	for(int i=0;i!=3;i++) l[i] = strlen(pal[i]);
	if(l[2]!=l[0]+l[1]) return false;
	FOR(i,l[0]+2) FOR(j,l[1]+2) ja[i][j]=0;
//	cout << pal[0] << " " << pal[1] << endl;
	return tenta(0,0,0);

}

void s() {
	int i,j;
	k++;
	cin >> pal[0] >> pal[1] >> pal[2];
	cout << "Data set " << k << ":";
	if(pos()) cout << " yes\n";
	else cout << " no\n";
}

int main() {

	int t; cin >> t;
	while(t--) s();
	return 0;

}
