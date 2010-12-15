#include <iostream>

using namespace std;

int n,m,s,t;
bool con[110][110];
int exp[110];

bool vis[110];

int bfs() {

	int atual,i,j,k,l;

	for(i=0;i!=n;i++) vis[i] = false;

	limpa();
	adiciona(s);
	vis[s] = true;

	while(!empty()) {

		atual = front();

		for(i=0;i!=n;i++) {
			if(!vis[i] && con[atual][i]) {
				vis[i] = true;
				
			}
		}

	}

	return 0;

}

int main() {

	int j,k,l;
	while(true) {
		cin >> n >> m >> s >> t;
		if(n==m && s==t && !n && !s) break;
		for(int i=0;i!=n;i++) cin >> exp[i];
		if(s==t || exp[s]==0) {
			cout << 0 << endl;
			continue;
		}
		for(int i=0;i!=m;i++) {
			cin >> j >> k >> l;
			j--; k--;
			con[j][k] = con[k][j] = l;
		}
		j = bfs();
		cout << j << endl;
	}

	return 0;

}
