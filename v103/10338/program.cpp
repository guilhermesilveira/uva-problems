#include <stdio.h>
//#include <iostream>
#include <string.h>

int main() {
	
	register int casos, c = 1;
	scanf(" %d ",&casos);
	char linha[23];
	register int size, i;
	char existe[26];
	unsigned long long fatoriais[21];
	unsigned long long z = 1;
	for(i=2;i!=21;i++) {
		z *= i;
		fatoriais[i] = z;
//		std::cout << i << " " << fatoriais[i] << std::endl;
	}
	while(casos--!=0) {
		fgets(linha,23,stdin);
		size = strlen(linha) - 1;
		for(i = 0; i != 26; i++) {
			existe[i] = 0;
		}
		for(i = 0; i != size; i++) {
			existe[linha[i]-'A']++;
		}
		z = fatoriais[size];
		for(i = 0; i != 26; i++) {
			if(existe[i] > 1) {
				z /= fatoriais[existe[i]];
			}
		}
		printf("Data set %d: %Ld\n",c++,z);
	}
	
	return 0;
	
}
