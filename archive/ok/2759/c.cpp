#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAIOR(a,b) (a>b?a:b)
#define MAXI (1001)

int main() {

	char s1[MAXI],s2[MAXI];
	int val[MAXI][MAXI];
	int i,j,k,l1,l2;
	while((cin >> s1 >> s2)) {
		l1 = strlen(s1); l2 = strlen(s2);
		for(i=0;i<=l1;i++) val[i][0] = 0;
		for(i=0;i<=l2;i++) val[0][i] = 0;
		for(i=1;i<=l1;i++) {
			for(j=1;j<=l2;j++) {
				if(s1[i-1]==s2[j-1]) {
					val[i][j] = val[i-1][j-1] + 1;
				} else {
					val[i][j] = MAIOR(val[i][j-1],val[i-1][j]);
				}
			}
		}
		cout << val[l1][l2] << endl;
	}
	return 0;

}
