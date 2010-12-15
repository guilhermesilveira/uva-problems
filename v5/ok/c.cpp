#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int carta(char c) {
	if(c=='A' || c=='a') return 115;
	else if(c=='K' || c=='k') return 114;
	else if(c=='Q' || c=='q') return 113;
	else if(c=='J' || c=='j') return 112;
	return c-'0';
}

bool comp(const char *s1,const char *s2) {
	
	if(s1[0]!=s2[0]) {
		if(s1[0]=='H') return false;
		if(s2[0]=='H') return true;
		return (s1[0]<s2[0]);
	}
	
	// mesmo sign
	int v1 = carta(s1[1]);
	int v2 = carta(s2[1]);
	return v1 < v2;
	
	
}

string val(int i) {
	if(i==0) {
		return "S:";
	} else if(i==1) {
		return "W:";
	} else if(i==2) {
		return "N:";
	} else if(i==3) {
		return "E:";
	}
}

int main() {
	
	char st[10];
	int start;
	while(true) {
		cin >> st;
		if(st[0]=='#') return 0;
		if(st[0]=='S') start = 1;
		else if(st[0]=='W') start = 2;
		else if(st[0]=='N') start = 3;
		else if(st[0]=='E') start = 0;
		scanf(" ");
		string s1,s2;
		getline(cin,s1);
		scanf(" ");
		getline(cin,s2);
		vector<char *> c[4];
		for(int i=0;i!=26;i++) {
			char *s = new char[3]; s[0]=s1[i*2];s[1]=s1[i*2+1];s[2]='\0';
			c[start].push_back(s);
			start++;
			if(start==4) start=0;
		}
		for(int i=0;i!=26;i++) {
			char *s = new char[3]; s[0]=s2[i*2];s[1]=s2[i*2+1];s[2]='\0';
			c[start].push_back(s);
			start++;
			if(start==4) start=0;
		}
		for(int i=0;i!=4;i++) sort(c[i].begin(),c[i].end(),comp);
		for(int i=0;i!=4;i++) {
			cout << val(i);
			for(int j=0;j!=13;j++) cout << " " << c[i][j];
			cout << endl;
		}
	}
	
	return 0;
	
}
