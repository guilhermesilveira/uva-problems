#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	long long v;
	while((cin >> v) && v>=0) {
		if(v==0) cout << 1 << endl;
		else if(v==1) cout << 2 << endl;
		else if(v==2) cout << 4 << endl;
		else {
			long long l = (1+v)*v/2 + 1;
			printf("%lld\n",l);
		}
	}
	return 0;
	
}
