#include <iostream>
#include <stack>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <stdlib.h>

using namespace std;

char **val;

struct ltstr
{
  bool operator()(const int &s1, const int &s2) const
  {
    cout << strcmp(val[s1], val[s2]) << "," << val[s1] << "," << val[s2] << endl;
    return strcmp(val[s1], val[s2]) <= 0;
  }
};

int cmp(const int &s1,const int &s2) {
	return 0;
}

int tot;
set<int,ltstr> l;
stack<int> q;

void gera(int at,int p) {
	int i;
	char j;
	for(i=0;i!=10;i++) val[tot][i]=val[at][i];
	j = val[at][p];
	val[tot][p] = val[at][p+1]; val[tot][p+1] = val[at][p+4]; val[tot][p+4] = val[at][p+3]; val[tot][p+3] = j;
	if(find(l.begin(),l.end(),tot)==l.end()) {
		cout << "g: " << val[tot] << endl;
		l.insert(tot);
		q.push(tot++);
	}
}

int main() {

	int i,j,k;
	val = (char **) malloc(sizeof(char *)*10000);
	for(i=0;i!=10000;i++) val[i] = (char *) malloc(sizeof(char)*12);
	while((scanf("%s",val[0]))) {
		if(val[0][0]=='E') break;
		l.clear();
		l.insert(0);
		tot = 1;
		while(!q.empty()) q.pop();
		q.push(0);
		while(!q.empty()) {
			i = q.top();	
			q.pop();
			cout << val[i] << endl;
			gera(i,0);
			gera(i,1);
			gera(i,3);
			gera(i,4);
		}
		cout << endl;
	}
	return 0;

}
