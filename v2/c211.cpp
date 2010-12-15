#include <iostream>
#include <stdio.h>
#define FOR(a,b) for(a=0;a!=b;a++)

using namespace std;

// original value
int val[7][8];
// already used???
bool usado[7][8];
int tot = 0;

int mapa[29][2];
int quem[7][8];
int ps[7][7];
bool peca[17][17];

void gera() {
	int c = 0;
	int a = 0,b = 0;
	while(!(a==7 && b==7)) {
		mapa[c][0] = a;
		ps[a][b] = c;
		mapa[c++][1] = b;
		if(++b==7) {
			a++; b = a;
		}
	}
}

#define MEN(a,b) (a<b?a:b)
#define MAI(a,b) (a>b?a:b)
#define calcp(a,b,c,d) a=MEN(c,d); b=MAI(c,d);
void vai(int y,int x) {
	
	if(x==8) {
		vai(y+1,0);
		return;
	}
	
	if(y==7 && x==0) {
		// terminou!!! valido!
		for(int i=0;i!=7;i++) {
			cout << " ";
			for(int j=0;j!=8;j++) {
				printf("%4d",quem[i][j]+1);
			}
			cout << endl;
		}
		cout << endl;
		tot++;
		return;
	}
	
	if(usado[y][x]) {
		vai(y,x+1);
		return;
	}
	
	usado[y][x] = true;
	
	int v1,v2;
	
	// tenta colocar de pe
	if(y!=6) {
		calcp(v1,v2,val[y][x],val[y+1][x]);
		// se eu nao usei a peca
		if(!peca[v1][v2]) {
			peca[v1][v2] = true;
			usado[y+1][x] = true;
			quem[y][x] = ps[v1][v2];
			quem[y+1][x] = ps[v1][v2];
			vai(y,x+1);
			usado[y+1][x] = false;
			peca[v1][v2] = false;
		}
	}
	
	// tenta colocar deitado
	if(x!=7) {
		// se eu nao usei
		if(!usado[y][x+1]) {
			calcp(v1,v2,val[y][x],val[y][x+1]);
			// se eu nao usei a peca
			if(!peca[v1][v2]) {
				peca[v1][v2] = true;
				usado[y][x+1] = true;
				quem[y][x] = ps[v1][v2];
				quem[y][x+1] = ps[v1][v2];
				vai(y,x+1);
				usado[y][x+1] = false;
				peca[v1][v2] = false;
			}
		}
	}
	
	usado[y][x] = false;
	
}

int main() {
	
	int i,j,k;
	int inst = 0;
	
	gera();
	
	while(true) {
		FOR(i,7) {
			FOR(j,8) {
				if(!(cin >> val[i][j])) return 0;
				usado[i][j] = false;
				peca[i][j] = false;
			}
		}
		tot = 0;
		cout << "Layout #" << ++inst << ":" << endl << endl << endl;
		FOR(i,7) {
			cout << " ";
			FOR(j,8) 
				printf("%4d",val[i][j]);
			cout << endl;
		}
		cout << endl << endl;
		cout << "Maps resulting from layout #" << inst << " are:" << endl << endl;
		vai(0,0);
		cout << "There are " << tot << " solution(s) for layout #" << inst << "." << endl << endl;
		cout << endl << endl;
	}
	
	return 0;
	
}
