#include <iostream>

#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int main() {

	int k,i,j,m,n,z;
	bool val[100][60];
	bool con[60][60];
	while(true) {
		cin >> n >> m >> k;
		if(!n && !m && !k) break;

		FOR(i,n) {
			FOR(j,n) con[i][j] = false;
			val[0][i] = false;
		}
		val[1][0] = true;
		FOR(i,m) {
			cin >> j >> z;
			con[j][z] = true;
		}

		int atual = 1;

		bool possivel = false;

		while(true) {

			if(atual>=k && val[atual][n-1]) {
				possivel = true;
				break;
			}

			if(atual>80) break;

			/*cout << atual << ": "; 
			FOR(i,n) {
				cout << val[atual][i] << " ";
			}
			cout << endl;*/

			FOR(j,n) val[atual+1][j] = false;

			FOR(i,n) {
				if(!val[atual][i]) continue;
				// ignora o (n-1), nao pode passar por aqui antes da hora
				// if(i==n-1) continue;
				FOR(j,n) {
					if(i==j || !con[i][j]) continue;
					val[atual+1][j] = true;
				}
			}

			atual++;

		}
		
		if(possivel) {
			cout << (atual) << endl;
		} else {
			cout << "LOSER" << endl;
		}
	}
	return 0;

}
