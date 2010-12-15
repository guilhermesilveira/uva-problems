#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define pb push_back
#define REP(a,b) for(int a=0,_n=b;a<_n;a++)
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int n;
vector<int> viz[10001];
bool vz[10001];
stack<int> st;

bool val = 1;

int path(int v) {

	int w;
	for(;!viz[v].empty();v=w) {
		st.push(v);
		w = viz[v][viz[v].size()-1];
		viz[v].erase(viz[v].end()-1);
		// remove o v de w tambem
		for(vector<int>::iterator it = viz[w].begin(); it!=viz[w].end();
			it++) {
			if(*it==v) {
				viz[w].erase(it);
				break;
			}
		}
	}
	return v;

}

vector<int> cam;

void mostra(int v) {
	cout << v << endl;
	while(path(v)==v && !st.empty()) {
		v = st.top(); st.pop();
		cout << v << endl;
	}
}

void dfs(int d) {
	if(vz[d]) return;
	vz[d] = 1;
	REP(i,viz[d].size()) dfs(viz[d][i]);
}

void sta(){

	int i,m,a,b;

	cam.clear();

	// le
	n = 1995;
	FOR(i,n) viz[i].clear();
	while((cin >> a >> b)) {
		if(!a && !b) break;
		viz[a].pb(b);
		viz[b].pb(a);
	}

	FOR(i,n) sort(viz[i].begin(),viz[i].end());

	// verifica se eh possivel
	for(i=0;i<n;i++) vz[i]=0;
	
//	REP(j,viz[0].size()) cout << viz[0][j] << endl;

	// testa paridade
	for(i=0;i<n;i++) if(viz[i].size()%2) {
		cout << -1 << endl;
		return;
	}
	// testa conexo
	dfs(0);
	for(i=0;i<n;i++) if(!vz[i]) {
		cout << -1 << endl;
		return;
	}
	mostra(0);
//	reverse(cam.begin(),cam.end());
	int len = cam.size();
	REP(j,cam.size()) cout << cam[j] << " "; cout << endl;

}

int main() {

	while(val) {
		sta();
		if(val) cout << endl;
	}
	return 0;

}
