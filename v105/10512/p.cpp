#include <iostream>
#include <assert.h>

using namespace std;

int main() {

	long long casos, cc=1,i,j,a,b,c,d,p,q,z;
	cin >> casos;
	while(casos--) {
		cout << "Case " << cc++ << ":" << endl;
		cin >> p >> q;
		cout << p << "," << q<< endl;
		a = 4;
		b = - 4 * p - (q * q);
		c = p * p;
		d = b * b - 4 * (a * c);
		if(d<0) {
			cout << "Impossible." << endl;
		} else {
			z = (- b * sqrt(d + 0.0)) / (2 * a);
			if(z<0) {
				cout << "Impossible." << endl;
			} else {
				
			}
		}
	}
}
