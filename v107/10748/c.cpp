#include <iostream>

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define BUCK (1001)
#define BUCKMAX (101)
#define PRIME (37)

int buckt[BUCK];
int buck[BUCK][BUCKMAX];
long long cache[100001][2];

void hclear() {
	for(int i=0;i!=BUCK;i++) buckt[i] = 0;
}

int hashcode(long long v1,long long v2) {
	return ((v1*v2*PRIME) % BUCK);
}

bool contain(long long v1,long long v2) {
	int b = hashcode(v1,v2),i=buckt[b]-1;
	for(;i>=0;i--) if(v[hm[b][i]][0]==v1 && v[hm[b][i]][1]==v2) break;
	return i!=-1;
}

void add(long long v1,long long v2) {
	int b = hashcode(v1,v2), i = buckt[b];
	
	buckt[b]++;
}

void vai(long long a,long long b,int t) {

	if(contain(a,b)) return;

	add(a,b);

	if(t!=0) {
		t--;
	}

}

int main() {

	int i,l,m;
	long long j,k;

	while((cin >> n) && n) {

		hclear();
		for(i=0;i!=n;i++) {
			cin >> j >> k >> l;
			vai(j,k,l);
		}

	}
	return 0;

}
