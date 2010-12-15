#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define FOR(a,b) for(a=0;a<b;a++)
#include <map>
using namespace std;

char l[10000];

map<string,int> autores;
struct {
	int s[10001],l,e;
	bool empty() {
		return l==e;
	}
	void clear() {
		l = e=0;
	}
	void pop() {
		l++;
	}
	int front() {
		return s[l];
	}
	int push(int i) {
		s[e++] = i;
	}
} fila;

int indexof(char *s,char c) {
	int i=0;
	while(*s!=c) {s++;i++;}
	return i;
}

char *trim(char *c) {
	while(*c==' ') c++;
	char *s = c;
	int len = strlen(s);
	while((s[len-1]==' ') && len) { len--; }
	s[len]='\0';
	return s;
}

int tot;
int quais[50];
vector<int> con[10000];
int temp;

struct {
	bool pos;
	int dep;
	bool vis;
	void clear() { pos=vis=dep=0;}
	void visita(int i) {
		pos=vis=1;
		dep=i;
	}
} _pes[10000];

void conn(int i,int j) {
	FOR(temp,con[i].size()) if(con[i][temp]==j) return;
	con[i].push_back(j);
	con[j].push_back(i);
}

void st() {

	int p,n,len,i,j,k,q;
	autores.clear();
	char *nomes,*paper;
	gets(l);
	sscanf(l,"%d %d",&p,&n);
	tot = 0;

	while(p--) {
		gets(l);
		len = strlen(l);
		j = indexof(l,':');
		l[j] = '\0';
		paper = &l[j+1];
		nomes = l;
		len = j; k = 0;
		FOR(i,len) if(nomes[i]==',') k++;
		k++; k /= 2; q = k;
		while(k--) {

			j = indexof(nomes,',');
			if(!k) j = strlen(nomes);
			else j += indexof(&nomes[j+1],',');

			nomes[j+1] = '\0';
			nomes = trim(nomes);

			string s = string(nomes);
			if(autores.find(s)
					==autores.end()) {
				autores[s] = quais[k] = tot;
				tot++;
			} else quais[k]=autores[s];

			nomes = &nomes[j+2];

		}
		FOR(i,q) for(j=i+1;j<q;j++)
			conn(quais[i],quais[j]);
	}

	int erdos = autores[string("Erdos, P.")];
	FOR(i,tot) _pes[i].clear();
	fila.clear();
	_pes[erdos].visita(0);
	fila.push(erdos);
	while(!fila.empty()) {
		j = fila.front();
		k = con[j].size();
		fila.pop();
		FOR(q,k) {
			if(!_pes[i = con[j][q]].vis) {
				fila.push(i);
				_pes[i].visita(_pes[j].dep+1);
			}
		}
	}

	while(n--) {

		gets(l);
		string s = string(l);
		if(autores.find(s)!=autores.end()) {
			int at = autores[s];
			if(_pes[at].pos) cout << l << " " << 
_pes[at].dep << endl;
			else cout << l << " infinity" << endl;
		} else {
			cout << l << " infinity" << endl;
		}
	}

	FOR(i,tot) con[i].clear();

}

int main() {
	int t,i=0;
	gets(l);
	sscanf(l,"%d",&t);
	while(t--) {
		cout << "Scenario " << ++i << endl; st();
	}
	return 0;
}

