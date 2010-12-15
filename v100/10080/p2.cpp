#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>

using namespace std;

class Path {
	public:
	int from,to;
	int cur,maxi;
	int outro;
	bool ok() {
		if(cur<maxi) {
			return true;
		} else {
			return false;
		}
	}
	int livre() {
		return maxi - cur;
	}
};

class Vertex {
	public:
	int id;
	int len;
	vector<int> paths;
	void clear(int i) {
		paths.clear();
		len = 0;
		id = i;
	}
};

// data
int pathstot = 0;
Path paths[110*110];
int vertextot = 0;
Vertex vertex[220];

// connecting links
void connect(int i,int j,int val) {
	paths[pathstot].from = paths[pathstot+1].to = i;
	paths[pathstot+1].from = paths[pathstot].to = j;
	paths[pathstot].cur = paths[pathstot+1].cur = 0;
	paths[pathstot].maxi = paths[pathstot+1].maxi = val;
	paths[pathstot].outro = pathstot+1;
	paths[pathstot+1].outro = pathstot;
	vertex[i].paths.push_back(pathstot);
	vertex[i].len++;
	vertex[j].paths.push_back(pathstot+1);
	vertex[j].len++;
	pathstot+=2;
}

// current path
int path[300];
int pathlen;
bool visitado[300];

int n,m,s,v;

// find path
bool findpath(int source,int sink,int level) {
	
	/*for(int i=0;i!=pathlen;i++) {
		cout << paths[path[i]].to << " ";
	}
	cout << endl;*/
	
	visitado[source] = true;
	int start,end;
	if(level==0) {
		start = 0;
		end = n - 1;
	} else if(level==1) {
		start = n;
		end = n + m - 1;
	} else if(level==2) {
		start = sink;
		end = sink;
	}
	for(int i=0;i!=vertex[source].len;i++) {
		int prox = vertex[source].paths[i];
		//cout << "tentando ir para " << paths[prox].to << endl;
		if(!visitado[paths[prox].to] && paths[prox].ok()) {
			//cout << "olha: " << paths[prox].ok() << endl;
			if(paths[prox].to<start || paths[prox].to>end) continue;
			if(paths[prox].to==sink) {
				// achei!
				return true;
			} else {
				path[pathlen++] = prox;
				if(findpath(paths[prox].to,sink,level+1)) return true;
				pathlen--;
			}
		}
	}
	visitado[source] = false;
	return false;
}

int main() {
	
	double gopher[110][2];
	double hole[110][2];

	while((cin >> n >> m >> s >> v)) {
		for(int i=0;i!=n;i++){
			vertex[i].clear(i);
			cin >> gopher[i][0] >> gopher[i][1];
		}
		for(int i=0;i!=m;i++) {
			cin >> hole[i][0] >> hole[i][1];
		}
		vertextot = n + m;
		double dist,mdist = v * s * v * s;
		pathstot = 0;
		
		// generating connections
		for(int i=0;i!=n;i++) {
			for(int j=0;j!=m;j++) {
				dist = (gopher[i][0]-hole[i][0])*(gopher[i][0]-hole[i][0]) + 
					(gopher[i][1]-hole[i][1])*(gopher[i][1]-hole[i][1]);
				if(dist<mdist) {
					// possivel
					connect(i,n+j,1);
				}
			}
		}
		
		// creating the source and sink
		int source = vertextot;
		for(int i=0;i!=n;i++) {
			connect(vertextot,i,1);
		}
		int sink = vertextot+1;
		for(int j=n;j!=vertextot;j++) {
			connect(j,vertextot+1,1);
		}
		vertextot+=2;
		
		// here we go....
		int total = 0, pos, min;
		while(true) {
			pathlen = 0;
			for(int i=0;i!=vertextot;i++) visitado[i] = false;
			if(!findpath(source,sink,0)) break;
			min = paths[path[0]].livre();
			for(int i=1;i<pathlen;i++) {
				if(paths[path[i]].livre()<min) {
					min = paths[path[i]].livre();
				}
			}
			for(int i=0;i<pathlen;i++) {
				pos = path[i];
				paths[pos].cur += min;
				paths[paths[pos].outro].cur = - paths[pos].cur;
			}
			total += min;
		}
		cout << (n-total) << endl;
		
	}
	return 0;
	
}
