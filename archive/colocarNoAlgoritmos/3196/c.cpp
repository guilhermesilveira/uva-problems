#include <iostream>
#define FOR(a,b) for(int a=0;a<b;a++)
using namespace std;

int n,m;
bool mat[15][3000];

#define MAXI (2<<31)
long long val[15][3000];
bool vis[15][3000];


long long s(int lev,int ult) {

	if((2<<(n-lev-1))*ult>m) return 0;

	if(lev==n) return 1;

	if(vis[lev][ult]) return val[lev][ult];

	long long v = 0;
	for(int i=ult==0?1:ult*2;i<=m;i++) v += s(lev+1,i);
	vis[lev][ult] = 1;
	return val[lev][ult] = v;

}


int main() {
int jz = 0;

	int t;
	cin >> t;
while(t--) {
	cin >> n >> m;
	FOR(i,n+2) FOR(j,m+2) vis[i][j] = 0;
	jz++;
	cout << "Case "<<jz<<": n = " << n << ", m = " << m << ", # lists = " << s(0,0) << endl;
	}


}
