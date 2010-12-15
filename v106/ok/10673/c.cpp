#include <iostream>
#include <assert.h>

using namespace std;

void start() {
	unsigned long long x;
	unsigned long long k;
	cin >> x >> k;
	//cout << endl << x << k << endl << endl;
	if(x % k == 0) {
		cout << 0<< " " << k << endl;
		return;
	}
	unsigned long long a = x / k;
	unsigned long long b = (x / k) + 1;
	unsigned long long f = x - a;
	unsigned long long z = 1;
	while(f>=0) {
		if(f % b == 0) {
			cout << z << " " << (f / b) << endl;
			return;
		}
		z++;
		f -= a;
	}
	assert(false);
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		start();
	}

}
