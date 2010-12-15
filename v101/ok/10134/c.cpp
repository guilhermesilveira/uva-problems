#include <iostream>
#include <stdio.h>

using namespace std;

void st() {

	int lf = 10;
	int tent = 2;
	int bt = 0, fis=0;
	int time = 0;
	scanf(" ");
	char s[10];
	while(true) {
//		cout << lf << " baits: " << bt << " tent: " << tent << endl;
		if(!(gets(s))) break;
		if(s[0]=='\n' || s[0]=='\r' || s[0]=='\0') break;
		if(s[0]=='l') {
			lf++;
			//cout << lf << ": lunch" << endl;
		} else if(s[0]=='b') {
			lf++;
			if(bt!=6) bt++;
			//cout << "cmd baits"<< endl;
		} else if(s[0]=='f') {
			lf++;
//			cout << lf << ": fish try: " << tent << endl;
			if(bt<2) continue;
			tent++;
			if(lf<6) continue;
			if(tent<3) continue;
			tent = 0;
			lf = 0;
			bt-=2;
			fis++;
			//cout << lf << ": fish: " << fis << endl;
		}
	}

	cout << fis << endl;

}

int main() {

	int t;
	cin >> t;
	while(t--) {
		st();
		if(t!=0) cout << endl;
	}
	return 0;

}
