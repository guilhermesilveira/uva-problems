#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argv,char **args) {
	
	unsigned long long start[45000];
	unsigned long long n;

	unsigned long long j = 1, i;
	unsigned long long k = 1;
	start[0] = 0;
	start[1] = 1;
	for(i = 2; start[i-1] < 2000000001; i++) {
		start[i] = start[i-1] + i + (i-1);
	}
	
	while((cin >> n)) {
		
		if(n==0) break;

		for(i = 1; start[i] < n; i++) ;
		
		if(i % 2 == 1) {
			// linha impar
			unsigned long long diff = start[i] - n;
			if(diff < i) {
				cout << (1 + diff) << " " << (i) << endl;
			} else {
				cout << (i) << " " << (i + i - diff - 1) << endl;
			}
		} else {
			// linha par
			unsigned long long diff = start[i] - n;
			if(diff < i) {
				cout << (i) << " " << (1 + diff) << endl;
			} else {
				cout << (i + i - diff - 1) << " " << (i) << endl;
			}
		}

	}
	
	return 0;
	
}
