#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
	int id;
	vector<Node *> children;
	vector<bool> passado;
	int group;
	bool operator == (Node &n2) {
		return id==n2.id;
	}
};

int nodeCount;
vector<Node *> nodes;

Node *primeiro;

//vector<Node *> passados;

/*void printPath() {
	for(int i=0;i!=nodes.size();i++) {
		cout << nodes[i]->id << " --> ";
	}
	cout << endl;
}*/

int dfs(Node *n) {

	//passados.push_back(n);
	
	cout << "indo para: " << n->id << endl;

	int s = n->children.size();
	bool found = false;
	Node *c;
	
	// tenta para os filhos deste node
	for(int i=0;i!=s;i++) {
		
		c = n->children[i];
		if(c==nodes[0]) {
			// achou um caminho final...
			if(found) {
				return 2;
			} else {
				found = true;
			}
		} else {
			// verifica se ja passou por ele
			//if(find(passados.begin(),passados.end(),c)==passados.end()) {
			if(!n->passado[i]) {
				n->passado[i] = true;
				int z = dfs(c);
				// verifica se achou um dos fins...
				if(z==1) {
					if(found) {
						return 2;
					} else {
						found = true;
					}
				} else if(z>1) {
					return 2;
				}
			}
			n->passado[i]=false;
			//}
		}
		
	}
	
	return 0;

}

int main(int argc, char **argv) {

	int inst;
	int connectionCount;
	int in1,in2;
	
	scanf("%d\n",&inst);
	
	while(inst!=0) {
	
		nodes.clear();
		scanf("%d\n%d\n",&nodeCount,&connectionCount);
		
		for(int i=0;i!=nodeCount;i++) {
			Node *n = new Node();
			n->id = i;
			n->group = i;
			nodes.push_back(n);
		}
		
		for(int i=0;i!=connectionCount;i++) {
			scanf("%d %d\n",&in1,&in2);
			Node *n1 = nodes[in1];
			Node *n2 = nodes[in2];
			n1->children.push_back(n2);
			// para todos os nodes com grupo do n2, coloca o grupo do n1
			for(int z=0;z!=nodes.size();z++) {
				if(nodes[z]->group==n2->group) {
					nodes[z]->group = n1->group;
				}
			}
		}

		for(int i=0;i!=nodeCount;i++) {
			if(nodes[i]->group!=nodes[0]->group) {
				printf("NO disconnected\n");
				goto proximaInst;
			}
		}
		
		// se o ciclo for maior que 1
		primeiro = nodes[0];
		//passados.clear();
		if(dfs(nodes[0])==1) {
			printf("YES\n");
		} else {
			printf("Nao eh cactus NO\n");
		}
		
		proximaInst:
		inst--;
		
	}

	return 0;

}
