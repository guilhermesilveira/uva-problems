#include <iostream>

using namespace std;

char m[100][102];
char p[100][102];
int mx,my;
int possivel;

void start(int lx,int ly,int ex,int ey) {

	p[ey][ex] = 1;

	possivel++;

	int i;

	// se nao esta no fim direito, tenta adiiconar um
	if(ex!=mx-1) {
		for(i=ly;i<=ey;i++) {
			if(m[i][ex+1]=='0' || p[i][ex+1]!=0) {
				// nao da
				goto na;
			}
		}
		// deu certo
		start(lx,ly,ex+1,ey);
	}
	
	na:
	if(ey!=my-1) {
		for(i=lx;i<=ex;i++) {
			if(m[ey+1][i]=='0' || p[ey+1][i]!=0) {
				// nao da
				return;
			}
		}
		// deu certo
		start(lx,ly,ex,ey+1);
	}
	
}

void zera(int x,int y) {
	for(int sy=0;sy!=my;sy++) {
		for(int sx=0;sx!=mx;sx++) {
			if(sy!=y || sx!=x) {
				p[sy][sx] = 0;
			}
		}
	}
}

int main() {

	while(true) {
		cin >> my >> mx;
		if(my==0) break;
//		cout << my << mx << endl << endl;
		for(int i=0;i!=my;i++) {
			cin >> m[i];
//			cout << m[i] << endl;
		}
		possivel = 0;
		for(int sy=0;sy!=my;sy++) {
			for(int sx=0;sx!=mx;sx++) {
				if(m[sy][sx]=='1') {
//					cout << sx << "," << sy << endl;
					zera(sx,sy);
					start(sx,sy,sx,sy);
				}
			}
		}
		cout << possivel << endl;
	}

}
