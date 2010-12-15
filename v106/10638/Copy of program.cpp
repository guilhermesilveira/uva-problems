#include <stdio.h>
#include <iostream>

using namespace std;

int main(char **argv,int argc) {

	register int c, i, countUp, countDown, countEquals;
	double n[10], total, novaMedia;
	while(true) {

		scanf(" %d",&c);
		if(c==0) break;
		total = 0; countUp = 0; countDown = 0; countEquals = 0;

		for(i = 0; i != c; i++) {
			scanf(" %lf", &n[i]);
			total += n[i];
			//printf(" %.2lf: ", total);
		}

		//novaMedia = (((int) (total / c * 100)) + 0.0) / 100.0;
		novaMedia = (total / c * 100);
		//printf(" %lf:: ", novaMedia);
		novaMedia = ((int) novaMedia) / 100.0;
		//printf(" %lf:: ", novaMedia);
		//novaMedia = ((int) ((total / c) * 100)) / 100.0;

		for(i = 0; i != c; i++) {

			// trocar para >= 0.02??
			if(n[i] < novaMedia) {
				countDown++;
			} else if(n[i] > novaMedia) {
				countUp++;
			} else {
				countEquals++;
			}

		}
		
		if(countUp + countEquals == c || countDown + countEquals == c) {
			// ignorar
			printf("0\n");
		} else {
			printf("%d\n", countUp > countDown ? countUp : countDown);
			//printf("%.2lf %d %d %d %d\n", novaMedia, countUp, countEquals, countDown, countUp > countDown ? countUp : countDown);
		}
		
	}

	return 0;

}
