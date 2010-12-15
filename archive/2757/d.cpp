#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MV (10010)

class P {
public: int val,tem; P(int a,int b) { val=a;tem=b;}
};

bool cmp(const P &a,const P &b) {
	if(a.tem!=b.tem) return a.tem<b.tem;
	return a.val<b.val;
}

#define MAX(a,b) (a>b?a:b)
#define FOR(a,b) for(int a=0;a<b;a++)


int main() {
	
	int p;
	vector<P> vec;
	long v[MV][2];
	long mel[MV];

	while((cin >> p) && p) {
		FOR(i,p) cin >> v[i][0] >> v[i][1];
		FOR(i,MV) mel[i] = 0;
		vec.clear();
		FOR(i,p) vec.push_back(P(v[i][0],v[i][1]));
		sort(vec.begin(),vec.end(),cmp);
		//FOR(i,p) cout << vec[i].val << " " << vec[i].tem << endl;
		FOR(i,p) {
			for(int j=vec[i].tem;j>0;j--) {
				mel[j] = MAX(mel[j],mel[j-1]+vec[i].val);
			}
			//FOR(i,10) cout << mel[i] << " ";
			//cout << endl;
		}
		long m = 0;
		//FOR(i,10) cout << mel[i] << " ";
		//cout << endl;
		FOR(i,MV) m = MAX(m,mel[i]);
		cout << m << endl;
	}
	return 0;

}
