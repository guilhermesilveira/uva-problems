#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int main() {

	vector<long> s;
	long i,j,n,a,b,d,ia,ib,id,ic,c;

	while((cin >> n) && n) {
		s.clear();
		FOR(i,n) { cin >> j; s.push_back(j); }
		sort(s.begin(),s.end());

for(id=n-1;id>=0;id--) { d = s[id];
FOR(ia,n) {
	if(ia==id) continue;
	a = s[ia];
	for(ib = ia + 1; ib < n; ib++) {
		b = s[ib];
		if(ib==id || ib==ia || (c=d-a-b)==d || c==b || 
c==a) continue;
		if(binary_search(s.begin(),s.end(),d-a-b)) {
			cout << (d) << endl; goto en;
		}
	}
}
}

	cout << "no solution" << endl;
	en:;

	}
	return 0;

}

