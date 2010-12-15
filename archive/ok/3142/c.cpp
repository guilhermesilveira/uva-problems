#include <iostream>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

double EPS = 0.00000001;

double p(double a,double b) {

	double d = a * a + b * b;
	if(d-EPS<=9) return 100;
	if(d-EPS<=36) return 80;
	if(d-EPS<=81) return 60;
	if(d-EPS<=144) return 40;
	if(d-EPS<=225) return 20;
	return 0;	

}

int main() {

	int i,j,k;
	double v[4][4][4];
	double tot[2];

	while(true) {

		FOR(i,2) FOR(j,3) FOR(k,2) cin >> v[i][j][k];
		if(v[0][0][0]==-100) break;

		FOR(i,2) {
			tot[i] = 0;
			FOR(j,3) {
				tot[i] += p(v[i][j][0],v[i][j][1]);
			}
		}

		if(tot[0]==tot[1]) cout << "SCORE: " << tot[0] << " to " << tot[1] << ", TIE." << endl;
		else {
			cout << "SCORE: " << tot[0] << " to " << tot[1] << ", PLAYER ";
			if(tot[0]>tot[1]) cout << 1;
			else cout << 2;
			cout << " WINS." << endl;
		}

	}

	return 0;

}
