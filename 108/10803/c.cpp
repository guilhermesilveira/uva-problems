#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MAXVAL (2 << 10)

long p[200][2];
double d[200][200];

long zk(int a,int b) {
	return
		(p[a][0]-p[b][0])*(p[a][0]-p[b][0])
			+
		(p[a][1]-p[b][1])*(p[a][1]-p[b][1]);
}

double dist(int a,int b) {
	return
		(p[a][0]-p[b][0])*(p[a][0]-p[b][0])
			+
		(p[a][1]-p[b][1])*(p[a][1]-p[b][1]);
}

void st() {

	int i,j,k,l,m,n;

	cin >> n;

	FOR(i,n) FOR(j,n) d[i][j] = MAXVAL;

	// reads the data
	FOR(i,n) {
		d[i][i] = 0;
		cin >> p[i][0] >> p[i][1];
	}

	FOR(i,n) FOR(j,n) if(zk(i,j)<=100) d[i][j] = sqrt(dist(i,j));

	// floyd
	FOR(i,n) FOR(j,n) FOR(k,n) d[j][k] = MIN(d[j][i] + d[i][k],d[j][k]);

	// connected?
	FOR(i,n) FOR(j,n) if(d[i][j]==MAXVAL) {
		cout << "Send Kurdy" << endl << endl;
		return;
	}

	// max value found
	double mm = 0;
	FOR(i,n) FOR(j,n) mm = MAX(mm,d[i][j]);

	// round it
	mm *= 10000;
	mm += 0.5;
	long zz = (long) mm;
	mm = zz / 10000.0;

	printf("%.4lf\n\n",mm);

}

int main() {

	int t;
	cin >> t;
	int jz = 0;
	while(t--) {
		cout << "Case #" << ++jz << ":" << endl;
		st();
	}
	return 0;

}
