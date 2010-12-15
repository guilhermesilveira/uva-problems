#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void read(string s,vector<int> &p) {

	vector<int> pancakes;
	cout << s << endl;
	while(s.find(" ")!=string::npos) {
		string temp = s.substr(0,s.find(" "));
		s = s.substr(s.find(" ") + 1);
		if(temp=="") continue;
		//cout << temp << "." << endl;
		p.push_back(atoi(temp.c_str()));
		pancakes.push_back(atoi(temp.c_str()));
		//cout << s<<endl;
	}
	while(s[0]==' ') {
		s.erase(s.begin());
	}
	if(s!="") {
		//cout << s << "." << endl;
		pancakes.push_back(atoi(s.c_str()));
		p.push_back(atoi(s.c_str()));
	}
	
	// reverse
	for(int i = pancakes.size() - 1; i >= 0; i--) {
		//p.push_back(pancakes[i]);
	}
	
}

void imprime(vector<int> &pancakes) {
	for(int i=0;i!=pancakes.size();i++) {
		cout << pancakes[i] << " ";
	}
	cout << "..." << endl;
}

void viraPosicao(int i,vector<int> &pancakes,int size) {
	// encontra o meu cara
	//cout << procura << "/" << (posicao) << endl;
	//cout << "movendo todos ate " << i << endl;
	cout << (size-i) << " ";
	vector<int>::iterator atual = pancakes.begin();
	for(int z = 0; z <= i; z++) {
		int temp = pancakes[z];
		pancakes.erase(atual);
		pancakes.insert(pancakes.begin(),temp);
	//	imprime(pancakes);
		atual++;
	}
}

void vira(int procura,vector<int> &pancakes,int size) {
	int i;
	for(i=0;pancakes[i]!=procura;i++);
	if(i!=0) viraPosicao(i,pancakes,size);
}

int main(char **argv,int argc) {

	while(true) {

		string s;
		if(!getline(cin,s)) {
			break;
		}

		vector<int> pancakes;
		read(s,pancakes);

		vector<int> sortedPancakes = vector<int>(pancakes);
		sort(sortedPancakes.begin(),sortedPancakes.end());

		int size = pancakes.size();
		//cout << "sorted pancakes: ";
		//imprime(sortedPancakes);
		
		//cout << "pancakes: ";
		//imprime(pancakes);
		
		if(size==2) {
			if(sortedPancakes[0]==pancakes[0]) {
				cout << "0" << endl;
			} else {
				cout << "1 0" << endl;
			}
			continue;
		}

		for(int atual=size-1; atual > 0; atual--) {
			// se nao for a panqueca correta na posicao correta
			if(pancakes[atual] != sortedPancakes[atual]) {
				//cout << "o " << sortedPancakes[atual] << " nao esta na posicao " << (atual) << endl;
		//		cout << "antes: "; imprime(pancakes);
				vira(sortedPancakes[atual],pancakes,size);
		//		cout << "depois: "; imprime(pancakes);
				viraPosicao(atual,pancakes,size);
		//		cout << "apos 2: "; imprime(pancakes);
			}
		}

		cout << "0" << endl;

	}

	return 0;

}
