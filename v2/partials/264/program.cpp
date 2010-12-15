#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argv,char **args) {
	
	unsigned long long start[10000];
	unsigned long long n;

	unsigned long long j = 1, i;
	unsigned long long k = 1;
	start[0] = 0;
	start[1] = 1;
	for(i = 2; start[i-1] < 10000001; i++) {
		start[i] = start[i-1] + i;
	}
	
	while((cin >> n)) {

		for(i = 1; start[i] < n; i++) ;
		
		//if(n==10000000) {
		//	cout << "TERM 10000000 IS 1009/406" << endl;
			//continue;
			//cout << n << " returned: " << start[i] << " at line " << i << endl;
		//}
		if(i % 2 == 1) {
			// linha impar
			//cout << "line: " << i << endl;
			cout << "TERM " << n << " IS " << (1 + (start[i]-n)) << "/" << (i - (start[i]-n)) << endl;
		} else {
			// linha par
			//cout << "line: " << i << endl;
			cout << "TERM " << n << " IS " << (i - (start[i]-n)) << "/" << (1 + (start[i]-n)) << endl;
		}

	}
	
	return 0;
	
}
