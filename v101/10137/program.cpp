#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int main(char **argv,int argc) {

	int n;
	vector<long double> valores;
	long double valor;
	long double media;
	
	long double totalAlto;
	long double totalBaixo;
	int i;

	while(true) {
	
		scanf("%d\n",&n);
		
		if(n==0) {
			break;
		}
		
		media = 0;		
		valores.clear();
	
		for(i=0;i!=n;i++) {
			scanf("%Lf",&valor);
			valores.push_back(valor);
			media += valor;
		}
		
		media = media/n;
		//cout << media << endl;
		// arredonda a media agora em duas casas
		media = media * 100;
		//cout << media << endl;
		media = (int) media / 100.00;
		//media = ((int) (media * 100)) / 100;
		//cout << media << endl;
		totalBaixo = 0;
		totalAlto = 0;

		for(i=0;i!=n;i++) {
			if(valores[i]>media+0.01) {
				totalAlto += valores[i] - media;
				//cout << "a:\t" <<totalAlto << endl;
			} else if(valores[i]<media-0.01) {
				totalBaixo += media - valores[i];
				//cout << "b:\t" <<totalBaixo << endl;
			}
		}
		
		//cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2);

		printf("$%.2Lf\n",totalAlto>totalBaixo?totalBaixo:totalAlto);
	
	}

	return 0;

}
