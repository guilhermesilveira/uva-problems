#include <iostream>

using namespace std;

int main() {
	
	unsigned long long n,k;
	while((cin >> n >> k)) {
		unsigned long long tot = n;
		unsigned long long s;
		while(n>=k) {
			s = n % k;
			n /= k;
			tot+=n;
			n += s;
		}
		cout << tot << endl;
	}
	return 0;
	
}
