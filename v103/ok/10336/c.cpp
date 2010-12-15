#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

char linha[2][10000];
int pos[2][10000],tot[300];

bool srt(char a,char b) {
	if(tot[a]==tot[b]) return a<b;
	return tot[a]>=tot[b];
}

void start() {
	
	int l,c;
	cin >> l >> c;
	// parseia a primeira linha
	cin >> linha[0];
	int j;
	for(j='a';j<='z';j++) tot[j] = 0;
	tot[linha[0][0]] = 1;
	pos[0][0] = 1;
	for(j=1;j<c;j++) {
		if(linha[0][j]!=linha[0][j-1]) {
			tot[linha[0][j]]++;
		}
		pos[0][j] = tot[linha[0][j]];
	}
	int k;
	for(int i=1;i<l;i++) {
		int atu = (i % 2);
		int ant = (i-1)%2;
		cin >> linha[atu];
		for(j=0;j<c;j++) {
			if(j==0) {
				if(linha[ant][j]!=linha[atu][j]) {
					// novo
					tot[linha[atu][j]]++;
					pos[atu][j] = tot[linha[atu][j]];
				} else { 
					pos[atu][j] = pos[ant][j];
				}
			} else {
				if(linha[ant][j]!=linha[atu][j] && linha[atu][j-1]!=linha[atu][j]) {
					tot[linha[atu][j]]++;
					pos[atu][j] = tot[linha[atu][j]];
				} else if(linha[ant][j]==linha[atu][j] && linha[atu][j-1]==linha[atu][j]) {
					if(pos[ant][j]!=pos[atu][j-1]) {
						for(k=j+1;k<c;k++) {
							if(linha[ant][k]!=linha[atu][j]) break;
							if(pos[ant][k]==pos[ant][j]) pos[ant][k] = pos[atu][j-1];
						}
						for(k=j-1;k>=0;k--) {
							if(linha[ant][k]!=linha[atu][j]) break;
							if(pos[ant][k]==pos[ant][j]) pos[ant][k] = pos[atu][j-1];
						}
						pos[atu][j] = pos[ant][j] = pos[atu][j-1];
						tot[linha[atu][j]]--;
					} else {
						pos[atu][j] = pos[ant][j];
					}
				} else if(linha[ant][j]==linha[atu][j]) {
					pos[atu][j] = pos[ant][j];
				} else {
					pos[atu][j] = pos[atu][j-1];
				}
			}
		}
	}
	vector<char> v;
	for(j='a';j<='z';j++) {
		if(tot[j]!=0) {
			v.push_back(j);
		}
	}
	sort(v.begin(),v.end(),srt);
	int len = v.size();
	for(int i=0;i!=len;i++) {
		cout << v[i] << ": " << tot[v[i]] << endl;
	}

}
int main() {
	int t,inst=0; cin >> t; while(t--) { cout << "World #" << ++inst << endl;start();}	return 0;
	
}
