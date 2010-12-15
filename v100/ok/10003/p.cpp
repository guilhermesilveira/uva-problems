#include <iostream>

using namespace std;

int p;
int ps[51];
int m[1001][1001];

int tenta(int l,int r) {

	if(m[l][r]!=-2) {
		return m[l][r];
	}

	int i,j,k = -1;
	for(i=0;i!=p;i++) {
		if(ps[i]>l && ps[i]<r) {
			j = tenta(l,ps[i]) + tenta(ps[i],r);
			if(k==-1 || j<k) k = j;
		}
	}
	
	if(k==-1) k = 0;
	else k = (r-l) + k;

	//cout << "de " << l <<" ate " << r << ":" << k<< endl;
	m[l][r] = k;

	return k;

}

int main() {

	int curS,i,j;
	while((cin >> curS)) {
		if(curS==0) return 0;
		cin >> p;
		for(i=0;i!=p;i++) {
			cin >> ps[i];
		}
		for(i=0;i<=curS;i++) for(j=0;j<=curS;j++) m[i][j] = -2;
		cout << "The minimum cutting is " << tenta(0,curS) << "." << endl;
	}
	return 0;

}
