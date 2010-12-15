#include <iostream>
#include <string>

using namespace std;

bool b;

string parse(string s,int len) {

	if(s[0]=='2' && len==1) goto bz;
	if(s[0]=='2') return s.substr(1,len-1);
	if(s[0]=='3' && len==1) goto bz;
	if(s[0]=='3') {
		string z = parse(s.substr(1,len-1),len-1);
		return z + "2" + z;
	}

bz:
	b = false; return "";

}

int main() {

	string s;
	while((cin >> s)) {
		if(s[0]=='0' && (s[1]=='\n' || s[1]=='\r' || s[1]=='\0')) break;
		int len = s.size();
		b = true;
		for(int i=0;i!=len;i++) if(s[i]=='0') goto iz;
		s = parse(s,s.size());
		if(!b) goto iz;
		cout << s << endl;
continue;
	iz:cout<< "NOT ACCEPTABLE" << endl;
	}
	return 0;

}
