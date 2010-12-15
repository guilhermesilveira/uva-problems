#include <iostream>
#include <assert.h>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int n,k;
int val[11110];
char pos[2][1010];

void start() {
	scanf("%d %d",&n,&k);
	int i,j;
	for(i=0;i!=n;i++) {
		scanf("%d",&val[i]);
		val[i] = val[i] % k;
	}
	for(i=0;i<=k;i++) {
		pos[0][i] = 0;
	}
	int t = val[0] % k;
	if(t<0) t = -t;
	pos[0][t] = 1;
	int b,b2;
	for(i=1;i<n;i++) {
		b = i % 2; b2 = (i-1) % 2;
		for(j=0;j<k;j++) pos[b][j] = 0;
		for(j=0;j<k;j++) {
			if(pos[b2][j]) {
				t = (j+val[i])%k;
				if(t<0) t = -t;
				pos[b][t] = 1;
				t = (j-val[i])%k;
				if(t<0) t = -t;
				pos[b][t] = 1;
			}
		}
	}
	if(pos[(n-1)%2][0]==1) printf("Divisible\n");
	else printf("Not divisible\n");
}

int main() {
	int t;
	cin >> t;
	while(t--) {start();}
	return 0;
	
}
