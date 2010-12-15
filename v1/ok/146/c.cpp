#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	
	string s;
	int len,i;
	while(true) {
		cin >> s;
		if(s[0]=='#') break;
		len = s.size();
		for(i=1;i<len;i++) if(s[i]>s[i-1]) break;
		if(i==len) {
			cout << "No Successor" << endl;
			continue;
		}
		next_permutation(s.begin(),s.end());
		cout << s << endl;
	}
	return 0;
}
