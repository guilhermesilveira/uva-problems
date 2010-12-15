#include <iostream>

using namespace std;

#define MM (501)
int v[MM][MM][MM];
#define FOR(z,q) for(z=0;z!=q;z++)

int main() {

	int a,b,c,d,e,f;

	FOR(a,MM) FOR(b,MM) FOR(c,MM) v[a][b][c]=-1;


	while((cin >> a >> b >> c)) {
		if(!a && !b && !c) break;
		cout << a << " " << b << " " << c << " " <<v[a][b][c] << endl;
	}
	return 0;
}
