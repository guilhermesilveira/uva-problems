#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;

#define FOR(a,b) for(a=0;a<b;a++)

int tem[11000];

void st() {

	priority_queue<int, vector<int>, greater<int> > q;
	int i,j,k,l;
	FOR(i,11000) tem[i]=-1;
	FOR(i,n) {
		cin >> j >> l;
		tem[j] = l;
		q.push(l);
	}

	int tempo = 1;
	int pos = q.top();

	while(!q.empty()) {
		l = q.top();
		q.pop();
		cout << "tempo: " << l << endl;
		
	}

}


int main() {

	while((cin >> n) && n) {
		st();
	}
	return 0;

}
