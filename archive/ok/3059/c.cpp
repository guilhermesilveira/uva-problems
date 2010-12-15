#include <iostream>

using namespace std;

int main() {

	int n,i,j;
	int lin[10][2];
	long long tot,a,b;
	while((cin >> n) && n!=-1) {
		tot = 0;
		for(i=0;i!=n;i++) {
			cin >> lin[i][0] >> lin[i][1];
			if(i==0) {
				tot += lin[i][0] * lin[i][1];
			} else {
				a = lin[i][1] - lin[i-1][1];
				tot += a * lin[i][0];
			}
		}
		cout << tot << " miles" << endl;
	}
	return 0;

}
