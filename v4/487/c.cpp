#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char linhas[21][25];

char posi[21];

vector<string> val;

int cmpa(string &s1, string &s2) {
	int len = s1.length();
	int len2 = s2.length();
	int min = len<len2?len:len2;
	for(int i=0;i!=min;i++) {
		if(s1[i]!=s2[i]) {
			return s1[i] - s2[i];
		}
	}
	return len - len2;
}

void ten(int y,int x,int l,char atual) {
	posi[l] = atual;
	if(l>=2) {
		posi[l+1] = '\0';
		string s = string(posi);
		val.push_back(s);
	} else if(l>n*n) {
		return;
	}
	// procuro um vizinho
	for(int dy=-1;dy<=1;dy++) {
		for(int dx=-1;dx<=1;dx++) {
			if(!dy && !dx) continue;
//			cout << "humm " << x << "," << y << ", " << dx << "," << dy << ":" << n << endl;
			if(y+dy<0 || x+dx<0 || y+dy>=n || x+dx>=n) continue;
//			cout << y+dy << x+dx << endl;
			if(linhas[y+dy][x+dx]>atual) {
				ten(y+dy,x+dx,l+1,linhas[y+dy][x+dx]);
			}
		}
	}
}

void tenta() {
	
	int i,j,k;
	for(i=0;i!=n;i++) {
		for(j=0;j!=n;j++) {
			ten(i,j,0,linhas[i][j]);
		}
	}
	
}

void start() {
	int i,j,k;
	for(i=0;i!=n;i++) cin >> linhas[i];
	tenta();
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		val.clear();
		start();
		int len = val.size();
		sort(val.begin(),val.end());
		for(int j=3;j!=n*n;j++) {
			bool first= true;
			for(int i=0;i!=len;i++) {
				if(val[i].size()==j && (first || val[i-1]!=val[i])) {
					first= false;
					cout << val[i] << endl;
				}
			}
		}
		if(t!=0) cout << endl;
	}
	
}
