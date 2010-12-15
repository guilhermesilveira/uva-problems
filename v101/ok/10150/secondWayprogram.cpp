#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Group;

class Word {

public:
	Group *group;
	string value;
	int size;
	int sum;
	int hash;
	vector<Word *> connections;
	Word *parent;

	void imprime() {
		if(parent != this) {
			parent->imprime();
		}
		cout << value << endl;
	}

};

class Group {
public:
	int id;
	vector<Word *> children;
};

map<string,Word *> palavras[16000];
map<int,Group *> groups;

Word *fromWord;
Word *targetWord;

void limpa(vector<Word *> &lista) {
	// clears and comes back to the generic parent idea during the search
	for(int i=0;i!=lista.size();i++) {
		lista[i]->parent = lista[i];
	}
}

int hash(string &s) {
	int sum = 0;
	//for(int i=0;i!=s.size();i++) {
	//	sum = sum * 31 + s[i];
	//}
	//return (sum<0 ? (0 - sum) : sum) % 8000;
	return (s[0] * 31 * 31 + s[1] * 31 + s[2]) % 8000;
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

/*int pow(int value,int level) {
	while(level!=1) {
		value *= level--;
	}
	return value;
}*/

void generateEdges(Word *w) {

   char c;
//   cout << "sum: " << sum << endl;
   for(int i=0;i!=w->size;i++) {
   	char oldChar = w->value[i];
   	// tenta todas nesse lugar
	for(c = 'a'; c <= 'z'; c++) {
		w->value[i] = c;
		// se ja existe, conecta
		int h = hash(w->value);
		palavras[h];
		if(palavras[h][w->value]) {

		/*	// adds to both sides
			Word *other = palavras[hash(w->value)][w->value];
			//cout << "conectando " << other->value << endl;
			w->connections.push_back(other);
			other->connections.push_back(w);

			if(other->group!=w->group) {
				// union para o novo grupo
				Group *g = other->group;
				// todos com o grupo maior irao ter o codigo do grupo menor
				while(!g->children.empty()) {
					Word *nw = g->children[0];
					g->children.erase(g->children.begin());
					w->group->children.push_back(nw);
					nw->group = w->group;
				}
			}*/

		}
	}
	w->value[i] = oldChar;
   }
//   cout << "fim sum: " << sum << endl;
   
}

int calcSum(string t) {
	int sum = 0;
	for(int i=0;i!=t.size();i++) {
		sum = sum * 31 + t[i];
	}
	return sum;
}

int main(char **argv,int argc) {

	/*for(char c='a';c!='z';c++) {
	for(char c2='a';c2!='k';c2++) {
	for(char c3='a';c3!='k';c3++) {
	for(char c4='a';c4!='k';c4++) {
	for(char c5='a';c5!='k';c5++) {
	cout << c << c2 << c3 << c4 << c5 << endl;
	}
	}
	}
	}
	}
	
	cout << "adhsa ekhsx" << endl;*/
	
//	return 0;

	string t;
	int id = 0;
	int hashCode;
	while (cin.peek()!='\n') {

		getline(cin,t);
		hashCode = hash(t);
		if(!palavras[hashCode][t]) {

			Word *nova = new Word;
			nova->value = t;
			nova->size = t.size();
			nova->group = new Group;
			nova->group->id = ++id;
			nova->parent = nova;
//			nova->sum = calcSum(t);
			nova->hash = hashCode;
			
			nova->group->children.push_back(nova);
			groups[id] = nova->group;

			generateEdges(nova);

			palavras[hashCode][t] = nova;

		}

	}
	
	cout << "comecando" << endl;
	
	for(int i=0;i<=3500;i+=2) {
		cout << "hash " << i << ": " << palavras[i].size() << " " << palavras[i+1].size() << endl;
	}
	
	int caseCount = 0;
	string from, target;
	int fromSum, targetSum;
	while(cin >> from >> target) {

		if(caseCount++!=0) {
			cout << endl;
		}

		int fromHash = hash(from);
		int targetHash = hash(target);

		cout << "procurando: " << fromHash << " e " << targetHash << endl;

		if(!palavras[fromHash][from] || !palavras[targetHash][target]) {
			cout << "nao existe No solution." << endl;
			continue;
		}

		fromWord = palavras[fromHash][from];
		targetWord = palavras[targetHash][target];

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
		
		cout << "from: " << fromWord->group->id << " e " << targetWord->group->id << endl;

		if(!solve()) {
//		if(fromWord->group->id != targetWord->group->id  || !solve()) {
			cout << "No solution." << endl;
		}

	}

	return 0;

}
