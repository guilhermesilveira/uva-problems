#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int s;
char b[100][101];
int maxArea;

void tenta(int y,int x, int y2, int x2, int area, char xp, char yp) {


	if(area > maxArea) {
		//cout << "tenta(" << y <<"," << x << "," << y2 << "," << x2 << "," << area << ")" << endl;
		maxArea = area;
	}
	
	if((s - y) * (s - x) <= maxArea) {
		return;
	}

	int i;
	
	if(y2==s-1 || yp==0) goto n;
	
	for(i=x;i<=x2;i++) {
		if(b[y2+1][i]!='.') {
			yp = 0;
			goto n;
		}
	}
	tenta(y,x,y2+1,x2,area + (x2 - x + 1),xp,1);

	n:
	
	if(x2==s-1 || xp==0) return;
	for(i=y;i<=y2;i++) {
		if(b[i][x2+1]!='.') {
			return;
		}
	}
	tenta(y,x,y2,x2+1,area + (y2 - y + 1),1,yp);


}

void start() {

	//cout << "start" << endl;

	int n,r1,r2,c1,c2,c;
	maxArea = 0;
	cin >> s;
	cin >> n;
	for(int i=0;i!=100;i++) {
		for(int j=0;j!=100;j++) {
			b[i][j] = '.';
		}
	}

	for(int z=0;z!=s;z++) {
		b[z][s] = '\0';
	}

	while(n--!=0) {

		cin >> r1 >> c1 >> r2 >> c2;
		//cout << r1 << "," << c1 << "-" << r2 << "," << c2 << endl;
		for(int r=r1;r<=r2;r++) {
			for(c=c1;c<=c2;c++) {
				b[r-1][c-1] = 'X';
			}
		}

	}
	
	/*for(int z=0;z!=s;z++) {
		for(int z2=0;z2!=s;z2++) {
			printf("%c", b[z][z2]);
		}
		printf("\n", b);
	}*/

	for(r1=0;r1!=s;r1++) {
		for(r2=0;r2!=s;r2++) {
			if(b[r1][r2]=='.') {
				tenta(r1,r2,r1,r2,1,1,1);
			}
		}
	}
	
	cout << maxArea << endl;
	
}

int main(int argc, char **argv) {

	int p;
	cin >> p;
	while(p--!=0) {
		start();
	}

	return 0;

}
