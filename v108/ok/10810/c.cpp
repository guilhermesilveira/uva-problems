#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int main() {

	int n = 0;
	int i,j,w,k=999999999;
	int v[500001];

	while((scanf("%d",&n)) && n) {
		k = 0;
		FOR(w,n) {
			scanf("%d",&v[w]);
			//FOR(i,w) if(v[i]>v[w]) k++;
		}
		FOR(w,n) {
		//	for(i=w+1;i<n;i++) if(v[i]<v[w]) k++;
		}
		cout << k << endl;
	}
	return 0;

}
