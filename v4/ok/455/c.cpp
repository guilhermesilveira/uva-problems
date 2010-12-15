// 455
// achando o menor periodo de uma string (de ate 80 caracteres)

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void st() {

	char s[100];
	cin >> s;
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

		cout << k << endl;
		return;

		n:;

	}

	cout << len << endl;

}

int main() {

	int t;
	cin >> t; while(t--) st();

}
