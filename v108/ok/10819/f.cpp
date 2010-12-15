#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>

#define FOR(a,b) for(a=0;a<b;a++)
#define FOR3(a,b,c) for(a=b;a<c;a++)

using namespace std;

int main() {

	int m,n,i,j,k,a,b;
	int pos[16000];
	int maxv;
	while((cin >> m >> n)) {
		FOR(i,m+300) pos[i]=-1;
		pos[0] = 0;
		maxv=0;
		FOR(k,n) {
			scanf("%d %d",&a,&b);
			for(i=maxv;i>=0;i--) {
				if(pos[i]>=0) {
					if(pos[a+i]<0 || pos[a+i]<pos[i]+b) {
						pos[a+i]=pos[i]+b;
						if(a+i<11000) maxv = max(a + i,maxv);
					}
				}
			}
		}
		int val = 0;
		for(i=0;i<=m;i++) val=max(pos[i],val);
		if(m>1800) {
			int lim = m + 200;
			for(i=2001;i<=lim;i++) val=max(pos[i],val);
		}
		cout << val << endl;
	}

}
