#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

#define MAX (100000)

int find(long long v, long long *ord, int left, int right) {
	
	if(ord[left]==v || ord[right]==v) return -1;
	
	int meio = (right + left) / 2;
	
	// nao existe na sequencia, fim
	if(meio==left) {
		if(ord[left]>v) {
			return left;
		} else {
			return right;
		}
	}
	
	if(ord[meio]==v) return -1;

	if(ord[meio]<v) {
		// eh menor
		return find(v,ord,meio,right);
	} else {
		// eh maior
		return find(v,ord,left,meio);
	}
	
	assert(false);
	return -2;
	
}

int main() {

	int maxv,i,j,c=0;
	long long t;
	long long *val = new long long[MAX], *pre = new long long[MAX], *mval = new long long[MAX];
	long long *ord = new long long[MAX];
	int ordc = 0;
	int pos;

	while((cin >> t)) val[c++] = t;

	for(i=0;i!=c;i++) { pre[i] = mval[i] = -1; }

	for(i=0;i!=c;i++) {

		if(ordc==0 || ord[ordc-1]<val[i]) {
			
			// novo
			ord[ordc] = val[i];
			mval[ordc] = i;
			if(ordc!=0) {
				pre[i] = mval[ordc-1];
			}
//			cout << "adicionando " << val[i] << " em " << ordc << endl;
			ordc++;

		} else {

			// substituindo
			if(ord[0] <= val[i]) {
				pos = find(val[i],ord,0,ordc-1);
				if(pos==-1) continue;
			} else {
				pos = 0;
			}

			ord[pos] = val[i];
			mval[pos] = i;
			pre[i] = mval[pos-1];
//			cout << "adicionando " << val[i] << " em " << pos << endl;
	
		}

	}

	stack<long long> st;
	cout << ordc << endl << "-" << endl;
	ordc = mval[ordc - 1];
	while(pre[ordc]!=-1) {
		st.push(val[ordc]);
		ordc = pre[ordc];
	}
	cout << val[ordc] << endl;
	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
	
}
