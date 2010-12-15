#include <iostream> 
#include <string> 
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int size;
string primeira;

map<string,int> ps;

bool sortFunction(const string &s1,const string &s2) {
	return ps[s2]>ps[s1];
}

int pontos(string &s) {
	int p = 0;
	for(int i=0;i!=size;i++) {
		if(s[i]!=primeira[i]) p++;
	}
	return p;
}

int main() {
	int morphs;
	string ultima;
	string nova;
	vector<string> vetor;
	while(cin >> morphs >> size) { 
		cin >> primeira;
		cin >> ultima;
		for(int i=0;i!=morphs-2;i++) {
			cin >> nova;
			vetor.push_back(nova);
			ps[nova] = pontos(nova);
		}
		sort(vetor.begin(),vetor.end(),sortFunction);
		cout << primeira << endl;
		for(int i=0;i!=morphs-2;i++) {
			cout << vetor[i] << endl;
		}
		cout << ultima << endl;
		ps.clear();
		vetor.clear();
	}
	return 0; 
}
