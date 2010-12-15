#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<long,long> mapa;
vector<long> ordem;
set<long> contem;

int main(char **argv,int argc) {

	long l;
	while((cin >> l)) {
		mapa[l]++;
		if(!binary_search(contem.begin(),contem.end(),l)) {
			contem.insert(l);
			ordem.push_back(l);
		}
	}
	
	for(vector<long>::iterator i=ordem.begin();i!=ordem.end();i++) {
		cout << (*i) << " " << mapa[*i] << endl;
	}

	return 0;

}
