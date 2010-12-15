#include <iostream>
#include <stdio.h>
#include <algorithm>
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

int val[7000][3];
void st();

int cmp(const void *a, const void *b) {
	int *c = (int *) a;
	int *d = (int *) a;
	if(c[0]!=d[0]) return c[0]-d[0];
	if(c[1]!=d[1]) return c[1]-d[1];
	if(c[2]!=d[2]) return c[2]-d[2];
	return 0;
}

int n=0;

int main() {
	while((cin >> val[n][1] >> val[n][2])) n++;
	st();
	return 0;
}

void st() {

	int i,j,k,l;
	FOR(i,n) val[i][0]=val[i][2]-val[i][1];
	qsort(val,n,sizeof(int)*3,cmp);
//	FOR(i,n) cout << val[i][0] << endl;
	int left[7000];
	FOR(i,n) left[i]=0;
	l = 0;
	left[l] = (2 << 10);
	FOR(i,n) {
		for(j=l;j>=0;j--) {
			//cout << "j: " << j << " " << left[j] << endl;
			if(left[j] && left[j]>=val[i][1]) {
			//cout << "vale a pena em " << j << endl;
	left[j+1] = max(left[j+1], min(left[j]-val[i][1],val[i][0]) );
				l=max(l,j+1);
			}
		}
	}
	cout << l << endl;

}
