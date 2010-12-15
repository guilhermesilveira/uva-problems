#include <iostream>
#include <stdio.h>
#include <math.h>

// TODO MELHORAR O TEMPO COM CHAR *

#define CACHE 47000

using namespace std;

int main (char **argv, int argc) {

  bool ehPrimo[CACHE];
  register int i;
  register int i2;
  register int k;
  
  ehPrimo[2] = true;
  for(i = 3; i < CACHE; i += 2) {
  	ehPrimo[i] = true;
  }
	
  for(i = 3;i < CACHE; i += 2) {
  	if(ehPrimo[i]) {
	  for(i2 = i + i + i; i2 < CACHE; i2 += i + i) {
	    ehPrimo[i2] = false;
	  }
  	}
  }

  while(true) {
  	
  	cin >> k;
  	if(k==0) break;
  	
  	bool appeared = false;
  	
  	printf("%d =",k);
  	
  	if(k < 0) {
  		printf(" -1");
  		k = -1 * k;
  		appeared = true;
  	}
  	
  	if(k < CACHE && ehPrimo[k]) {
  		if(appeared) {
  			printf(" x %d\n",k);
		} else {
  			printf(" %d\n",k);
		}
  		continue;
  	}
  	
  	while(k % 2 == 0) {

  		k = k / 2;
  		if(appeared) {
  			printf(" x 2");
  		} else {
  			printf(" 2");
	  		appeared = true;
  		}

  	}
  	
  	int sq = (int) sqrt(k + 0.0);
  	for(i = 3; i <= sq; i += 2) {
  		
  		if(!ehPrimo[i]) { continue; }
  		
	  	if(k < CACHE && ehPrimo[k]) {
	  		if(appeared) {
  				printf(" x %d",k);
			} else {
  				printf(" %d",k);
			}
  			k = 1;
			break;
	  	}
  	
  		while(k % i == 0) {
	  		if(appeared) {
  				printf(" x %d",i);
			} else {
  				printf(" %d",i);
  				appeared = true;
			}
  			k = k / i;
  			sq = (int) sqrt(k + 0.0);
  		}
  		
  	}
  	
  	if(k!=1) {
  		if(appeared) {
  			printf(" x %d\n",k);
		} else {
  			printf(" %d\n",k);
		}
		continue;
  	}

  	cout << endl;
  	
  }
	
  return 0;

}
