#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;
	int len;
	while(true) {
		cin >> s;
		len = s.length();
		if(s[0]=='#') break;
		long long v = 0;
		long long k = 1;
		for(int i=len-1;i>=0;i--) {
			int z = 0;
			if(s[i]=='%') z = 0;
			else if(s[i]==')') z = 1;
			else if(s[i]=='~') z = 2;
			else if(s[i]=='@') z = 3;
			else if(s[i]=='?') z = 4;
			else if(s[i]=='\\') z = 5;
			else if(s[i]=='$') z = -1;
			z = z * k;
			v += z;
			k *= 6;
		}
		cout << v << endl;
	}
	
	return 0;

}



