#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100000

long ci[30];

int compare(const void *a, const void *b) {
	
	int c1 = * ((int *)a);
	int c2 = * ((int *)b);
	if(ci[c2]==ci[c1]) {
		return c1 - c2;
	}
	return ci[c2] - ci[c1];
	
}

int main() {
	
	register int l,len,i;
	char *s = new char[MAX];
	
	int cc[26];
	for(i=0;i!=26;i++) {
		ci[i] = 0;
		cc[i] = i;
	}
	
	scanf(" %d ",&l);
	while(l--) {
		fgets(s,MAX,stdin);
		len = strlen(s);
	//	cout << s << endl;
		for(i=0;i!=len;i++) {
			if(s[i]>='a'  && s[i]<='z') {
				ci[s[i]-'a']++;
			} else if(s[i]>='A'  && s[i]<='Z') {
				ci[s[i]-'A']++;
			}
		}
	}
	
	qsort(cc, 26, sizeof(int), compare);
	
	for(i=0;i!=26;i++) {
		if(ci[cc[i]]==0) break;
		cout << (char) (cc[i]+'A')<< " " << ci[cc[i]] << endl;
	}
	
}
