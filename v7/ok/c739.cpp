#include <stdio.h>
#include <iostream>

using namespace std;

int enc(char c) {
	if(c=='R') return 6;
	if(c=='M' || c=='N') return 5;
	if(c=='L') return 4;
	if(c=='D' || c=='T') return 3;
	if(c=='C' || c=='Z') return 2;
	if(c=='S' || c=='X') return 2;
	if(c=='K' || c=='Q') return 2;
	if(c=='G' || c=='J') return 2;
	if(c=='B' || c=='P') return 1;
	if(c=='F' || c=='V') return 1;
	return -1;
}

int main() {
	
	char s[30];
	int len,i;
	char code[30];
	char clen;
	int lcode;
	cout << "         NAME                     SOUNDEX CODE" << endl;
	while((cin >> s)) {
		len = strlen(s);
		code[0] = s[0];
		clen = 1;
		lcode = enc(s[0]);
		for(i=1;i<len;i++) {
			int novo = enc(s[i]);
			if(novo==-1) {
				lcode = -1;
				continue;
			}
			//cout << "li: " << novo << endl;
			if(lcode==-1 || novo!=lcode) {
				//cout << "add: " << novo << ": " << clen << endl;
				lcode = novo;
				code[clen++] = '0' + novo;
			}
			if(clen==5) break;
		}
		while(clen<4) {
			code[clen++]='0';
		}
		code[4] = '\0';
		cout << "         " << s;
		while(len++!=25) putchar(' ');
		cout << code << endl;
	}
	cout << "                   END OF OUTPUT" << endl;
	return 0;
	
}
