/* @JUDGE_ID: 39315ZN 122 C++ "Largura" */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

//long pos[256];
string pos[256];
long nv[256];
int ncount;
vector<int> vt;
//vector<long> contem;
vector<string> contem;

bool vtsort(const int &i1, const int &i2) {
	return pos[i1]<pos[i2];
}

int main(int argc, char **argv) {

	char c;
	string node;
	
	while(cin >> c) {
	
		if(c=='(') {

			ncount = 0;
			vt.clear();
			contem.clear();
			bool notComplete = false;
			
			// comeca um novo item
			while(cin>>node && node!="()") {
				//cout << "a";
				if(!notComplete) {
					//cout << node;
					if(node[0]=='(') {
						node=node.substr(1,node.length()-1);
					} else {
						node=node.substr(0,node.length()-1);
					}
					nv[ncount] = atol(node.substr(0,node.find(',')+1).c_str());
					node = node.substr(node.find(',')+1);
					//cout << "indo";
					pos[ncount] = "";
					int i = 0;
					for(i=0;i!=node.length();i++) {
						if(node[i]=='L' || node[i]=='l') {
							//pos[ncount]=pos[ncount]*10+1;
							pos[ncount].append("L");
							//pos[ncount][i]='L';
						} else if(node[i]=='r' || node[i]=='R') {
							//pos[ncount]=pos[ncount]*10+2;
							//pos[ncount][i]='R';
							pos[ncount].append("R");
						}
					}
					if(find(contem.begin(),contem.end(),pos[ncount])!=contem.end()) {
						notComplete=true;
						//cout << "existe repetido" << endl;
					} else {
						//cout << "adding: " << pos[ncount]<< endl;
						contem.push_back(pos[ncount]);
						//cout << "pushou um";
						vt.push_back(ncount);
						ncount++;
						//cout << "pushou";
					}
				} else {
					//cout << "ignoring: " << node << endl;
				}
			}
			
			//cout << "indo checar" << endl;
			
			if(!notComplete) {
				
				sort(vt.begin(),vt.end(),vtsort);
				
				// ve se faltaAlgum
				for(int z=0;z!=vt.size();z++) {
					// se os pais ate o root nao existe...
					//pos[vt[i]]/=10;
					for(int i=0;i<pos[z].length();i++) {
						//cout << "procurando " << i << " " << pos[z].substr(0,i) << endl;
						if(find(contem.begin(),contem.end(),pos[z].substr(0,i))==contem.end()) {
							// nao contem
							goto nc;
						}
					}
				}
				
				for(int i=0;i!=vt.size();i++) {
					if(i!=0) cout << " ";
					cout << nv[vt[i]];
				}
				
			}else {
				nc:
				cout << "not complete";
			}

			cout << endl;
			
		}
	
	}
	
	return 0;

}


