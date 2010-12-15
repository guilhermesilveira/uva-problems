#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int X,Y;
char v[110][110][110];

char maior(char a,char b) {
	if(a=='R' && b=='S') return 'R';
	if(b=='R' && a=='S') return 'R';
	if(a=='R' || b=='R') return 'P';
	return 'S';
}

void at(int r,int x,int y,int dx,int dy) {
	if(x+dx<0 || y+dy<0 || x+dx>=X || y+dy>=Y) return;
	char a = v[r][y][x];
	char b = v[r][y+dy][x+dx];
	if(a==b) return;
	char c = maior(a,b);
	if(c==a) v[r+1][y+dy][x+dx]=c;
	else v[r+1][y][x]=c;
}

void gr(int r,int x,int y) {
	at(r,x,y,1,0);
	at(r,x,y,0,1);
}

int main() {

	int i,j,k,l,m,n,o,p,x,y,z=0,t,r;
	cin >> t; while(t--) {

	cin >> Y >> X >> r;
	FOR(i,Y) scanf("%s",v[0][i]);
	
	FOR(j,r) {
		FOR(x,X) FOR(y,Y) v[j+1][y][x] = v[j][y][x];
		FOR(x,X) FOR(y,Y) gr(j,x,y);
	}

	if(z) cout << endl;
	FOR(i,Y) cout << v[r][i] << endl;
	z=1;

	}
	return 0;

}
