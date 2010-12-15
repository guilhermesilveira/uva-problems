#include <iostream>

#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int st[2000][2];
bool v[2000];
int cam[2000];

int start;
int n;

bool tenta(int d,int atual) {

	if(d==n) {
		return true;
	}

	int i;
	FOR(i,n) {
		if(!v[i]) {
			v[i] = true;
			cam[d] = i;
			if(st[i][0]==atual) {
				if(tenta(d+1,st[i][1])) return true;
			} else if(st[i][1]==atual) {
				if(tenta(d+1,st[i][0])) return true;
			}
			v[i] = false;
		}
	}

	return false;

}

int main() {

	int x,y,z;

	while(true) {

		n=0;
		int k;
		while(true) {
			cin >> x >> y;
			if(!x && !y) break;
			x--; y--;
			cin >> z;
			st[z-1][0] = x;
			st[z-1][1] = y;
			if(n==0) {
				k = x;
				if(x>y) k = y;
			}
			n++;
		}
		if(n==0) break;

		FOR(x,n) v[x] = false;

		start = st[0][0];
		start = k;
		//cout << start << endl;
		if(tenta(0,start)) {
			//cout << n << endl;
			FOR(x,n) cout << (cam[x]+1) << " ";
			cout << endl;
		} else {
			cout << "Round trip does not exist." << endl;
		}

		cout << endl;

	}

	return 0;

}
