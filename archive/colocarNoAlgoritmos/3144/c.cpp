#include <iostream>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int n,m;
long long tot;
int op[20];

bool tenta(int ult,long level) {
	if(level==n-1) {
		int v = ult * 2;
		if(v>m) return false;
		tot += m - v + 1;
		return true;
	}
	int i;
	i = ult * 2;
	if(ult==0) i = 1;
	bool b = false;
	for(;i<=m;i++) {
		if(i << (n - level) > m) return b;
		//op[level] = i;
		if(tenta(i,level+1)) b = true;
		else return b;
	}
	return b;
}

long long v(int a,int b) {
	tot = 0;
	n = a;
	m = b;
	tenta(0,0);
	return tot;
}

int main() {

	int ta;
	int j=0,k,l;
	cin >> ta;
	while(true) {
		cin >> k >> l;
		cout << "Data set " << ++j << ": " << k << " " << l << " " << v(k,l) << endl;
		ta--;
		if(ta==0) return 0;
	}
	return 0;
}
