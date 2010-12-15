#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

	int ij=0;
	long n;
	long ult,tot,j;
	int tempo;
	while((scanf("%ld",&n) && n)) {

		printf("Output for data set %d, %ld bytes:\n",++ij,n);
		tot = ult = tempo = 0;
		while(n!=0) {
			scanf("%ld",&j);
			tot++; tempo++; n -= j; ult += j;
			if(tempo==5) {
				printf("   Time remaining: ");
				if(ult==0) printf("stalled\n");
				else {
					double rate = n / (ult / 5.0);
					printf("%ld seconds\n", (long) ceil(rate));
				}
				ult = tempo = 0;
			}
		}
		printf("Total time: %ld seconds\n\n",tot);

	}
	return 0;

}
