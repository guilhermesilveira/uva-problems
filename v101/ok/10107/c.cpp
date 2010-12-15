#include <iostream>
#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Node {
public:
	Node(int v) {
		this->v=v;
	}
	Node *pr;
	long v;
};

Node *root = new Node(0);
Node *last = root;

long pega(int n) {
	//cout << "pega " << n << endl;
	Node *node = root;
	for(int i=0;i!=n;i++) {
		node = node->pr;
	}
	return node->v;
}

void adi(Node *n,Node *nov) {
	if(nov->v < n->pr->v) {
		nov->pr = n->pr;
		n->pr = nov;
		return;
	}
	adi(n->pr,nov);
}

void imp(Node *n) {
	cout << n->v << " ";
	if(n!=last) imp(n->pr);
}

int main() {

	long k;
	int n = 1;
	cin >> k;
	last = root = new Node(k);
	cout << k << endl;
	while((cin >> k)) {
		n++;
		Node *nod = new Node(k);
		if(k >= last->v) { last->pr = nod; last = nod; }
		else if(root->v >= k) { nod->pr = root; root = nod; }
		else adi(root,nod);
		//imp(root); cout << endl;
		if(n%2==0) {
			cout << (long) ((pega(n/2)+pega(n/2-1))/2.0) << endl;
		} else {
			cout << pega(n/2) << endl;
		}
	}
	return 0;

}
