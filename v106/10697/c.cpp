#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

void start() {
	double x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if((x1==x2 && x2==x3 && y1==y2 && y2==y3) || (x1==x2 && y2==y1) || (x1==x3 && y3==y1) || (x3==x2 && y2==y3)) cout << "There is an infinity of possible locations." << endl;
	else if(x1*y2+x2*y3+x3*y1==x1*y3+x2*y1+x3*y2) {
		cout << "There is no possible location." << endl;
	} else {
		double v21 = x2*x2 + y2*y2 - x1*x1 - y1*y1;
		v21 /= 2;
		double v32 = x3*x3 + y3*y3 - x2*x2 - y2*y2;
		v32 /= 2;
		double b = v32 * (x2 - x1) - v21 * (x3 - x2);
		double bai = ((y1-y2)*(x3-x2)-(y2-y3)*(x2-x1));
		b /= bai;
		double a = 0;
		if(x2-x1!=0) {
			a = v21 + b * (y1 - y2);
			a /= (x2-x1);
		} else {
			a = v32 + b * (y2 - y3);
			a /= (x3-x2);
		}
		long t = (long) (a * 100);
		t += 5;
		cout << t << endl;
		cout << (t/100.0) << endl;
		a = (t / 10.0);
		t = (long) (b * 100);
		t += 5;
		b = (t / 10.0);
		printf("The equidistant location is (%.1lf, %.1lf).\n",trunc(a)/10,trunc(b)/10);
	}

}

int main() {

	int i;
	cin >> i;
	while(i--) start();
	return 0;

}
