#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int n,i,j;
	int d[10000];
	int mm;
	while(true) {
		scanf(" %d",&n);
		if(n==0) break;
		for(i=0;i!=n;i++) {
			scanf(" %d",&d[i]);
		}
		mm = d[0];
		j=d[0];
		for(i=1;i<n;i++) {
			if(j<0) {
				j = d[i];
			} else {
				j+=d[i];
			}
			if(j>mm) mm = j;
		}
		if(mm<=0) {
			printf("Losing streak.\n");
		} else {
			printf("The maximum winning streak is %d.\n",mm);
		}

	}
	
	return 0;
}
