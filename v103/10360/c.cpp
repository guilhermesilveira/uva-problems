
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int tam[1300][1300];

int maxi = 0;
int px,py;
int s;

void tenta(int curx,int cury,int at) {
	int j,i;
	while(cury+s<=1024) {
		if(cury!=0) {
			// diminui a linha anterior
			// soma a atual limite
			for(j=0;j<=s*2;j++) at = at - tam[curx+j][cury-1] + tam[curx+j][cury+s];
		}
		if(at>maxi) {
			maxi = at; px = curx + s; py = cury + s;
		}
		cury++;
	}
}

void start() {
	
	cin >> s;
	int i,j,p;
	for(i=0;i!=1300;i++) for(j=0;j!=1300;j++) tam[i][j]=0;
	
	int rp;
	cin >> rp;
	while(rp--) {
		cin >> i >> j >> p;
		tam[i][j] = p;
	}
	
	int curx = 0;
	int cury = 0;
	int at = 0;
	
	// soma os n primeiros
	for(i=0;i<=s*2;i++) for(j=0;j<=s*2;j++) at+=tam[i][j];
	maxi = at;
	px = curx+s;
	py = cury+s;
	while(curx+s<=1024) {
		if(curx!=0) {
			// diminui a linha anterior
			// soma a atual limite
			for(j=0;j<=s*2;j++)
				at = at - tam[curx-1][cury+j] + tam[curx+s][cury+j];
		}
		tenta(curx,cury,at);
		curx++;
	}
	cout << px << " " << py << " " << maxi << endl;
	
}



int main() {
	
	int t;
	cin >> t;
	while(t--) start();

	return 0;
	
}
