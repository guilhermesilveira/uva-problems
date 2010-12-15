#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

char mapa[200][200];
bool vis[200][200];
int m,n;
int tot;

#define FOR(a,b) for(a=0;a!=b;a++)

void tenta(int y,int x) {
	if(y<0 || x<0 || y==m || x==n) return;
	if(vis[y][x]) return;
	vis[y][x]=1;
	if(mapa[y][x]=='@') {
		tenta(y+1,x-1);
		tenta(y+1,x+1);
		tenta(y+1,x);
		tenta(y-1,x);
		tenta(y-1,x-1);
		tenta(y-1,x+1);
		tenta(y,x+1);
		tenta(y,x-1);
	}
}

int main() {
	
	int i,j;
	while((cin >> m) && m) {
		cin >> n;
		tot = 0;
		FOR(i,m) FOR(j,n) vis[i][j] = 0;
		FOR(i,m) cin >> mapa[i];
		FOR(i,m) FOR(j,n) if(!vis[i][j] && mapa[i][j]=='@') { tot++; tenta(i,j); }
		cout << tot << endl;
	}
	return 0;
	
}
