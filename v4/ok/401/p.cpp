#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	string l;
	bool ispal, ismir;
	string valid = "AEHIJLMOSTUVWXYZ12358";
	string rev = "A3HILJMO2TUVWXY51SEZ8";
	
	while((getline(cin,l,'\n'))) {
	
		string g = l;
		reverse(g.begin(),g.end());
		ispal = (g == l);
		ismir = false;
		
		int len = l.length();
		string k = l;
		for(int i=0;i!=len;i++) {
			if(valid.find(l[i])==string::npos) {
				goto p;
			} else {
				k[i] = rev[valid.find(l[i])];
			}
		}
		
		reverse(k.begin(),k.end());
		//cout << "cacando: " << k << endl;
		if(k==l) ismir = true;
		
		p:
		
		if(!ispal && !ismir) {
			cout << l << " -- is not a palindrome." << endl;
		} else if(ispal && !ismir) {
			cout << l << " -- is a regular palindrome." << endl;
		} else if(!ispal && ismir) {
			cout << l << " -- is a mirrored string." << endl;
		} else {
			cout << l << " -- is a mirrored palindrome." << endl;
		}
		cout << endl;
		
	}

	return 0;

}
