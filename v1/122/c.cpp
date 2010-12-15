#include <stdio.h>

#include <iostream>

using namespace std;

int n;
char st[300][300];
int v[300];

int main() {

	int len,i=0,j;
	while((true)) {
		n = 0;
		while((true)) {
//			scanf(" ");
			j = scanf(" ( %d , %[^)] )",&v[n],st[n]);
			cout << "j: " << j << endl;
			if(j==0) break;
			cout << v[n] << " " << st[n] << endl;
			n++;
		}
		cout << endl;
//		scanf(")");
		if(n==0) break;
//		scanf("%s",&st[0]);
//		cout << st[0] << endl;
//		break;
		if(i++==1) break;
	}
	return 0;

}
