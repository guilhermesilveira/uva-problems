#include <stdio.h>

int main() {
	double d,v=0;
	for(int i=0;i!=12;i++) {
		scanf("%lf",&d);
		v += d/12;
	}
	printf("$%.2lf",v);
	return 0;
}
