#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	
	int n,i;
	char s1[100],s2[100];
	int oc[300],p[300];
	while((cin >> n) && n!=-1) {
		cout << "Round " << n << endl;
		cin >> s1 >> s2;
		int len1 = strlen(s1);
		for(i='a';i<='z';i++) oc[i]=p[i]=0;
		for(i=0;i!=len1;i++) { oc[s1[i]]=p[s1[i]]=1; }
		len1 = strlen(s2);
		int er = 0;
		for(i=0;i!=len1;i++) {
			if(p[s2[i]]==0) {
				if(++er==7) break;
			} else {
				oc[s2[i]]=0;
			}
		}
		if(er==7) {
			cout << "You lose." << endl;
		} else {
			for(i='a';i<='z';i++) if(oc[i]!=0) break;
			if(i=='z'+1) {
				cout << "You win." << endl;
			} else cout << "You chickened out." << endl;
		}
		
	}
	return 0;
	
}
