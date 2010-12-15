#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const double &c1, const double &c2) {

	return c1 > c2;
	

}

int main(char **argv,int argc) {

	int c, i, countUp, countDown, countEquals, movimentos;
	double total, media, parcial;
	while(true) {

		scanf(" %d",&c);
		if(c==0) break;
		total = 0; countUp = 0; countDown = 0; countEquals = 0;
		movimentos = 0;

		printf("\nnovo %d\n", c);

		vector<double> n;
		for(i = 0; i != c; i++) {
			double ni;
			scanf(" %lf", &ni);
			total += ni;
			ni *= 100;
			n.push_back(ni);
			// arrendonda o cara
//			printf("%d %.2lf\n", i, n[i]);
		}

		media = ((total * 100) / c);
		media = (long) media;
		// TODO ROUND?
//		printf("media:: %lf %lf\n", total,media);
		cout << media << endl;

		sort(n.begin(),n.end(),comp);

		// para cada cara com valor maior
		for(i = 0; i != c; i++) {

			cout << n[i] << endl;
			if(n[i] < media) {

				countDown++;

			} else if(n[i] > media) {

				// especial: procura cara menores e balanceia eles
				double z = n[i] - media;
				cout << i << " tem maior: " << z << endl;
				for(int i2 = 0; i2 != c; i2++) {
					
					if(n[i2] < media) {
						
						cout << i2 << " vai receber" << endl;
						
						if(media - n[i2] > z) {
							n[i2] += z;
							z = 0;
						} else {
							z -= (media - n[i2]);
							n[i2] = media;
						}
//						cout << i2 << " terminou com: " << n[i2] << endl;
						movimentos++;
						
						if(z == 0) {
							break;
						}
					}
					
				}
				//cout << i << " terminou com: " << z << endl;
				countUp++;

			} else {
				
				countEquals++;
				
			}

		}
		
		printf("%d\n",movimentos);
		
	}

	return 0;

}
