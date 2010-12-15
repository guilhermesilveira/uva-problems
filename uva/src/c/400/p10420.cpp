#include <iostream> 
#include <string> 
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> v;
map<string,int> m;

bool comp(const string &c1,const string &c2) {
	return c1>c2;
}

int main(int argc,char **argv) {
	
	int total;
	cin >> total;
	string p;
	
	while(total--!=0) {
		cin >> p;
		if(find(v.begin(),v.end(),p)!=v.end()) {
			m[p]++;
		} else {
			m[p]=1;
			v.push_back(p);
		}
		getline(cin,p);
	}	
	
	sort(v.begin(),v.end(),comp);

	for(total=v.size()-1;total!=-1;total--) {
		cout << v[total] << " " << m[v[total]] << endl;
	}
	
	return 0; 
	
}
