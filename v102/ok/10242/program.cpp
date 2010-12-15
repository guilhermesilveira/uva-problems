#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define TROCA(a,b,c,d) temp=a;a=b;b=temp;temp=c;c=d;d=temp;

int main(char **argv,int argc) {
	
	double x1,y1, x2,y2;
	double x21,y21, x22,y22;
	double posX,posY;
	double temp;
	
	while((cin >> x1 >> y1 >> x2 >> y2 >> x21 >> y21 >> x22 >> y22)) {
		
		if(x1==x21 && y1==y21) {
			TROCA(x1,x2,y1,y2);
		} else if(x2==x22 && y2==y22) {
			TROCA(x21,x22,y21,y22);
		} else if(x1==x22 && y1==y22) {
			TROCA(x1,x2,y1,y2);
			TROCA(x21,x22,y21,y22);
		}
		
		posX = x1 - (x21 - x22);
		posY = y1 - (y21 - y22);

		printf("%.3lf %.3lf\n",floor(posX * 1000 + 0.5) / 1000,floor(posY * 1000 + 0.5) / 1000);

	}

	return 0;

}
