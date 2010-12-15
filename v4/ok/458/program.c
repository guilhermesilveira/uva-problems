#include <stdio.h>
#include <stdlib.h>

int main(char **argv,int argc) {

	char linha[1001];
	long  size;
	long i;

	while(gets(linha)) {
	
		size = strlen(linha);
		for(i=0;i!=size;i++) {
			linha[i] = linha[i] - 7;
		}
		printf("%s\n",linha);
	
	}

	return 0;

}
