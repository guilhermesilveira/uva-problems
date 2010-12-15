#include <iostream>

using namespace std;

int main() {

	int t,a,b,i = 0;
	long long v;
	cin >> t;
	while(t--) {

		cin >> a >> b;
		if(a==b && a%2) v = a;
		else if(a==b) v = 0;
		else {
			if((a%2==0)) a++;
			if((b%2==0)) b--;
			v = (b-a)/2 + 1;
			v = (a+b)*v/2;
		}
		cout << "Case " << ++i << ": " << v << endl;

	}
	return 0;

}
