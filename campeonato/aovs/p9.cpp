#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

	long mini[10000];
	long val[10000];
	long maior[10000];
	bool enc[10000];
	
	int i,j,k;
	#define FOR(a,b) for(a=0;a<b;a++)
int n;
	while((cin >> n) && n) {

long v;
FOR(i,n) mini[i]=enc[i]=maior[i]=0;
FOR(i,n) {
	long men = 0;
	FOR(j,n) {
		scanf("%ld",&val[j]);
		if(!j || val[j]<men) men=val[j];
		maior[j]=max(maior[j],val[j]);
	}
	FOR(j,n) {
		if(val[j]==men) {
			enc[j]=1;
			if(val[j]>mini[j]) mini[j]=val[j];
		}
	}
}
long maiorv = 0;
FOR(i,n) {
	//cout << mini[i] << " ";
	if(mini[i]==maior[i]) maiorv = max(mini[i],maiorv);
}

cout << maiorv << endl;



	}

	return 0;

}
