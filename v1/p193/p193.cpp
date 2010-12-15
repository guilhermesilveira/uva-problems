#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INCOLOR		0
#define BLACK		1
#define	WHITE		2

struct node {
	int id;
	vector<int> filhos;
	int color;
	int nfilhos;
};

void clear(node &n) {
	n.color = INCOLOR;
	n.filhos.clear();
}

int nodeCount;
int blackCount;
vector<node> pool;
vector<int> nodes;

bool compNodes(const int &n1,const int &n2) {
	return pool[n1].nfilhos < pool[n2].nfilhos;
}

int main(int argc, char **argv) {
	
	int inst;
	scanf("%d",&inst);
	
	for(int i=0;i!=100;i++) {
		node n;
		n.id = i;
		pool.push_back(n);
	}
	
	while(inst--!=0) {
		
		long int n;
		int a,b;
		scanf("%d %ld",&nodeCount,&n);
		nodes.clear();
		blackCount=0;
		//nextToCheck = 0;
		for(int i=0;i!=nodeCount;i++) {
			nodes.push_back(i);
			clear(pool[i]);
		}
		for(int i=0;i!=n;i++) {
			scanf("%d %d", &a, &b);
			pool[a-1].filhos.push_back(b-1);
			pool[b-1].filhos.push_back(a-1);
		}
		for(int i=0;i!=nodeCount;i++) {
			pool[i].nfilhos = pool[i].filhos.size();
		}
		
		// pinta um a um
		while(nodes.size()!=0) {

			sort(nodes.begin(),nodes.end(),compNodes);

			node &n = pool[nodes[0]];
			nodes.erase(nodes.begin());
			//printf("%d %d\n",n.id,n.color);
			if(n.color==WHITE) continue;
			
			/*for(int z=0;z!=n.filhos.size();z++) {
				if(pool[n.filhos[z]].color==BLACK) {
					//printf("%d white pois %d\n",n.id,pool[n.filhos[z]].id);
					n.color=WHITE;
					break;
				}
				//printf("filho %d",n.filhos[z].id);
			}*/
			//if(n.color==INCOLOR) {
				n.color=BLACK;
				blackCount++;
				//printf(" preto\n");
				// seta os parentes como branco
				for(int z=0;z!=n.filhos.size();z++) {
					node &filho = pool[n.filhos[z]];
					filho.color = WHITE;
					//printf("%d white\n",filho.id);
					// remove uma de cada soma de conexoes
					for(int k=0;k!=filho.filhos.size();k++) {
						pool[filho.filhos[k]].nfilhos--;
					}
				}
			/*} else {
				//printf("%d %d\n",n.id,n.color);
			}*/

		}
		
		// imprime o resultado
		printf("%d\n",blackCount);
		for(int i=0;i!=nodeCount;i++) {
			if(pool[i].color==BLACK) {
				if(--blackCount==0) printf("%d",pool[i].id+1);
				else printf("%d ",pool[i].id+1);
			}
		}
		printf("\n");
		
	}
	
	return 0;

}
