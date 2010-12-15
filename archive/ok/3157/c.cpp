#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define FOR(a,b) for(a=0;a<b;a++) 

using namespace std;

int main() {

	int pl[12000];
	int poi[12000];
	int n,m,v,tot;
	register int i,j;
	while(true) {
		tot = 0;
		scanf("%d %d",&n,&m);
		if(!n && !m) break;
		fill(&poi[0],&poi[11000],0);
		FOR(j,n) {
			FOR(i,m) {
				scanf("%d",&v);
				if(find(&pl[0],&pl[tot],v)==&pl[tot]) pl[tot++] = v;
				poi[v]++;
			}
		}
		int maxi = 0;
		FOR(j,tot) {i=pl[j]; if(poi[i]>maxi) maxi = poi[i];}
		int seg = 0;
		sort(pl,&pl[tot]);
		FOR(j,tot) {i=pl[j]; if(poi[i]>seg && poi[i]!=maxi) seg = poi[i];}
		FOR(j,tot) {i=pl[j]; if(poi[i]==seg) printf("%d ",i);}
		printf("\n");
	}
	return 0;

}
