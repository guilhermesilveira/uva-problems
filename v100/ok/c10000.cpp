#include <iostream>
#include <assert.h>
#include <map>
#include <string>

using namespace std;

int n,s;

char cam[110][110];

void start() {

	cin >> s;
	int i,j,k,l;
	for(i=0;i!=n;i++) 
		for(j=0;j!=n;j++) cam[i][j] = 0;
	while(true) {
		cin >> i >> j;
		if(!i&&!j) break;
		cam[i-1][j-1]=1;
	}
	s--;
	for(i=0;i!=n;i++) {
		for(j=0;j!=n;j++) {
			if(i==j || !cam[j][i]) continue;
			for(k=0;k!=n;k++) {
				if(k==i || k==j || !cam[i][k]) continue;
				l = cam[j][i] + cam[i][k];
				if(!cam[j][k] || cam[j][k]<l) {
					cam[j][k] = l;
				}
			}
		}
	}
	
	l = 0;
	for(i=0;i!=n;i++) {
		if(cam[s][i]>cam[s][l]) {
			l = i;
		}
	}
	cout << (s+1) << " has length " << (int)(cam[s][l]) << ", finishing at " << (l+1) << "." << endl << endl;

}


int main() {

	int inst = 0;
	while(true) {
		cin >> n;
		if(n==0) return 0;
		cout << "Case " << ++inst << ": The longest path from ";
		start();
	}

	return 0;

}
