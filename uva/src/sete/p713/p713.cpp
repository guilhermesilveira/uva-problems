/* @JUDGE_ID: 39315ZN 713 C++ "Invert" */

#include <iostream>
using namespace std;

unsigned long long inverte(unsigned long long value) {
	unsigned long long int novoValue = 0;
	while(value>0) {
		novoValue = novoValue * 10 + (value % 10);
		value /= 10;
	}
	return novoValue;
}

int main(int argc, char **argv) {
   
	int inst = 0;
	cin >> inst;
	unsigned long long a;
	unsigned long long b;

	for(int i=0;i!=inst;i++) {

		cin >> a >> b;
		cout << inverte(inverte(a) + inverte(b)) << endl;

	}
   
   return 0;
   
}

