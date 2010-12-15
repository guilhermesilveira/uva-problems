#include <iostream>

using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)

int mat[20];

bool ok(int k,int m) {
	int i,j;
	int n = k * 2;
	int pos = -1;
//	cout << "m=" << m << endl;
	while(n!=k) {
		pos += m;
		pos %= n;
//		cout << pos << endl;
		if(pos<k) return 0;
		pos--;
		n--;
	}
	return 1;
}

void pre(int k) {

	int m = 1;
	while(true) {
		if(ok(k,m)) {
			mat[k]=m;
//			cout << m << endl;
			return;
		}
		m++;
	}

}

int main() {

	int i;

	FOR(i,15) if(i) pre(i);
/*	mat[1] = 2;
	mat[2] = 7;
	mat[3] = 5;
	mat[4] = 30;
	mat[5]=169;
	mat[6]=441;
	mat[7]=1872;
	mat[8] = 7632;
	mat[9] = 1740;
	mat[10] = 93313;*/
	
	while((cin >> i) && i) cout << mat[i] << endl;
	return 0;
}

