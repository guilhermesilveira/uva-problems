#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
	string name;
	vector<Node *> children;
	int group;
	bool operator == (Node &n2) {
		return name==n2.name;
	}
};

class Path {
public:
	vector<Node *> nodes;
	Node *lastNode() {
		return nodes[nodes.size()-1];
	}
	void add(Node *n) {
		nodes.push_back(n);
	}
	bool contains(Node *n)  {
		return find(nodes.begin(),nodes.end(),n)!=nodes.end();
	}
	void copy(Path *c) {
		for(int i=0;i!=c->nodes.size();i++) {
			add(c->nodes[i]);
		}
	}
};

int nodeCount;

map<string,Node *> nodes;
vector<Node *> nodesVector;
vector<Node *> hasBeenAtList;

/* 
 * Checks whether this node has been visited in an earlier path
 */
bool hasBeenAt(Node *n) {
	return find(hasBeenAtList.begin(),hasBeenAtList.end(),n)!=hasBeenAtList.end();
}

int getDistanceBetween(Node *from,Node *to) {

	vector<Path *> pilha;
	Path *c1 = new Path();
	c1->add(from);
	pilha.push_back(c1);

	hasBeenAtList.clear();
	
	while(!pilha.empty()) {
	
		Path *c = pilha[0];
		pilha.erase(pilha.begin());
		hasBeenAtList.push_back(c->lastNode());
		
		// para cada node conectado ao ultimo
		for(int i=0;i!=c->lastNode()->children.size();i++) {
			if(c->lastNode()->children[i]==to) {
				// achou
				return c->nodes.size();
			} else {
				// se ainda nao estiver no Path
				if(!hasBeenAt(c->lastNode()->children[i])) {
					Path *novo = new Path();
					novo->copy(c);
					novo->add(c->lastNode()->children[i]);
					pilha.push_back(novo);
				}
			}
		}
		
	}
	
	return 0;
	
}

int main(int argc, char **argv) {

	int questionCount;
	int connectionCount;
	int inst;
	int inst2 = 0;
	int i;
	int z;
	
	scanf("%d\n",&inst);
	
	cout << "SHIPPING ROUTES OUTPUT" << endl;
	
	while(inst--!=0) {
	
		nodes.clear();
		nodesVector.clear();
	
		printf("\nDATA SET  %d\n\n",(++inst2));
		
		scanf("%d %d %d\n",&nodeCount,&connectionCount,&questionCount);
		
		for(i=0;i!=nodeCount;i++) {
			Node *n = new Node();
			cin >> n->name;
			n->group = i + 1;
			nodes[n->name]=n;
			nodesVector.push_back(n);
		}
		
		string a,b;
		for(i=0;i!=connectionCount;i++) {
			cin >> a >> b;
			Node *n1 = nodes[a];
			Node *n2 = nodes[b];
			n1->children.push_back(n2);
			n2->children.push_back(n1);
			// para todos os nodes, checa se eh o mesmo 
			for(z=0;z!=nodesVector.size();z++) {
				if(nodesVector[z]->group==n2->group) {
					nodesVector[z]->group = n1->group;
				}
			}
		}

		int peso;
		for(i=0;i!=questionCount;i++) {
			cin >> peso >> a >> b;
			if(nodes[a]->group==nodes[b]->group) {
				cout << "$" << (peso * getDistanceBetween(nodes[a],nodes[b]) * 100) << endl;
			} else {
				printf("NO SHIPMENT POSSIBLE\n");
			}
		}
		
	}

	return 0;

}
