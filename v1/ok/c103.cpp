#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

vector<int> boxes;
struct {
	int val[11];
} _box[40];

int k,d;

bool cmp(int a,int b) {
	int i;
	FOR(i,d) if(_box[a].val[i]>_box[b].val[i]) return false;
	return true;
}

bool fit(int a,int b) {
	int i;
	FOR(i,d) if(_box[a].val[i]>=_box[b].val[i]) return false;
	return true;
}

int val[50],pre[50];

void imp(int i) {
	if(pre[i]-i) {
		imp(pre[i]);
		cout << " " << (1+boxes[i]);
	} else {
		cout << (1+boxes[i]);
	}
}

void st() {

	boxes.clear();
	int i,j;
	FOR(i,k) {
		FOR(j,d) cin >> _box[i].val[j];
		sort(_box[i].val,&_box[i].val[d]);
		boxes.push_back(i);
	}
	sort(boxes.begin(),boxes.end(),cmp);
	FOR(i,k) { val[i]=1;pre[i]=i; }
	FOR(i,k) for(j=i+1;j<k;j++) {
		if(val[j]<val[i]+1 && fit(boxes[i],boxes[j])) {
			val[j] = val[i]+1; pre[j]=i;
		}
	}
	int maior = *max_element(val,&val[k]);
	cout << maior << endl;
	FOR(i,k) if(val[i]==maior) break;
	imp(i);
	cout << endl;
}


int main(){

	while((cin >> k >> d)) st();
	return 0;

}
