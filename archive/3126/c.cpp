#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

struct {
	int h;
	int m;
	int a,b,c,d;
	int pre;
	int tot;
	int hf,mf;
	bool ok;
} rua[510];

bool antes[510][510];

bool ant(int i,int j) {
	if(rua[i].hf<rua[j].h) return true;
	if(rua[i].hf>rua[j].h) return false;
	return rua[i].mf<rua[j].m;
}

int ABS(int v) {
	if(v<0) return -v;
	return v;
}

void st() {

	int n;
	cin >> n;
	int tot = n;
	

	int i,j,k,l;

	FOR(i,n) {
		scanf("%d:%d %d %d %d %d",&rua[i].h,&rua[i].m,&rua[i].a,&rua[i].b,&rua[i].c,&rua[i].d);
		rua[i].hf = rua[i].h;
		rua[i].mf = rua[i].m + ABS(rua[i].a-rua[i].c) + ABS(rua[i].b-rua[i].d);
		while(rua[i].mf>=60) {
			rua[i].hf++;
			rua[i].mf--;
		}
		rua[i].ok = 1;
	}
	FOR(i,n) FOR(j,n) antes[i][j]=ant(i,j);

	int necessario = 0;
	int val[510];
	int lef = 0;
	FOR(i,n) if(rua[i].ok) val[lef++]=i;
	while(tot) {
		necessario++;
	FOR(i,lef) { rua[val[i]].pre=i; rua[val[i]].tot=1; }
int a,b;
FOR(a,lef) {
	for(b=a+1;b<lef;b++) {
		i=val[a];j=val[b];
		if(antes[i][j] && rua[j].tot<rua[i].tot+1) {
			rua[j].pre=i;
			rua[j].tot=rua[i].tot+1;
		}
	}
}
		int maxi = 0;
		FOR(i,lef) if(rua[val[i]].tot>maxi) {maxi = rua[val[i]].tot;j=val[i];}
		while(rua[j].pre!=j) {
			rua[j].ok=0;
			j = rua[j].pre;
		}
		tot-=maxi;

	}
	cout << necessario<<endl;

}


int main() {

	int t; cin >> t; while(t--)st(); return 0;

}
