#include <iostream>
#include <assert.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char line[300];

#define rl() fgets(line,97,stdin)

int h[1101];
int n;
int maxv;

int length[1101];
int pre[1101];

void start() {
	n = 0;
	maxv = 0;
	while(gets(line) && line[0]!='\0' && line[0]!='\r' && line[0]!='\n') {
		sscanf(line,"%d",&h[n++]);
//		cout << h[n-1] << endl;
	}
	assert(n<1051);
	for(int i=0;i!=n;i++) {
		pre[i] = -1;
		length[i] = 1;
	}
	for(int i=0;i!=n;i++) {
		for(int j=i+1;j<n;j++) {
			if(h[j]>h[i]) {
				if(length[i]+1>length[j]) {
					length[j] = length[i]+1;
					if(length[j]>length[maxv]) {
						maxv = j;
					}
					pre[j] = i;
				}
			}
		}
	}
	cout << "Max hits: " << length[maxv] << endl;
	stack<int> st;
	while(pre[maxv]!=-1) {
		st.push(h[maxv]);
		maxv = pre[maxv];
	}
	cout << (h[maxv]) << endl;
	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}

int main () {
	
	int c;
	scanf("%d\n",&c);
	while(c--!=0) {
		start();
		if(c!=0) printf("\n");
	}
	return 0;
	
}
