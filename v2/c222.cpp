// 222
// DP de gas station com diversos detalhes

#include <iostream>
using namespace std;

double distf;
int n;
double cap,mpg,cost0,meio;
double p[51][2];

void st() {

	int i,j,k;

	double quanto[51];

	cin >> cap >> mpg >> cost0 >> n;
	for(i=0;i!=n;i++) {
		cin >> p[i+1][0] >> p[i+1][1];
		p[i+1][1]/=100;
	}
	p[0][0] = 0;
	p[0][1] = cost0;
	meio = cap/2;
	n++;
	p[n][0] = distf;
	p[n][1] = 0;

	for(i=0;i<=n;i++) quanto[i]=-1;
	quanto[0] = 0;
	double m = -1,temp;

	for(i=0;i<=n;i++) {
		// a partir do valor que eu tenho nesse cara e tanque cheio
		// tento ir para cada um dos outros
		for(j=i+1;j<n;j++) {
			if(p[j][0]-p[i][0]<cap*mpg) {
				// consigo chegar aqui... tenta encher
				temp = p[j][0]-p[i][0];
				temp /= mpg;
				temp *= p[j][1];
				if(quanto[j]<0 || quanto[j]>quanto[i]+temp+2) {
					quanto[j] = quanto[i]+temp+2;
				}
			}
		}
		if(p[n][0]-p[i][0]<cap*mpg) {
			// consigo chegar ao fim, nao precisa encher
			if(quanto[j]<0 || quanto[j]>quanto[i]) {
				quanto[j] = quanto[i];
			}
		}
	}

	/*for(i=0;i<=n;i++) cout << quanto[i] << " ";
	cout << "::" << cost0 << endl;*/


	cout << "minimum cost = $";
	printf("%.2lf",quanto[n]+cost0);
	cout << endl;

}


int main() {

	int i=0;
	while(true) {
		cin >> distf;
		if(distf<0) break;
		cout << "Data Set #" << ++i << endl;
		st();
	}
	return 0;

}
