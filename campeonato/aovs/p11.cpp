#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define PR pair<int,pair<int,int> >
#define Swap(a,b) { j=a; a=b; b=j; }

vector<PR> v;

#define fit(a,b) ((v[a].first<v[b].first && v[a].second.first<v[b].second.first))

int main() {

	int n,i,j,k,a,b,c;
	int *m = new int[10000];
	while((cin >> n) && n) {

v.clear();
for(i=0;i<n;i++) {
	cin >> a >> b >> c;
//	if(a>b) swap(a,b);
//	if(b>c) swap(b,c);
//	if(a>b) swap(a,b);
//	cout << a << " " << b << " " << c << endl;
	v.push_back(make_pair(a,make_pair(b,c)));
//	v.push_back(make_pair(b,make_pair(a,c)));
//	v.push_back(make_pair(b,make_pair(c,a)));
//	v.push_back(make_pair(c,make_pair(a,b)));
//	v.push_back(make_pair(c,make_pair(b,a)));
}
sort(v.begin(),v.end());
//for(i=0;i<n;i++) cout << v[i].first << endl;
int maior = 0;
for(i=0;i<n*5;i++) if(v[i].second.second>maior) maior=v[i].second.second;
for(i=0;i<n*5;i++) m[i]=v[i].second.second;
m[n]=maior;

for(i=0;i<n*5;i++) {
	for(j=i+1;j<n*5;j++) {
		if(fit(i,j)) {
			m[j]=max(m[j],m[i]+v[j].second.second);
		}
	}
}
for(i=0;i<n*5;i++) {
	cout << m[i] << " ";
}

for(i=0;i<n*5;i++) maior=max(maior,m[i]);


cout << maior << endl;


	}
	return 0;

}

