#include <iostream>
#include <string>

using namespace std;

int m[26][6];
string z[90000];
string s;
int len;
int n;

void faz() {
}

void zera() {
	int i,j,c=0;
	for(i=0;i!=26;i++) {
		m[i][0] = c++;
	}
	c = 0;
	int k = 26;
	for(i=0;i!=25;i++) {
		c += k;
		k--;
		m[i][1] = c;
		cout << (char)('a' + i) << "[1] = "  << c << endl;
	}
	m[i][1] = -1;
	
	
}

int main() {

	int i;
	char l;
	zera();
	while((cin>>s)) {
		len = s.length();
		for(i=0;i!=len;i++) {
			if(s[i]<=l) break;
		}
		if(i!=len) {
			cout << 0 << endl;
			continue;
		}
		n = 1;
		faz();
		cout << n << endl;
	}

	return 0;

}
