#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void convN(char a) {
	char c;
	if((scanf("%c",&c))==0) return;
}

int main() {

	char c;
	while((scanf("%c",&c))==1) {
		// le um caracter
		if(c>='0' && c<='9') {
			convN(c);
		}
		else {
			convL(c);
		}
	}
	
	return 0;

}
