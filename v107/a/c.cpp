#include <iostream>
#include <assert.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS (1e-10)
#define IGUAIS(a,b) ((a-b)*(a-b)<EPS)
#define DIF(d,e) !IGUAIS(d,e)

using namespace std;

double r, xs, ys, xe, ye;

bool start2() {

	double dify = ys - ye;
	double difx = xs - xe;
	
	//double mdify = (dify>0) ? dify : -dify;
//	double mdifx = (difx>0) ? difx : -difx;
	double mdify = 0;
	double mdifx = 0;
	
	mdify = mdifx = 0;
	if(DIF(dify,0))mdify=(dify>0) ? dify : -dify;
	if(DIF(difx,0))mdifx=(difx>0) ? difx : -difx;
	
	if(DIF(mdify,mdifx)) {
		if(mdify>mdifx) {
			double dif = mdify - mdifx;
			cout << ((dify<0)?"north":"south");
			printf(" %.10lf\n",dif);
			if(mdifx==0) return true;
			if(dify>0) ys = ye + mdifx;
			else ys = ye - mdifx;
			goto n;
		} else {
			double dif = mdifx - mdify;
			cout << ((difx<0)?"east":"west");
			printf(" %.10lf\n",dif);
			if(mdify==0) return true;
			if(difx>0) xs = xe + mdify;
			else xs = xe - mdify;
			goto n;
		}
	}
	n:
	
	dify = ys - ye;
	difx = xs - xe;
	
	mdify = mdifx = 0;
	if(DIF(dify,0)) mdify= (dify>0) ? dify : -dify;
	if(DIF(difx,0)) mdifx = (difx>0) ? difx : -difx;
//	mdify = (dify>0) ? dify : -dify;
	//mdifx = (difx>0) ? difx : -difx;
	
	// diagonal
	if(DIF(dify,0)) cout << ((dify<0)?"north":"south");
	if(DIF(difx,0)) cout << ((difx<0)?"east":"west");
//	if(dify!=0) cout << ((dify<0)?"north":"south");
	//if(difx!=0) cout << ((difx<0)?"east":"west");
	
	double mal = mdify;
	ys = ye; xs = xe;
	
	if(dify!=0 && difx!=0) mal = sqrt(2 * (mal*mal));
	
	printf(" %.10lf\n",mal);
	
	//assert(xe*xe + ye*ye <= r * r);
	
	return true;
	
}

int main () {
	
	//int t;
	int inst = 0;

	while(true) {
		if(!(cin >> r)) return 0;
		if(r==-1) return 0;
		cin >> xs >> ys >> xe >> ye;
		if(inst++!=0) cout << endl;
		while(!start2());
	}
	
	return 0;
	
}
