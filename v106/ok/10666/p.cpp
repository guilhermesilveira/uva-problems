#include <iostream>
#include <assert.h>

using namespace std;

long long n, m,mx;

long long ganhou(long long x) {
	if(x<0 || x>mx) assert(false);
	long long k = 1;
	for(long long i = 0; i <= n; i++) {
		k *= 2;
		if((x % k) != 0) {
			// ganhou
			k /= 2;
			break;
		}
	}
	//cout << x << " ganhou de " << (k-1) << endl;
	return k-1;
}

long long perdeu(long long x) {
	if(x==0) assert(false);
	if(x<0) assert(false);
	long long k = 1;
	for(long long i = 0; i <= n; i++) {
		k *= 2;
		if((x % k) != 0) {
			// perdeu
			return x - (x % k);
		}
	}
	assert(false);
}

long long o(long long x) {
	if(x==0) return 1;
	if(x % 2 == 1) o(x - 1);
	return o(perdeu(x)) + 1;
}

long long p(long long x) {
	// primeiro lugar
	if(x==0) return 1;
	// ultimo lugar
	if(x & 1 == 1) return mx + 1;
	// lugar de quem ele ganhou por ultimo - 1 (de quem ele ganhou por primeiro)
	return ((mx+1) - ganhou(x));
}

void start() {
	cin >> n >> m;
	mx = 1;
	for(long long i=0;i!=n;i++) mx *= 2;
	mx--;
	cout << o(m) << " " << p(m) << endl;
}

int main() {

	long long c;
	cin >> c;
	while(c--) start();

}
