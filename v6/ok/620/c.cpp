#include <iostream>
#include <stdlib.h>

using namespace std;

char s[10000];

int tenta(int l,int r) {

	if(l==r) {
		if(s[l]=='A') return 0;
		return 3;
	}

	if(s[r]=='A') {
		// pode ser duas coisas
		int j = tenta(l,r-1);
		if(j!=3) return 0;
		j = tenta(l+1,r-1);
		if(j!=3) return 2;
		return 3;
	}

	// o da direita eh B
	if(s[r-1]=='A') {
		if(tenta(l,r-2)==3) return 3;
		return 1;
	}

	return 3;

}

int main() {

	int i,j,k;
	cin >> i;	
	while(i--) {
		cin >> s;
		j = strlen(s) - 1;
		k = tenta(0,j);
		if(k==0) cout << "SIMPLE" << endl;
		else if(k==1) cout << "FULLY-GROWN" << endl;
		else if(k==2) cout << "MUTAGENIC" << endl;
		else cout << "MUTANT" << endl;
	}


}
