// 10298
// periodo de uma string

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

char s[1000003];

bool st() {

	if(!(cin >> s)) return false;
	if(s[0]=='.' && (s[1]=='\n' || s[1]=='\r' || s[1]=='\0')) return false;
	int len = strlen(s);
	int k,j,l,p;
	for(int i=0;i!=len;i++) {

		k = i + 1;
		if(len%k!=0) continue;

		for(l=0;l+k<=len;l+=k) {
			if(strncmp(s,&s[l],k)!=0) {
				goto n;
			}
		}

		cout << (len/k) << endl;
		return true;

		n:;

	}

	cout << 1 << endl;
	return true;

}

int main() {

	while(st());
	return 0;

}
