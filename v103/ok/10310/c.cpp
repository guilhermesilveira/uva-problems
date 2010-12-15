#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int n;
double gx,gy,dx,dy;
double h[1001][2];

double DIST(double x,double y,double x2,double y2) {
	return (x-x2)*(x-x2)+(y-y2)*(y-y2);
}

int main() {

	int i,j,k;
	while((cin >> n)) {
		cin >> gx >> gy  >> dx>>dy;
		for(i=0;i!=n;i++) {
			cin >> h[i][0] >> h[i][1];
		}
		for(i=0;i!=n;i++) {
			double d1 = DIST(h[i][0],h[i][1],gx,gy);
			double d2 = DIST(h[i][0],h[i][1],dx,dy);
			if(d1*4<=d2) break;
		}
		if(i==n) cout << "The gopher cannot escape." << endl;
		else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",h[i][0],h[i][1]);
	}
	
	return 0;
	
}
