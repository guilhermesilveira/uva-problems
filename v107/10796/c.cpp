#include <iostream>

using namespace std;

#include <cstdio>

#define FOR(a,b) for(a=0;a<b;a++)

char mat[30][30];
bool pos[30][30];

void st() {

	int i,j,k,l;
	int sx,sy,ex,ey,kx,ky,x,y;
	int X,Y;
	char direcao[5];
	scanf("%d %d",&X,&Y);
	scanf("%d %d %d %d %d %d %s",&sy,&sx,&ey,&ex,&ky,&kx,direcao);
	
	FOR(i,Y) scanf("%s",mat[i]);
	FOR(i,Y) FOR(j,X) pos[i][j] = false;
	pos[sy][sx] = true;

	


}


int main() {

	int ins = 0;
	int t; cin >> t;
	while(t--) {
		res = -1;
		st();
		printf("Maze %d: %d\n",++ins,res);
	}
	return 0;

}
