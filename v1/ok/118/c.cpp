#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int y,x,sy,sx;
bool marc[100][100];

int d;
char dir[4];
char cmd[120];

bool forw() {
	int tx,ty;
	if(d==0) { tx=sx; ty=sy+1;}
	else if(d==1) { tx=sx+1; ty=sy;}
	else if(d==2) { tx=sx; ty=sy-1;}
	else if(d==3) { tx=sx-1; ty=sy;}
	if(tx==-1 || ty==-1 || tx>x || ty>y) {
		if(marc[sy][sx]) {
			// ignora e mantem nessa posicao
			return true;
		}
		// invalido
		return false;
	}
	// valido
	sx = tx;
	sy = ty;
	return true;
}

int main() {
	
	char *dd[4] = {"N","E","S","W"};
	cin >> x >> y;
	int i,j,k;
	for(i=0;i<=x;i++) for(j=0;j<=y;j++) marc[j][i]=false;
	
	while((cin >> sx >> sy >> dir)) {
		if(dir[0]=='N') d=0;
		else if(dir[0]=='E') d=1;
		else if(dir[0]=='S') d=2;
		else d=3;
		cin >> cmd;
		int len = strlen(cmd);
		for(i=0;i!=len;i++) {
			if(cmd[i]=='F') {
				if(!forw()) {
					// para aqui
					cout << sx << " " << sy << " " << dd[d] << " LOST" << endl;
					marc[sy][sx] = true;
					goto f;
					break;
				}
				// se foi, ok...
			} else {
				// atualiza a direcao
				if(cmd[i]=='L') d--;
				else d++;
				if(d==4) d=0;
				else if(d==-1) d=3;
			}
		}
		cout << sx << " " << sy << " " << dd[d] << endl;
		f:;
	}
	
	return 0;
	
}
