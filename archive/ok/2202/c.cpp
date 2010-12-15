#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void st() {
	int n;	cin >> n; int k;
	vector<int> v;
	for(int i=0;i!=n;i++) { cin >> k; v.push_back(k); }
	sort(v.begin(),v.end());
	long pos = (n%2)?(v[n/2]):((v[n/2]+v[n/2-1])/2);
	long long va = 0;
	for(int i=0;i!=n;i++) {
		if(v[i]>pos) va+=v[i]-pos;
		else va+=pos-v[i];
	}
	cout << va << endl;
}

int main() {

	int t; cin >> t; while(t--) st(); return 0;

}
