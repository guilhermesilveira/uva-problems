#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	char s[100];
	char n[100];
	int len,i,j,k;
	int dig[10];
	bool b;
	int men;

	while((cin >> s)) {

		len = strlen(s);
		b = false;
		men = -1;

		for(i=0;i!=10;i++) dig[i] = 0;

		for(i=0;i!=len;i++) {
			if(s[i]!='.') {
				j = s[i]-'0';
				if(j==9);
				//if(j==6) j = 9;
				//else if(j==0 || j==1) j = 8;
				else if(j==2) j = 5;
				dig[j]++;
				b = true;
			}
		}

		if(!b) break;

		for(i=0;i!=10;i++) if(dig[i]!=0) break;
		men = i;
		dig[men]--;

		j = 0;
		for(i=9;i>=0;i--) {
			while(dig[i]--!=0) {
				n[j++] = i+'0';
			}
		}
		n[j++]='.';
		n[j++]=men+'0';
		for(i=0;i!=j;i++) if(n[i]!=s[i]) break;
		if(i==j) {
			cout << "The price cannot be raised." << endl;
			continue;
		}
		n[j++]='\0';

		cout << n << endl;

	}

	return 0;	

}
