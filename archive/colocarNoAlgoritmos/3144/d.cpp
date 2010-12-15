#include <iostream>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

unsigned long long mat[11][3000];
bool bv[11][3000];

unsigned long long pr(int n, int m) {
	int i,j;
	if(bv[n][m]) return mat[n][m];
	bv[n][m] = true;
	if(n>m) {
		mat[n][m] = 0;
	} else {
//		cout << n << " " << m << endl;
		mat[n][m] = 0 + pr(n-1,m/2) + pr(n, m-1);
	}
	if(n<0 || m<0) exit(0);
	return mat[n][m];
}

void pre() {
	int i,j,k,l,v[20];
	FOR(i,11) FOR(j,2011) { mat[i][j] = 0; bv[i][j] = false; }
	FOR(j,2011) { bv[1][j] = true; mat[1][j] = j; }
	FOR(j,11) { bv[j][1] = true; }
	mat[1][1] = 1;
	for(i=1;i!=11;i++) for(j=1;j!=2011;j++) pr(i,j);
}

int main() {

	int ta;
	int j=0,k,l,i;

	pre();
	cin >> ta;
	while(true) {
		cin >> k >> l;
		cout << "Data set " << ++j << ": " << k << " " << l << " " << mat[k][l] << endl;
		ta--;
		if(ta==0) return 0;
	}
	return 0;
}
