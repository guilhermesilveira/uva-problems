#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int n=0,i,j,len[100],ml=0;
	char linha[100][105];

	while((gets(linha[n]))) {
		i = len[n] = strlen(linha[n]);
		while(true) {
			if(linha[n][i-1]=='\n' || linha[n][i-1]=='\r') i = --len[n];
			else break;
		}
		if(len[n]>ml) ml = len[n];
		n++;
	}

	for(i=0;i!=ml;i++) {
		for(j=n-1;j>=0;j--) {
			if(len[j]<=i) {
				putchar(' ');
			} else {
				putchar(linha[j][i]);
			}
		}
		putchar('\n');
	}

	return 0;

}
