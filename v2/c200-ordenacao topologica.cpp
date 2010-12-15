#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

int at,ou;
char s[2][30];

struct {
	bool ap,ja;
	map<char,int> dep;
	void clear() { ap=ja=0; }
} letra[30];

//  aaa
//  aab

// ab
// b

// a
// ba

// ab
// abd

#define FOR(a,b) for(int a=0;a<b;a++)

void con() {
//	cout << s[ou] << " " << s[at] << endl;
	int l1 = strlen(s[ou]), l2 = strlen(s[at]);
	int men = min(l1,l2);
	char c1,c2;
	for(int i=0;i!=men;i++) {
		if((c1=s[ou][i])!=(c2=s[at][i])) {
			letra[c2-'A'].dep[c1-'A'] = 1;
//			cout << c2 << " dep de " << c1 << endl;
			break;
		}
	}
	FOR(i,l1) letra[s[ou][i]-'A'].ap=1;
	FOR(i,l2) letra[s[at][i]-'A'].ap=1;
}

void imp(int p) {
	if(letra[p].ap && !letra[p].ja) {
		letra[p].ja=1;
		FOR(i,30) {
			if(letra[p].dep.find((char)i)!=letra[p].dep.end()) {
				imp(i);
			}
		}
		cout << (char)(p+'A');
	}
}

int main() {

	int l = 0;
	at = 0; ou = 1;
	FOR(i,30) letra[i].clear();
	while(true) {
		cin >> s[at];
		if(s[at][0]=='#') break;
		if(l) con();
		l++;
		ou = at; at = !at;
	}

	/*FOR(i,30) { cout << "i:" << ((char) (i+'A')) << endl; FOR(j,30) if(letra[i].dep.find((char)j)!=letra[i].dep.end()) cout << (char) (j+'A') << " "; cout << endl; }*/

	FOR(i,30) imp(i); cout << endl;

	return 0;
}
