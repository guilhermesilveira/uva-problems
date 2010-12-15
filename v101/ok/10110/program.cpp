#include <stdio.h>
#include <math.h>

// para cada n
// vai de 1 ate n
// se n for divisivel por i, altera o valor

int main(char **argv,int argc) {

	long long n;

	while(true) {
	
		scanf("%Ld\n",&n);
		
		if(n==0) {
			break;
		}
	
		//bool val = true;
	
		/*for(long long i=2; i<=n ;i++) {
			if(n % i == 0) {
				val = !val;
			}
		}*/
		
		if(sqrt(n) == (long) sqrt(n)) {
		//if(val) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	
	}

	return 0;

}
