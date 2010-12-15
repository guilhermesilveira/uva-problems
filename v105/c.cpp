#include <iostream>

using namespace std;

int mat[2][500];

void st() {

	int tam,n;
	cin >> tam;
	cin >> n;
	int i,j,k = 0,novo;
	int t = 0;

	for(i=0;i<=tam;i++) mat[0][i] = 1;

	int u;
	cout << "tam " << tam << endl;
	for(u=0;u!=n;u++) {

		novo = !k;

		cin >> j;
		cout << "lido: " << j << endl;
		for(i=0;i<=tam;i++) mat[novo][i] = 0;
		int p = 0;
		for(i=0;i<=tam;i++) {
			if(mat[k][i]!=0)
				mat[novo][i+j] = ++p;
		}
		cout << ++t << ": " << endl;
		for(i=0;i<=tam;i++) {
			cout << mat[novo][i] << " ";
		}
	cout << endl;

		k = novo;

	}

	cout << mat[k][tam] << endl;

}

int main() {

	int t;
	cin >> t;
	while(t--) {
		st();
	}

	return 0;

}
