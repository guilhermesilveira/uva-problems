#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const int *c1,const int *c2) {
	if(c1[0]!=c2[0]) return c1[0]<c2[0];
	return c1[1]>c2[1];
}

int pre[1010];
vector<int*> vec;

void imp(int i) {
	//cout << "l: " << i << " " << pre[i] << endl;
	if(pre[i]!=-1) imp(pre[i]);
	cout << (vec[(i)][2] + 1) << endl;
}


int main() {

	int *v;
	int val[1010];
	int tot = 0;
	while(true) {
		v = new int[3];
		if(!(cin >> v[0] >> v[1])) break;
		v[2] = tot++;
		vec.push_back(v);
	}

	int i,j,k,len = vec.size();

	sort(vec.begin(),vec.end(),cmp);

	for(i=0;i!=len;i++) {
		val[i] = 1;
		pre[i] = -1;
		//cout << i <<": " << vec[i][2] << endl;
	}

	for(i=0;i!=len;i++) {
		for(j=i+1;j<len;j++) {
			// ignora
			if(vec[j][0]==vec[i][0]) continue;
			if(vec[j][1]<vec[i][1]) {
				//cout << i << " " << j << endl;
				if(val[j]<val[i]+1) {
					val[j] = val[i] + 1;
					pre[j] = i;
				}
			}
		}
	}

	/*for(i=0;i!=len;i++) {
		cout << i <<": " << vec[i][2] << " " << val[i] << " " << pre[i] << endl;
	}*/


	int maxi = *max_element(&val[0],&val[len]);
	for(i=len-1;i>=0;i--) {
		if(val[i]==maxi) break;
	}
	int vz = i;
	cout << maxi << endl;
//	cout << vz << " " << maxi << endl;
	imp(vz);

//	cout << "f" << endl;

	return 0;

}
