#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	int i,j;
	
	long primos[1001];
	bool sf[1000010];
	bool fre;
	int n;
	long pc = 1;
	primos[0] = 2;
	for(i=3;i<1001;i+=2) {
		for(j=0;j!=pc;j++) {
			if((i % primos[j])==0) {
				break;
			}
		}
		if(j==pc) primos[pc++] = i;
	}
	
	return 0;
	long mu[1000010];
//	long MU[1000010];
	mu[1] = 1;
	//MU[1] = 1;
	for(i=2;i!=1000000;i++) {
		int fat = 0;
		for(j=0;j!=pc;j++) {
			if((i % primos[j])==0) {
				fat++;
				if((i/primos[j])%primos[j]==0) {
				}
			}
		}
		if(!fre) {
			mu[i] = 0;
		} else {
		if((fat%2)==0) {
			mu[i] = 1;
		} else {
			mu[i] = -1;
		}
		}
		//MU[i] = MU[i-1] + mu[i];
	}
	
	while((cin >> n)) {
		if(!n) break;
		printf("%8d%8d%8d",n,mu[n],mu[n]);
	}
	
	
	return 0;
	
}
