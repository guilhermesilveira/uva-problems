#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int len,i,v[300];

vector<char> t;

bool cmp(const char &a,const char &b) {
	if(v[a]!=v[b]) return v[a]>v[b];
	return a<b;
}

#define pb push_back

int main() {

	char s[10000];
	t.pb('a');
	t.pb('e');
	t.pb('i');
	t.pb('o');
	t.pb('u');
	while(cin.getline(s,1000)) {
		for(i=0;i!=300;i++) v[i] = 0;
		if(s[0]=='#') break;
		len = strlen(s);
		for(i=0;i!=len;i++) {
			if(s[i]>='A' && s[i]<='Z') s[i] = s[i] - 'A' + 'a';
			v[s[i]]++;
		}
		sort(t.begin(),t.end(),cmp);
		for(i=0;i!=5;i++) {
			cout << t[i] << ":" << v[t[i]];
			if(i!=4) cout << " ";
		}
		cout << "." << endl;
	}
	return 0;

}
