#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int main() {

	int v;
	int i,j,k;
	long a,b,n,val,t,c,del;
	while((cin >> v) && v) {

t=0;
//cout << v << endl;
for(a=1;a<v+1;a++) {
for(b=a;b<v+1;b++) {
	long v1 = (a*a+b*b);
	long v2 = ((a*b+1));
	if(v1 % v2 ==0) {
		cout << a << " " << b << " " << v1 << " " << v2 <<endl;
		t++;
	}
}
}
cout << t << endl;

	}
	return 0;

}
