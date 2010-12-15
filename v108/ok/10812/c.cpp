#include <iostream>


using namespace std;

bool st() {
	long long c,d;
	cin >> c >> d;
	if((c+d)%2) return 0;
	long long a = (c + d) / 2;
	long long b = c - a;
	if(b<0) return 0;
	cout << a << " " << b << endl;
	return 1;
}

int main() {
	int t;
	cin >> t; while(t--) if(!st()) cout << "impossible" << endl;	return 0;
}
