#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int n,i,j,k=0;
	char lista[41][30];

	while((cin >> n) && n) {

		cout << "SET " << ++k << endl;
		for(i=0;i!=n;i++) {
			scanf("%s",&lista[i/2]);
			if(i%2==0) printf("%s\n",lista[i/2]);
		}

		n--;
		if(n%2==0) n--;

		for(i=n;i>0;i-=2) {
			printf("%s\n",lista[i/2]);
		}

	}

	return 0;

}
