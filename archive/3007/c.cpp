#include <iostream>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

bool c(const int *v1,const int *v2) {
	if(v1[0]!=v2[0]) return v1[0] < v2[0];
	return v1[1] < v2[1];
}

void start() {
	
	int n;
	cin >> n;
	priority_queue<int, vector<int> , greater<int> > q;
	vector<int* > vec;
	for(int i=0;i!=n;i++) {
		int *x = new int[2];
		cin >> x[0] >> x[1];
		vec.push_back(x);
	}
	sort(vec.begin(),vec.end(),c);
	int ult = 0;
	int pen = 0;
	for(int i=0;i!=n;i++) {
		int atual = vec[i][0];
		int tempo = vec[i][1];
		// se nao passou tempo, ignora e continua
		if(ult==atual) {
			q.push(tempo);
			continue;
		}
		int disponivel = atual - ult;
		while(disponivel!=0) {
			
			// se nao tem ninguem mais, para
			if(q.empty()) break;
			
			// pega o cara de menor tempo
			int val = q.top();
			q.pop();
			
			if(val>disponivel) {
				// tira o que for possivel dele
				val -= disponivel;
				pen += disponivel * q.size();
				q.push(val);
				break;
			} else if(val==disponivel) {
				// acaba com ele
				pen += disponivel * q.size();
				disponivel = 0;
				break;
			} else {
				// da para matar esse cara
				pen += disponivel * q.size();
				disponivel -= val;
				// continua
			}
		}
		ult = atual;
		// adiciona esse cara no queue
		q.push(tempo);
	}
	while(!q.empty()) {
		int val = q.top();
		q.pop();
		pen += val * q.size();
	}
	cout << n << " " << pen << endl;
	
}

int main() {
	int t;
	cin >> t;
	while(t--) start();
	return 0;
}
