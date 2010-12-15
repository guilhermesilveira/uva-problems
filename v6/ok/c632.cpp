#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

char lin[3000];

void st() {
	int i,j,k;
	gets(lin);
	gets(lin);
	sscanf(lin,"%d",&j);
	k=j;
	// vai ler de 50 em 50
	int pos = 0;
	while(j>0) {
		gets(&lin[pos]);
		j -= 50;
		pos+=50;
	}
	string p = string(lin);
	string s1;
	vector<string> v;
	FOR(i,k) {
		string s = p.substr(i,k) + p.substr(0,i);
		//cout << s << endl;
		v.push_back(s);
		if(i==1) s1 = s;
	}
	sort(v.begin(),v.end());
	FOR(i,k) {
	//	cout << v[i] << " e " << s1 << endl;
		if(v[i]==s1) break;
	}
	cout << i << endl;
	s1="";
	FOR(i,k) s1+= v[i][k-1];
	FOR(i,k) {
		if(i && i%50==0) cout << endl;
		cout << s1[i];
	}
	cout << endl;
}

int main() {
	int t;
	gets(lin);
	sscanf(lin,"%d",&t);
	while(t--) { st(); if(t) cout << endl; }
	return 0;
}

