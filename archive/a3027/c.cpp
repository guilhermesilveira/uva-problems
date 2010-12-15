#include <iostream>

using namespace std;

int v[20100];
int c[20100];
long long d[20100];

#define FOR(a,b) for(a=0;a<b;a++)

void st() {

	int n;
	char p[10];
	cin >> n;
	long long t;

	int i,j,k,l,m;
	FOR(i,n+10) {
		v[i] = c[i] = i;
		d[i] = 0;
	}
	m = 0;

	while(true) {

		scanf("%s",p);
		if(p[0]=='O') break;

		if(p[0]=='E') {

			scanf("%d",&j);
			cout << d[j] << endl;

		} else if(p[0]=='I') {

			scanf("%d %d",&j,&k);

			if(c[j]!=c[k]) {

				v[j] = k;

				t = j - v[j];
				if(t<0) t = - t;
				t %= 1000;

				j = c[j];
				k = c[k];

				for(i=0;i!=n;i++) if(c[i]==j) { c[i] = k; d[i] = (d[i] + t) % 1000; }

			}

		}

	}

}

int main() {

	int t;
	scanf("%d",&t);
	while(t--) st();
	return 0;

}
