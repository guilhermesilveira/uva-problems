#include <iostream>

using namespace std;

long trans(int v,int b) {
	long n = 0;
	long t = 1;
	while(v>0) {
		n += t * (v % 10);
		v /= 10;
		t *= b;
	}
	return n;
}

long trans(int v,int b,int b1) {
	long n = 0;
	long t = 1;
	while(v>0) {
		n += t * (v % b1);
		v /= b1;
		t *= b;
	}
	return n;
}

char *ltoa(long n, char *out, int rout) {
	int p = 0;
	char temp[50];
	long t;
	while(n > 0) {
		t = n % rout;
		if(t<10) temp[p] = '0' + t;
		else temp[p] = 65 + t - 10;
		p++;
		n /= rout;
	}
	if(p==0) temp[p++] = '0';
	for(int i=0;i!=p;i++) {
		out[i] = temp[p-i-1];
	}
	out[p] = '\0';
	return out;
}

void start() {

	long b1,b2,r1,r2;
	cin >> b1 >> b2 >> r1 >> r2;
	long i,j,k,m,mm;
	mm = r2;
	for(i=mm-1;i>r1;i--) {
		m = trans(i,b2,b1);
		if(m % i==0) {
			cout << i << endl;
			return;
		}
	}
	
	cout << "Non-existent." << endl;

}

int main() {

	int t;
	cin >> t;
	while(t--) start();

	return 0;

}
