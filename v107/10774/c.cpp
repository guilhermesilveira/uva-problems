#include <iostream>

using namespace std;

int val[30001];
bool b[30001];

int calc(int p) {

	if(val[p]!=-1) return val[p];

	int i;
	for(i=1;i!=p+1;i++) b[i] = true;

	int n = p;
	int m = 0, k = 0;

	int t = 0;

	while(t!=p-1) {
		m++;
		if(m==p+1) m = 1;
		if(b[m]) k++;
		if(k==2) {
			k = 0;
			b[m] = false;
			t++;
		}
	}

	for(i=1;i!=p+1;i++) if(b[i]) break;
	int s = i;

	if(s==p) return 1;

	return calc(s) + 1;

}

int main() {

	val[1] = 1;
	val[2] = 2;
	val[3] = 1;

	for(int o=4;o!=30001;o++) {
		val[o]=-1;
	}

	for(int o=4;o!=30001;o++) {
		val[o] = calc(o);
	}

	int t,v;
	cin >> t;
	int i = 0;
	while(t--) {
		cin >> v;
		cout << "Case " << ++i << ": " << v << " " << val[v] << endl;
	}
	return 0;

}
