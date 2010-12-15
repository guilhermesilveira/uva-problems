#include <iostream>
#include <assert.h>
#include <stdio.h>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int move, vis[100][100],open[100][100];
char mat[100][100][3];
int dy,dx;

void print() {
	int i,j;
	FOR(i,dy) {
		FOR(j,dx) cout << "|---";
		cout << "|" << endl;
		FOR(j,dx) cout << "| " << (open[i][j]==1 ? mat[i][j][0] : '?')<< " ";
		cout << "|" << endl;
	}
	FOR(j,dx) cout << "|---";
	cout << "|" << endl;
}

bool valido(int y,int x) {
	return !(y<0 || x<0 || y==dy || x==dx);
}

void abre(int y,int x) {
	if(valido(y,x)) open[y][x] = 1;
}

bool visitado(int y,int x) {

	// eh invalido, nao visita nao!!!
	if(!valido(y,x)) return true;

	// eh muro, nao visita nao!!!
	if(mat[y][x][0]=='X') return true;

	// se eu ja visitei, retorna true
	return vis[y][x]==1;

}

void start(int y,int x) {

	if(!valido(y,x)) return;
	vis[y][x] = open[y][x] = 1;
	move++;

	// abre os quatro cantos
	abre(y-1,x); abre(y,x+1); abre(y+1,x); abre(y,x-1);

	if(!visitado(y-1,x)) start(y-1,x);
	else if(!visitado(y,x+1)) start(y,x+1); 
	else if(!visitado(y+1,x)) start(y+1,x);
	else if(!visitado(y,x-1)) start(y,x-1);

}

int main() {
	
	int i,j,k;
	while((cin >> dy >> dx)) {
		
		if(dy==0 && dx==0) break;

		cout << endl;
		
		int y,x;
		cin >> y >> x;
		y--;x--;

		FOR(i,dy) {
			FOR(j,dx) {
				cin >> mat[i][j];
				vis[i][j] = open[i][j] = 0;
			}
		}

		move = -1;
		start(y,x);
		print();

		cout << endl << "NUMBER OF MOVEMENTS: " << move << endl;

	}
	return 0;
	
}
