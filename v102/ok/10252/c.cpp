#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main() {
	
	int apareceu1[300],apareceu2[300];
	string s1,s2;
	while(true) {
		if(!getline(cin,s1)) break;
		getline(cin,s2);
		int len = s1.size();
		for(char i='a';i!='z'+1;i++) apareceu1[i] = apareceu2[i] = 0;
		for(int i=0;i!=len;i++) if(islower(s1[i])) apareceu1[s1[i]]++;
		len = s2.size();
		for(int i=0;i!=len;i++) if(islower(s2[i])) apareceu2[s2[i]]++;
		for(char i='a';i<='z';i++) {
			if(apareceu1[i] && apareceu2[i]) {
				#define menor(a,b) (a<b?a:b)
				int men = menor(apareceu1[i],apareceu2[i]);
				while(men--) cout << i;
			}
		}
		cout << endl;

	}
	
}
