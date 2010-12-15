#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long roundz(double d) {
	d += 0.5;
	return (long) d;
}

double fat(int j) {
	if(j<3) return log(j+0.0);
	double v = 0;
	int i = j;
	while(i) {
		v += log(i+0.0);
		i--;
	}
	//cout << j << " " << exp(v) << " " << v << endl;
	return v;
}

int main() {

	long a,b,c;
	double v[5];
	long MV = 2; MV = 2 << 20;
	/*double *fat = new double[(MV)];
	fat[0] = log(1.0);*/
	int i,j,k;
	//for(i=1;i<MV;i++) {
	//	fat[i] = fat[i-1] + log(i+0.0);
/*		if(i<5) {
			cout << "III: " << i << ": " << fat[i] <<  " " << exp(fat[i]) << endl;
		}*/
	//}
	while((cin >> a >> b)) {
		if(a==0 && b==0) break;
		//if(a>=MV || b>=MV) while(true);
		//cout << a << " " << b << " " << fat[a] << " " << fat[b] << endl;
		double val = fat(a) - fat(b) - fat(a-b);
//		a!
//		(a-b)!*b!
		v[0]=exp(val);
		//cout << val<< " " <<v[0] << endl;
		printf("%ld\n",roundz(v[0]));
	}
	return 0;


}
