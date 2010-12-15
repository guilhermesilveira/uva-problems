#include <iostream>
#include <stdio.h>

using namespace std;

int p[10001][2];

#define DIST(a,b) ((p[a][0]-p[b][0])*(p[a][0]-p[b][0])+(p[a][1]-p[b][1])*(p[a][1]-p[b][1]))

void st() {

	int n;
	cin >> n;
	int i,j;
	double k,l,d,mk,ml,md;
	bool b = false;
	
	for(i=0;i!=n;i++) cin >> p[i][0] >> p[i][1];
	md = 20000*20000*2;

	//cout << md << endl;

	for(i=0;i!=n;i++) {

		for(j=i+1;j<n;j++) {

			d = DIST(i,j);
			if(d>=md) continue;

			k = p[i][0] - p[j][0];
			if(k<0) k = -k; k /= 2.0;

			l = p[i][1] - p[j][1];
			if(l<0) l = -l; l /= 2.0;

			if(!b || d<md) {
				b = true;
				mk = k; ml = l; md = d;
			}
		}
	}
	printf("%.3lf %.3lf\n",mk,ml);
//	cout << md << endl;

}

int main() {

	int t; cin >> t; while(t--) st(); return 0;

}
