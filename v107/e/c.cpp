#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int coins, c[100],deslen;

void start() {
	int maxi[100];
	int i,j,k,mz = 0;
	int maior = 0;
	for(i=0;i!=coins;i++) {
		maxi[i] = deslen - (deslen % c[i]);
		if(maxi[i] <= deslen && maxi[i]> maior) { maior = maxi[i]; mz = i; }
	}
	if(mz==0) maior = maxi[0];
	
}

int main () {
	
	int dlen,i;
	while(true) {
		cin >> coins >> dlen;
		if(!coins && !dlen) return 0;
		for(i=0;i!=coins;i++) cin >> c[i];
		for(i=0;i!=dlen;i++) {
			cin >> deslen;
			start();
		}
	}
	
	
	return 0;
	
}
