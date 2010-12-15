#include <stdio.h>

int main() {

	int t;
	long long a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%Ld %Ld",&a,&b);
		if(a>=b) printf("MMM BRAINS\n");
		else printf("NO BRAINS\n");
	}
	return 0;

}
