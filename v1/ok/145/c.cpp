#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	char tel[100];
	char z;
	int a,b,c,d,v[3],tz;
	double cs[5][3];
	cs[0][0] = 0.1; cs[0][1]=0.06; cs[0][2]=0.02;
	cs[1][0] = 0.25; cs[1][1]=0.15; cs[1][2]=0.05;
	cs[2][0] = 0.53; cs[2][1]=0.33; cs[2][2]=0.13;
	cs[3][0] = 0.87; cs[3][1]=0.47; cs[3][2]=0.17;
	cs[4][0] = 1.44; cs[4][1]=0.8; cs[4][2]=0.3;

	double cost;
	while(true) {
		scanf(" %c",&z);
		if(z=='#') break;
		scanf("%s %d %d %d %d",&tel,&a,&b,&c,&d);
		v[0]=v[1]=v[2]=0;
		while(true) {
			//cout << a << ":" << b << endl;
			if(a>=8 && a<18) tz = 0;
			else if(a>=18 && a<22) tz = 1;
			else tz = 2;
			b++;
			if(b==60) { a++; b = 0; }
			if(a==24) a = 0;
			v[tz]++;
			if(a==c && b==d) break;
		}
		//if(v[0]+v[1]+v[2]==1) v[0]=v[1]=v[2]=0;
		tz = z - 'A';
		cost = cs[tz][0]*v[0] + cs[tz][1]*v[1] + cs[tz][2]*v[2];
		printf("  %s%6d%6d%6d  %c%5.2lf\n",tel,v[0],v[1],v[2],z,cost);
	}
	return 0;

}
