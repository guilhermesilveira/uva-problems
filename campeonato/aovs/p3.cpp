#include <iostream>

using namespace std;

int n;

bool b[2][1000][1000];
bool ja[1000];
long long tot = 0;
#define FOR(a,b) for(a=0;a<b;a++)

void tenta(int u) {
	int i,j,k,l;
	if(u==n) {
		tot++;
		return;
	}
	FOR(i,n) {
		if(!ja[i] && b[0][u][i] && b[1][i][u]) {
			ja[i]=1;
			tenta(u+1);
			ja[i]=0;
		}
	}
}

int main() {
	int i,j,k,l;
	while((cin >> n) && n) {
		FOR(i,2) {
			FOR(j,n) {
				FOR(k,n) cin >> b[i][j][k];
			}
		}
		FOR(i,n) ja[j]=0;
		tot=0;
		tenta(0);
		cout << tot << endl;
	}
	return 0;


}
