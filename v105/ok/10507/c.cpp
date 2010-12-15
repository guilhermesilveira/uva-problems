#include <iostream>
#include <stdlib.h>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

bool con[30][30];
bool existe[30];
bool acordado[30];
int temp[30];

int main() {

	char ac[100];
	char a,b;
	int total;
	int i,j,k,l,n,m;
	while((cin >> n >> m)) {
		cin >> ac;
		FOR(i,30) existe[i] = acordado[i] = false;
		l = strlen(ac);
		FOR(i,l) if(ac[i]>='A' && ac[i]<='Z') acordado[ac[i]-'A'] = existe[ac[i]-'A'] = true;
		FOR(i,30) FOR(j,30) con[i][j] = false;
		while(m--) {
			cin >> a >> b;
			a -= 'A'; b -= 'A';
			existe[a] = existe[b] = true;
			con[a][b] = con[b][a] = true;
		}
		int maximo = 26 * 4;
		int tempo = 0, tl = 0;
		total = 0;
		FOR(i,30) if(acordado[i]) total++;
		while(true) {
			if(total==n) {
				cout << "WAKE UP IN, " << tl << ", YEARS" << endl;
				goto f;
			}
			tl++;
			if(tempo==10) break;
			FOR(i,30) temp[i] = 0;
			FOR(i,30) {
				if(!existe[i] || !acordado[i]) continue;
				FOR(j,30) if(con[i][j]) temp[j]++;
			}
			FOR(i,30) {
				if(!existe[i] || acordado[i]) continue;
				if(temp[i]>=3) {
					acordado[i] = true;
					total++;
					tempo = 0;
					FOR(j,30) if(existe[j] && !acordado[j]) break;
				}
			}
			tempo++;
		}
		cout << "THIS BRAIN NEVER WAKES UP" << endl;
f:;
	}
	return 0;

}
