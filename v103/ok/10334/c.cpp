#include <iostream>

using namespace std;

char val[2000][300];
int len[2000];

void calcula(int i) {
	len[i] = len[i-1];
	for(int j=0;j!=len[i];j++) {
		val[i][j] += val[i-1][j]+val[i-2][j];
		if(val[i][j]>=10) {
			if(j==len[i]-1) len[i]++;
			val[i][j]-=10;
			val[i][j+1]=1;
		}
	}
}

int main() {
	int j,n,i;
	for(j=0;j!=300;j++) val[0][j] = val[1][j] = 0;
	val[0][0]=len[0]=len[1]=1;
	val[1][0]=2;
	for(i=2;i!=1001;i++) {
		for(j=0;j!=300;j++) val[i][j] = 0;
		calcula(i);
	}
	while((cin>>n)) {
		for(i=len[n]-1;i>=0;i--) cout << (char) (val[n][i]+'0');
		cout << endl;
	}
	return 0;
}
