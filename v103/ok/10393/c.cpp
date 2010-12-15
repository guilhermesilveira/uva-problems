#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n,f;
int nao[20];

bool canType[300];

vector<string> pal;
int mlen,len;

int main() {
	
	while((cin >> n >> f)) {
		for(int i=0;i!=20;i++) nao[i]=0;
		for(int i=0;i!=300;i++) canType[i] = 1;
		for(int i=0;i!=n;i++) {
			cin >> len;
			nao[len]=1;
			if(len==1) {
				canType['q']=canType['a']=canType['z']=0;
			} else if(len==2) {
				canType['x']=canType['s']=canType['w']=0;
			} else if(len==3) {
				canType['e']=canType['d']=canType['c']=0;
			} else if(len==4) {
				canType['r']=canType['f']=canType['v']=canType['t']=canType['g']=canType['b']=0;
			} else if(len==5 && nao[6]) {
				canType[' ']=0;
			} else if(len==6 && nao[5]) {
				canType[' ']=0;
			} else if(len==7) {
				canType['m']=canType['j']=canType['u']=canType['n']=canType['h']=canType['y']=0;
			} else if(len==8) {
				canType['i']=canType['k']=canType[',']=0;
			} else if(len==9) {
				canType['o']=canType['l']=canType['.']=0;
			} else if(len==10) {
				canType['p']=canType[';']=canType['/']=0;
			}
		}
		mlen = 0;
		pal.clear();
		scanf(" ");
		for(int i=0;i!=f;i++) {
			string s;
			getline(cin,s);
			len = s.size();
			if(len<mlen) continue;
			for(int j=0;j!=len;j++) {
				if(!canType[s[j]]) goto p;
			}
			if(len>mlen) {
				pal.clear();
				mlen = len;
			}
			pal.push_back(s);
			p:;
		}
		sort(pal.begin(),pal.end());
		len = pal.size();
		mlen = 0;
		for(int i=0;i!=len;i++) {
			if(i==0 || pal[i-1]!=pal[i]) mlen++;
		}
		cout << mlen << endl;
		for(int i=0;i!=len;i++) {
			if(i==0 || pal[i-1]!=pal[i]) cout << pal[i] << endl;
		}
	}
	
	return 0;
	
}
