#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	int m,n;
	double val;
	string t;
	map<string,double> mapa;
	while((cin >> m >> n)) {
		mapa.clear();
		while(m--) {
			string s = string();
			cin >> s >> val;
			mapa[s] = val;
		}
		while(n--) {
			val = 0;
			while((true)) {
				cin >> t;
				if(t[0]=='.') break;
				if(mapa.find(t)!=mapa.end()) {
					val += mapa[t];
				}
			}
			cout << val << endl;
		}
	}

}
