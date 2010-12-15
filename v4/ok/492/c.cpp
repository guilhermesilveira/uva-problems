#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool isCharacter(char c) {
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool isVocal(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
		c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int main() {

	char c;
	char primeiro;
	bool p = false;
	while(!feof(stdin)) {
		c = getchar();
		if(isCharacter(c)) {
			if(!p) {
				// nova palavra
				p = true;
				primeiro = c;
				if(isVocal(c)) putchar(c);
			} else {
				putchar(c);
			}
		} else {
			if(p) {
				// acabou a palavra
				if(isVocal(primeiro)) {
					// ignora
				}
				// imprime se for consoante
				if(!isVocal(primeiro)) {
					putchar(primeiro);
				}
				printf("ay");
				p = false;
			}
			putchar(c);
		}
	}
	if(p) {
		if(!isVocal(primeiro)) {
			putchar(primeiro);
		}
		printf("ay");
	}
	
	return 0;

}
