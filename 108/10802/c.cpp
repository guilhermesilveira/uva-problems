#include <iostream>

using namespace std;

#define FOR(a,b,c) for(a=b;a<c;a++)

bool con[110][110];

int st,en;
int cam[110],n;
bool v[110];

bool dfs(int at,int lev) {

	if(at==en) {
		int i;
		FOR(i,0,lev) cout << cam[i] << " ";
		cout << at << endl;
		return true;
	}

	int i;
	FOR(i,0,n) {
		if(!v[i] && con[at][i]) {
			// drive
			if(lev!=0 && cam[lev-1]==i) continue;
			// tenta
			v[i] = true;
			cam[lev+1] = i;
			if(dfs(i,lev+1)) return true;
			v[i] = false;
		}
	}

	return false;

}

void sat() {

	int i,j,k,m;
	cin >> n >> m >> st;
	FOR(i,0,n) FOR(j,0,n) con[i][j] = false;
	FOR(i,0,m) {
		cin >> j >> k;
		con[j][k]  = con[k][j] = true;
	}
	FOR(i,0,n) {
		// menor caminho de s ate i
		cam[0] = st;
		en = i;
		FOR(j,0,n) v[j] = false;
		v[st] = true;
		//cout << "de " << st << " para " << (i) << endl;
		if(dfs(st,0)) {
			
		} else {
			cout << "No drive." << endl;
		}
	}

}


int main() {
	int t;
	int j = 0;
	cin >> t;
	while(t--) 	{
		cout << "Case #" << ++j << ":" << endl;
		sat();
		cout << endl;
	}
	return 0;
}
