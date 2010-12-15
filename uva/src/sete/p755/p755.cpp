/* @JUDGE_ID: 39315ZN 713 C++ "Invert" */

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<string,int> repetecos;
vector<string> valores;

bool ordenacao(const string &s1,const string &s2) {
	return s2>s1;
}

void trabalha(string &novo) {
	for(int i=0;i!=novo.length();i++) {
		//cout << novo[i] << endl;
		if(novo[i]=='A' || novo[i]=='B' || novo[i]=='C') {
			novo[i]='2';
		} else if(novo[i]=='D' || novo[i]=='E' || novo[i]=='F') {
			novo[i]='3';
		} else if(novo[i]=='G' || novo[i]=='H' || novo[i]=='I') {
			novo[i]='4';
		} else if(novo[i]=='J' || novo[i]=='K' || novo[i]=='L') {
			novo[i]='5';
		} else if(novo[i]=='M' || novo[i]=='N' || novo[i]=='O') {
			novo[i]='6';
		} else if(novo[i]=='P' || novo[i]=='R' || novo[i]=='S') {
			novo[i]='7';
		} else if(novo[i]=='T' || novo[i]=='U' || novo[i]=='V') {
			novo[i]='8';
		} else if(novo[i]=='W' || novo[i]=='X' || novo[i]=='Y') {
			novo[i]='9';
		} else if(!(novo[i]>='1' || novo[i]<='0') || novo[i]=='-') {
			novo.erase(i,1);
			i--;
		}
	}
}

int main(int argc, char **argv) {
	
	int ccc = 0;
	cin >> ccc;
	
	for(int zzz=0;zzz!=ccc;zzz++) {
   
	int inst = 0;
	cin >> inst;
	string novo;
	
	valores.clear();
	repetecos.clear();

	for(int i=0;i!=inst;i++) {

		cin >> novo;
		trabalha(novo);
		repetecos[novo]++;
		if(find(valores.begin(),valores.end(),novo)==valores.end()) {
			valores.push_back(novo);
		}
		//cout<< novo <<endl;
		
	}
	
	// para cada cara que passou
	sort(valores.begin(),valores.end(),ordenacao);
	int count = 0;
	for(int i=0;i!=valores.size();i++) {
		if(repetecos[valores[i]]!=1) {
			count++;
			cout << valores[i].substr(0,3) << "-" << valores[i].substr(3,4) << " " << repetecos[valores[i]] << endl;
		}
	}
	if(count==0) {
		cout << "No duplicates." << endl;
	}
	
	if(zzz!=ccc-1) cout << endl;
	
	}
   
   return 0;
   
}

