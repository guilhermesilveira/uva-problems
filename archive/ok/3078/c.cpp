#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX (10000)

char v[MAX];
int tot;
long long dp[MAX];

long long calc(int n) {

	if(dp[n]!=-1) return dp[n];

	if(n>tot) return 1;

	if(v[n]=='1') {
		if(n==tot-1) dp[n] = 1;
		else {
			if(v[n+1]=='0') dp[n] = calc(n+2);
			else dp[n] = calc(n+1) + calc(n+2);
		}
	}

	else if(v[n]=='2') {
		if(n==tot-1) dp[n] = 1;
		else {
			if(v[n+1]=='0') dp[n] = calc(n+2);
			else if(v[n+1]>='7') dp[n] = calc(n+1);
			else dp[n] = calc(n+1) + calc(n+2);
		}
	} else dp[n] = calc(n+1);

	return dp[n];

}

int main() {

	int i;
	while((cin >> v)) {
		if(v[0]=='0' && (v[1]=='\n' || v[1]=='\r' || v[1]=='\0')) break;
		tot  =  strlen(v);
		for(i=0;i!=tot;i++) dp[i] = -1;
		dp[tot] = 1;
		cout << calc(0) << endl;
	}

	return 0;

}
