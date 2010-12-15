#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	char c[1000];
	long long pot2[35];
	pot2[0]=1;
	pot2[1]=2;
	for(int i=2;i!=35;i++) {
		pot2[i]=pot2[i-1]*2;
	}
	while((cin >> c)) {
		
		if(c[0]=='0' && strlen(c)==1) break;
		long long v=0;
		int len = strlen(c);
		int p = len;
		for(int i=0;i!=len;i++) {
			v += (pot2[p]-1) * (c[i]-'0');
			p--;
		}
		cout << v << endl;
		
	}

	return 0;

}

