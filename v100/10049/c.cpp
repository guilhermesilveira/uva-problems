#include <iostream>
#include <cstdio>


using namespace std;

#define MX (500001)

long val[MX];
long pesquisa(int v,int l,int tot) {
	int m = (l + tot) / 2;
	for(int i=1;i!=MX;i++) if(val[i]>=v) return i;
}

int main() {

	long v = 2000000000;
	long pos = 0;
	val[1] = 1;
	val[2] = 2;
	val[3] = 4;
	tot = 3;
	int i;
	for(i=1;i!=MX;i++) {
		pos += pesquisa(1,i);
		val[i-1] = pos;
		if(pos>v) break;
	}
	while((cin >> v) && v) cout << pesquisa(v,1,i) << endl;
	return 0;

}
