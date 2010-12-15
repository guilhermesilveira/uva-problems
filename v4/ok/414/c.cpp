#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int main() {

	int val[20];
	char lin[300];
	int n,i,j,k;
	while(true) {
		gets(lin);
		sscanf(lin,"%d",&n);
		if(!n) break;
		FOR(i,n) {
			val[i]=0;
			gets(lin);
			FOR(j,25) if(lin[j]==' ') val[i]++;
//			cout << i << " " << val[i] << endl;
		}
		int d = *min_element(val,&val[n]);
		j = 0;
		FOR(i,n) j += (val[i]-d);
		cout << j << endl;
	}
	return 0;

}
