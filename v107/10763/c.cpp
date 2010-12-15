#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define PI pair<int,int>

int main() {

	int n,i,j,k,val;
	map<PI,int> m;

	while((cin >> n) && n) {

		m.clear();

		while(n--) {

			cin >> i >> j;

			if(i>j) {
				val=-1;
				swap(i,j);
			} else val=1;

			PI p = make_pair(i,j);
			if(m.find(p)!=m.end()) {
				val += (*(m.find(p))).second;
				if(val)
					m[p] = val;
				else
					m.erase(p);
			} else m[p]=val;

		}

		if(!m.size()) cout << "YES"<<endl;
		else cout << "NO" << endl;

	}
	return 0;
	
}
