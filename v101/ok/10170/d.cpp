#include <iostream>
#include <cmath>

using namespace std;

int main() {

	long long a,b;
	while((cin >> a >> b)) {
		b -= a;
		while(b>0) {
			a++;
			b -= a;
			//cout << b << " " << a << endl;
		}
		cout << a << endl;
	}
	return 0;

}
