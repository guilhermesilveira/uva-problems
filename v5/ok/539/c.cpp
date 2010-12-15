// 539
// MAIOR CAMINHO, UNDIRECTED, pode visitar quantas vezes quiser o mesmo no

#include <iostream>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int n,m;
int maior;
bool con[30][30];
bool vis[30][30];

void tenta(int atual,int lev) {
	//cout << atual << "," << lev << endl;
	if(lev>maior) maior = lev;
	int i;
	FOR(i,n) {
		if(!vis[atual][i] && con[atual][i]) {
			vis[atual][i]=vis[i][atual]=true;
			tenta(i,lev+1);
			vis[atual][i]=vis[i][atual]=false;
		}
	}
}

void maxi() {
	int i,j,k,l;
	FOR(i,n) FOR(j,n) vis[i][j] = con[i][j] = false;
	FOR(i,m) {
		cin >> j >> k;
		con[k][j] = con[j][k] = true;
	}
	FOR(i,n) {
		tenta(i,0);
	}
}

int main() {

	while((cin >> n >> m)) {
		if(!n && !m) break;
		maior = 0;
		maxi();
		cout << maior << endl;
	}
	return 0;

}
