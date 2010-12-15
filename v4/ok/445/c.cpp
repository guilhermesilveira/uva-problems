#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int i=0;
	char c;
	while((c = getchar())!=-1) {
		if(c>='0' && c<='9') {
			i += c - '0';
		} else if(c=='\n' || c=='!') {
			putchar('\n');
		} else if(c=='b') {
			while(i--) {
				putchar(' ');
			}
			i=0;
		} else {
			while(i--) {
				putchar(c);
			}
			i=0;
		}
	}

	return 0;
	
}
