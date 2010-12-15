#include <iostream>

using namespace std;

int main() {

	int n;
	int val[20000];
	val[1] = 1;
	int j = 2,k;
	for(int i=2;true;i++) {
		k = i;
		while(k--) val[j] = val[(j++) - 1] + i;
		if(j>10000) break;
	}
	while((cin >> n)  && n) {
		cout << n << " " << val[n] << endl;
	}
	return 0;

}
