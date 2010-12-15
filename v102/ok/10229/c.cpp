#include <iostream>
#include <math.h>

using namespace std;

unsigned long long fib(unsigned long long n, unsigned long long m) {
		unsigned long long i=1,j=0,k=0,h=1,t=0;
		while(n>0) {
			if(n % 2 == 1) {
				t = j * h;
				j = (((i % m) * (h % m)) % m + (j * (k % m)) % m + (t) % m) % m;
				i = i * k + t;
			}
			t = (h * h) % m;
			h = (2 * k * h + t) % m;
			k = (k * k + t) % m;
			n = n / 2;
		}
		return j;
}

int main() {

	unsigned long long n, val, ant, antant,k, d[30];
	double sqr = sqrt(5.0);
	int m;
	d[0] = 1;
	d[1] = 2;
	for(m=2;m!=21;m++) d[m] = d[m-1] * 2;
	while((cin >> n >> m)) {
		if(n==0) cout << 0 << endl;
		else if(n==1 || n==2) cout << (1 % m) << endl;
		else {
			antant = 1;
			ant = 1;
			cout << (fib(n,d[m])) << endl;
		}
	}

}
