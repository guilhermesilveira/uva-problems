#include <iostream>
#include <cmath>
using namespace std;

#define EPS (1e-5)

long roundz(double v) {
	v+=0.5;
	return (double)((long)v);
}

int main() {

	long v,p;
	while((cin >> v) && v) {

double val = log(v+0.0), b;
p = ((long) sqrt(v+0.0)) + 10;
//cout << "init;"<<p<<endl;

for(;p>1;p--) {
	b = exp(val/p);
/*	if(p<10){
	cout << p << " " << b << " " << (roundz(b)) <<endl;
	cout << (b-roundz(b)<1e-1) << endl;}*/
	if(abs(b-roundz(b))<1e-5) {
		break;
	}
}
cout << p << endl;


	}
	return 0;

}
