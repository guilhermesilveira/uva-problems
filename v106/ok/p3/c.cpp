#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	char s[100],i;
	while((cin >> s)) {
		for(i=0;i<=7;i++) s[i]-='0';
		long long c = s[7] + s[6]*10;
		c += (s[5] + s[4]*10) * 100;
		c += (s[3] + s[2]*10) * 100 * 60;
		c += (s[1] + s[0]*10) * 100 * 60 * 60;
		//cout << c << endl;
		long long t = c * 125 / 108;
		printf("%07ld\n",t);		
	}

	return 0;

}