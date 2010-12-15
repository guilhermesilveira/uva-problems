// ADD BIG INTEGER

#include <iostream>
#include <assert.h>

using namespace std;

int main() {

	unsigned long long n,i,j,a,b,c,d,p,q,z,s,cc=1,cases;
	unsigned long long pa[10000];
	cin >> cases;
	while((cin >> n)) {
		a = n;
		c = 1;
		pa[0] = n;
		while(a!=1) {
			b = a;
			a = 0;
			while(b!=0) {
				a += (b % 10) * (b % 10);
				b /= 10;
			}
			//cout << a << endl;
			for(i=0;i!=c;i++) {
				if(pa[i]==a) {
					cout << "Case #" << cc++ << ": " << n << " is an Unhappy number." << endl;
					goto nz;
				}
			}
			pa[c++] = a;
		}
		cout << "Case #" << cc++ << ": " << n << " is a Happy number." << endl;
		nz:
		if(!--cases) break;
	}
}
