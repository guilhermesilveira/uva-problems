#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Word {

public:
	int group;
	long sum;
	string value;
	int size;
	vector<Word *> connections;
	Word *parent;

	bool isSimilar(Word *s2) {
		if(sum - s2->sum > 257 || s2->sum - sum > 257) return false;
		bool hasDiference = false;
		for(int i=0;i!=size;i++) {
			if(value[i]!=s2->value[i]) {
				if(hasDiference) {
					return false;
				} else {
					hasDiference = true;
				}
			}
		}
		return hasDiference;
	}

	void imprime() {
		if(parent != this) {
			parent->imprime();
		}
		cout << value << endl;
	}

};

map<string,Word *> palavras;
vector<Word *> vetores[17];

Word *fromWord;
Word *targetWord;

void limpa(vector<Word *> &lista) {
	// clears and comes back to the generic parent idea during the search
	for(int i=0;i!=lista.size();i++) {
		lista[i]->parent = lista[i];
	}
}

bool solve() {

	vector<Word *> fila;
	vector<Word *> passadoGeral;
	
	fila.push_back(fromWord);
	passadoGeral.push_back(fromWord);
	
	while(fila.size()!=0) {

		Word *w = fila[0];
		fila.erase(fila.begin());

		// gera filhas
		for(int i=0;i!=w->connections.size();i++) {

			// se o fim eh diferente do comeco e ja passou, ignora
			if(find(passadoGeral.begin(),passadoGeral.end(),w->connections[i])!=passadoGeral.end()) {
				continue;
			}

			// se eh aceitavel, continua
			Word *novo = w->connections[i];
			novo->parent = w;

			// se chegou no fim
			if(novo==targetWord) {
				novo->imprime();
				limpa(passadoGeral);
				return true;
			}

			// adiciona a fila
			fila.push_back(novo);
			passadoGeral.push_back(novo);

		}

	}

	limpa(passadoGeral);
	return false;

}

void generateEdges(Word *w, vector<Word *> &v) {


   int size = v.size();
   
   for(vector<Word *>::iterator iter = v.begin(); iter!=v.end(); iter++) {

   	if(w->isSimilar((*iter))) {
	
		// adds to both sides
		w->connections.push_back((*iter));
		(*iter)->connections.push_back(w);
		
		// union para o menor grupo
		if(w->group != (*iter)->group) {
			int g = (*iter)->group;
			// todos com o grupo maior irao ter o codigo do grupo menor
			for(int z=0;z!=size;z++) {
				if(v[z]->group == g) {
					v[z]->group = w->group;
				}
			}
		}
		
	}
	
   }
   
}

void generateEdges(Word *w) {
	generateEdges(w,vetores[w->size]);
}

int main(char **argv,int argc) {

	string t;
	int id = 0;
	while (cin.peek()!='\n') {

		getline(cin,t);
		if(!palavras[t]) {
		
			//cout << t << endl;

			Word *nova = new Word;
			nova->value = t;
			nova->size = t.size();
			nova->group = ++id;
			nova->parent = nova;
			nova->sum = 0;
			
			int repetidas = 0;
			for(int i=0;i != nova->size; i++) {
				nova->sum += (t[i] + 128);
			}

			generateEdges(nova);

			vetores[nova->size].push_back(nova);
			palavras[t] = nova;

		}

	}
	
	int caseCount = 0;
	string from, target;
	while(cin >> from >> target) {

		if(caseCount++!=0) {
			cout << endl;
		}

		if(!palavras[from] || !palavras[target]) {
			cout << "No solution." << endl;
			continue;
		}

		fromWord = palavras[from];
		targetWord = palavras[target];
		
		if(fromWord==targetWord) {
			if(fromWord->connections.size()==0) {
				cout << "No solution." << endl;
			} else {
				cout << fromWord->value << endl;
				cout << fromWord->connections[0]->value << endl;
				cout << fromWord->value << endl;
			}
			continue;
		}

		// o solve da time out!!!
		if(fromWord->group != targetWord->group || !solve()) {
			cout << "No solution." << endl;
		}

	}

	return 0;

}
