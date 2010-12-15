#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(const int a,const int b) {
	return a>b;
}

int main() {

	int val[10001][2];
	int tot[10001];
	vector<int> t;
	priority_queue<int> pq;

	int n,j,k,axi;
	while((cin >> n)) {

		axi=0;
		while(!pq.empty()) pq.pop();
		t.clear();

		for(int i=0;i!=10001;i++) { 
			tot[i] = 0;
		}

		for(int i=0;i!=n;i++) {

			cin >> j >> k;
			val[i][0] = j;
			val[i][1] = k;

			pq.push_back(j);

			tot[j]++;
			if(k>axi) axi = k;

		}

		long long vala = 0;

		for(int i=1;i<=axi;i++) {
			int v = pq.top(); pq.pop();
			for(k=0;k!=n;k++) {
				// o maior vai ser esgotado
				if(val[k][1]==i && val[k][0]==v) tot[val[k][0]]--;
			}
			if(v==-1) while(true);
			vala += v;
			for(k=0;k!=n;k++) if(val[k][1]==i) tot[val[k][0]]--;
		}

		f:
		cout << vala << endl;


	}
	return 0;

}
