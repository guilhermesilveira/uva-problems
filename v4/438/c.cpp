#include <iostream>
#include <math.h>

#define PI (2*acos(0.0))

using namespace std;

#define D(y) ((q[y]-q[(y+1)%3])*(q[y]-q[(y+1)%3])+(w[y]-w[(y+1)%3])*(w[y]-w[(y+1)%3]))

int main() {
	
	double q[3],w[3];
	while((cin >> q[0]>>w[0]>> q[1]>>w[1]>> q[2]>>w[2])) {
		double a=D(0),b=D(1),c=D(2);
		cout << a << " " << b << " " << c << " " << endl;
		double s = (a+b+c)/2.0;
		cout << "s=" << s << endl;
		cout << s*(s-a)*(s-b)*(s-c) << endl;
		double l = sqrt(s*(s-a)*(s-b)*(s-c));
		cout << l << endl;
		double r = (a*b*c)/(4*l);
		cout << (2*PI*r) << endl;
	}
	return 0;
	
}
