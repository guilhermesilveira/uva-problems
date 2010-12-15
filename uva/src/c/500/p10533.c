#include "stdio.h"

long a,b;
long inst;
long count;

inline void digitprimo(long soma) {
	printf("%ld ",soma);
	while(soma>=10) {
		int tempSoma = soma;
		soma = 0;
		while(tempSoma!=0) {
			soma+=tempSoma%10;
			tempSoma/=10;
		}
	}
	printf("(%ld) ",soma);
/*	if(soma>10) {
		long tempSoma = soma;
		soma = 0;
		while(tempSoma!=0) {
			soma+=tempSoma%10;
			tempSoma/=10;
		}
	}*/
	if(soma==1 || soma==2 || soma==3 || soma==5 || soma==7
		|| soma==11 || soma==13 || soma==17 || soma==19 || soma==23
		|| soma==29 || soma==31 || soma==37 || soma==41 || soma==43
		|| soma==47 || soma==53) {
		count++;
	}
	//cout << soma << " ";
	/*if(!(soma==4 || soma==6 || soma==8 || soma==9)) {
		count++;
	}*/
}

int main() {
	scanf("%ld\n",&inst);
	while(inst--!=0) {
		count = 0;
		scanf("%ld %ld\n",&a,&b);
		while(a!=b+1) {
			digitprimo(a++);
		}
		printf("%ld\n",count);
	}
	return 0; 
}
