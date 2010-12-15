#include <iostream>
#include <stdio.h>

using namespace std;

int main(char **argv,int argc) {

	int casos;
	cin >> casos;
	while(casos--!=0) {
	
		unsigned long long min, max;
		scanf("%Lu %Lu",&min,&max);
		
		long long val = max - min;
		//cout << "init: " << val << endl;
		
		long v = 1;
		long t = 0;
		while(val >= 2*v) {
		//	cout << "v: " << v << " e val=" << val << endl;
			val -= (2*v);
			t += 2;
			v++;
		}
		
		//cout << "fim: " << val << endl;
		
		//cout << "t: " << t << " e val=" << val << endl;
		if(val > v) {
			// v e o resto de val - v
			t += 2;
		} else if(val == v) {
			// v
			t++;
		} else if(val > 0) {
			// val eh menor que v, entao val
			t++;
		}
		
		cout << t << endl;
		
	}

	return 0;

}
