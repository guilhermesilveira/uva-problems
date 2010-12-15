#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	long long n,u,j;
	char v[1000];
	while((cin >> v)) {

		if((v[0]=='0' && (v[1]=='\n' || v[1]=='\r' || v[2]=='\0'))) break;

		int len = strlen(v);
		n = 0;

		for(int i=0;i!=len;i++) {
			if(v[i]>='0' && v[i]<='9') n += v[i] - '0';
		}


		if(v[1]=='\n' || v[1]=='\r' || v[1]=='\0') {
			cout << n << endl;
			continue;
		}

		while(n>9) {

			u = 0;
			while(n!=0) {
				j = n % 10;
				u = u + j;
				n /= 10;
			}
			n = u;

		}

		cout << n << endl;
		
	}

	return 0;

}
