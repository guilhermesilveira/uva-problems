#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(char **argv,int argc) {

	string p,e;
	char *root;
	char tv;
	int c = 0, conj;
	while((cin >> p >> e)) {
		if(c++!=0) cout << endl;
		cout << p << " (to " << e << ")" << endl;
		int len = p.size();
		if(p[len-1]=='r' && p[len-2]=='a') {
			root = (char *)p.c_str();
			root[len-2] = '\0';
			tv = 'a';
			conj = 1;
		} else if(p[len-1]=='r' && p[len-2]=='e') {
			root = (char *)p.c_str();
			root[len-2] = '\0';
			tv = 'e';
			conj = 2;
		} else if(p[len-1]=='r' && p[len-2]=='i') {
			root = (char *)p.c_str();
			root[len-2] = '\0';
			tv = 'i';
			conj = 3;
		} else {
			cout << "Unknown conjugation" << endl;
			conj = 0;
		}
		if(conj!=0) {
			cout << "eu        " << root << "o" << endl;
			if(conj!=3) {
				cout << "tu        " << root << tv << "s" << endl;
			} else {
				cout << "tu        " << root << "es" << endl;
			}
			cout << "ele/ela   " << root << (conj==3?'e':tv) << endl;
			cout << "n" << (char) 243 << "s       " << root << tv << "mos" << endl;
			cout << "v" << (char) 243 << "s       " << root << tv << (conj==3?"s":"is") << endl;
			if(conj==3) {
				cout << "eles/elas " << root << "em" << endl;
			} else {
				cout << "eles/elas " << root << tv << "m" << endl;
			}
		}
	}

	return 0;

}
