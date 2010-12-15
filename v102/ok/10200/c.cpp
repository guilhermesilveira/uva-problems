#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
	
	bool eh[10051];
	long v,sq;
	for(long i=0;i<=10050;i++) {
		v = i * i + i + 41;
		eh[i] = false;
		sq = (long) sqrt(v + 0.0) + 2;
		for(long j=3;j<sq;j+=2) {
			if(v % j==0) goto n;
		}
		eh[i]=true;
		n:;
	}
	
	long a,b;
	
	while((cin >> a >> b)) {
		
		double tot=b-a+1,val=0;
		for(int i=a;i<=b;i++) if(eh[i]) val++;
		
		double l = (val/tot*100);
		printf("%.2lf\n",l);
	}
	
	return 0;
}
