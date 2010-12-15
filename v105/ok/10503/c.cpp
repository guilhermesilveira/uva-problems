#include <iostream>
#define FOR(a,b) for(a=0;a<b;a++)
#define WHILES while(true)

using namespace std;

int i,j,k,l,m,n;
int peca[20][2];
bool con[20][20];
bool usado[20];

bool st(int last,int level) {

//	cout << "level: " << level << ": " << last << endl;

	if(level==n) {
		if(last==peca[1][0]) { //|| last==peca[1][1]) {
			return true;
		}
		return false;
	}
	
	for(int i=2;i<m;i++){
		if(usado[i]) continue;
		usado[i] = true;
		if(peca[i][0]==last) if(st(peca[i][1],level+1)) return true;
		if(peca[i][1]==last) if(st(peca[i][0],level+1)) return true;
		usado[i] = false;
	}

	return false;

}

int main() {

	
	WHILES {
		cin >> n;
		if(!n) return 0;
		cin >> m;
		m+=2;
		FOR(i,m) cin >> peca[i][0] >> peca[i][1];
		FOR(i,m) FOR(j,m) con[i][j] = false;
		FOR(i,m) FOR(j,m) if(peca[i][1]==peca[j][0]) con[i][j] = true;
		FOR(i,m) usado[i] = false;
		usado[0] = usado[1] = true;
		//if(st(peca[0][0],0) || 
		if(st(peca[0][1],0)) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}
	return 0;

}
