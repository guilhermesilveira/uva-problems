#include <stdio.h>

int main(char **argv,int argc) {
	
	// calculando todos os primos ate 1000000
	bool ehPrimo[1000001];
	
	for(int i=3;i!=1000001;i+=2) {
		ehPrimo[i] = true;
	}
	
	for(int i = 3; i != 1000001;i+=2) {
		if(ehPrimo[i]) {
			//printf("eh: %d\n",i);
			for(int j = i + i; j < 1000001; j += i) {
				ehPrimo[j] = false;
			}
		}
	}

	ehPrimo[2] = true;

	long t;
	long temp;
	long ttt;
	while((scanf(" %ld",&t))==1) {
		if(!ehPrimo[t]) {
			printf("%ld is not prime.\n",t); 
		} else {
			temp = t;
			ttt = 0;
			while(temp != 0) {
				ttt =  ttt * 10 + (temp % 10);
				temp /= 10;
			}
			//printf("%ld,",ttt);
			if(ttt==t || !ehPrimo[ttt]) {
				printf("%ld is prime.\n",t); 
			} else {
				printf("%ld is emirp.\n",t); 
			}
		}
	}

	return 0;

}
