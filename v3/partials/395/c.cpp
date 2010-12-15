#include <iostream>
#include <stdio.h>

using namespace std;

char lines[10][10];
char s[5];

int hor[10];
int ver[10];
int diag[10][10];
int odiag[10][10];

int p;

char car(int i) {
	return 'A' + i;
}

void possivel(int y,int x,int dy, int dx, int t) {
	int py=y,px=x;
	for(int i=0;i!=t;i++) {
		py += dy;
		px += dx;
		if(py<0 || py==8) return;
		if(px<0 || px==8) return;
		if(lines[py][px]!='.' && lines[py][px]!=s[0]) {
			// nao pode
			return;
		}
	}
	if(lines[py][px]==s[0]) {
		// nao pode
		return;
	}
	cout << car(y) << (x+1) << "-" << car(py) << (px+1) << endl;
	p++;
}

void tenta(int y,int x) {
	
	cout << "comeca em " << y << "," << x << endl;
	possivel(y,x,-1,-1,diag[y][x]);
	possivel(y,x,-1,0,ver[x]);
	possivel(y,x,0,-1,hor[x]);
	possivel(y,x,0,1,hor[x]);
	possivel(y,x,1,0,ver[x]);
	possivel(y,x,1,1,diag[y][x]);
	possivel(y,x,-1,1,odiag[y][x]);
	possivel(y,x,1,-1,odiag[y][x]);
	
}

void sh(int y) {
	hor[y] = 0;
	for(int i=0;i!=8;i++) {
		if(lines[y][i]!='.') hor[y]++;
	}
}

void sv(int x) {
	ver[x] = 0;
	for(int i=0;i!=8;i++) {
		if(lines[i][x]!='.') ver[x]++;
	}
}

void sd(int y,int x) {
	diag[y][x] = 0;
	for(int i=-8;i<=8;i++) {
		if(y+i<0 || x+i<0 || y+i>=8 || x+i>=8) continue;
		if(lines[y+i][x+i]!='.') diag[y][x]++;
	}
	odiag[y][x] = 0;
	for(int i=-8;i<=8;i++) {
		if(y+i<0 || x+i<0 || y+i>=8 || x+i>=8) continue;
		if(lines[y+i][x-i]!='.') odiag[y][x]++;
	}
}

int main() {

	int t = 0;
	while((cin >> lines[0])) {
		if(t++) cout << endl;
		for(int i=1;i!=8;i++) cin >> lines[i];
		cin >> s;
		p = 0;
		for(int i=0;i!=8;i++) {
			sh(i); sv(i);
			for(int j=0;j!=8;j++) {
				sd(i,j);
			}
		}
		for(int i=0;i!=8;i++) {
			for(int j=0;j!=8;j++) {
				if(lines[i][j]==s[0]) tenta(i,j);
			}
		}
		if(!p) {
			cout << "No moves are possible" << endl;
		}
	}

	return 0;
	
}
