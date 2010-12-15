#include <iostream>

using namespace std;

int main() {

	long k,n,m;
	while((cin >> n>>m)) {
		if(n==1 || m==1 || !n || !m) goto b;
		k = n;
		while(k!=1) {
			if(k % m != 0) goto b;
			k /= m;
		}
		while(n!=1) {
			cout << n << " ";
			n /= m;
		}
		cout << 1 << endl;
		continue;
		b:
			cout << "Boring!" << endl;
	}

}
