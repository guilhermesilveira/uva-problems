#include <iostream>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int n;
char m[20][20];
int p[20][20];

int tenta(int y,int x) {
	if(m[y][x]=='0' || !y || !x || x==n || y==n) {
		p[y][x] = 0;
		return 0;
	}
	
}

void st() {
	int i,j,k;
	cin >> n;
	FOR(i,n) cin >> m[i];
	FOR(i,n) FOR(j,n) p[i][j]=-1;
	FOR(i,n) FOR(j,n) tenta(i,j);
	cout << "finish test" << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) st();
	return 0;
}

// 82456811 ou 51828043
