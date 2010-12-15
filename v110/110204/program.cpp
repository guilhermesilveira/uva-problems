#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

int *ENCAIXA_NULL = new int[1];

vector<string> listagens[18][18];
vector<string> codigos;
char mapa[300], inverso[300];
string line;
map<string,set<char> *> distintas;

int calculaDecodificadas(string &s);
string codifica(string &s);
void mostraCodificada();
int calculaDistintas(string &s);
void desfaz(int mudadas[18]);
int *encaixa(string original, string codificada);
bool tenta(string &atual);
bool fim();
bool compara(string &s1,string &s2);

int split(string &s) {
	int inicio = 0;
	int atual = 0;
	//cout << s << ":: ";
	while(s.find(' ',inicio) != string::npos) {
		int tamanho = s.find(' ',inicio)-inicio;
		string nova = s.substr(inicio,tamanho);
		// se for soh espaco
		if(nova!=" " && nova!="") {
			codigos.push_back(nova);
			atual++;
		}
		inicio = s.find(' ',inicio) + 1;
	}
	// se for em branco
	//cout << atual << endl;
	if(s.substr(inicio)!=" " && s.substr(inicio)!="") {
		codigos.push_back(s.substr(inicio));
	}
	return atual;
}

int main(char **args,int argv) {

	int words;
	cin >> words;

	string s;
	getline(cin,s);
	for (int i = 0; i != words; i++) {
		getline(cin,s);
		int totalDistintas = calculaDistintas(s);
		vector<string> l = listagens[s.size()][totalDistintas];
		// nao adiciona repetida
		if (find(l.begin(),l.end(),s)==l.end()) {
			listagens[s.size()][totalDistintas].push_back(s);
			//cout << "dict: " << s << endl;
		}
	}
	
	while (getline(cin,line)) {
	
		for(int i=0;i!=260;i++){
			mapa[i]=0;
			inverso[i]=0;
		}

		codigos.clear();

		// splita em todos
		int size = split(line);

		if (codigos.size() == 0) {
			cout << line << endl;
			continue;
		}
	
		if (!tenta(codigos[0])) {
			for (int i = 0; i < 260; i++) {
				mapa[i] = '*';
			}
			mostraCodificada();
		}

	}

}

string elementoMaior() {
	string maior = codigos[0];
	for(int i=1;i<codigos.size();i++) {
		if(compara(maior,codigos[i])) {
			maior = codigos[i];
		}
	}
	return maior;
}

bool tenta(string &atual) {

	if (calculaDecodificadas(atual) == -1) {
		if (fim()) {
			mostraCodificada();
			return true;
		} else {
			return false;
		}
	}

	int distintas = calculaDistintas(atual);
	vector<string> sugestoes = listagens[atual.size()][distintas];
	// para cada palavra com mesmo tamanho e numero de repeticoes
	for (int i = 0; i < sugestoes.size(); i++) {
		// pega a palavra
		string sugestao = sugestoes[i];
		int *modificadas = encaixa(atual, sugestao);
		if (modificadas[0]!=0) {
			// pega a q tem mais decodificadas
			string pproxima = elementoMaior();
			if (tenta(pproxima)) {
				return true;
			} else {
				desfaz(modificadas);
			}
		}
	}

	return false;

}

bool fim() {

	// para cada palavra
	for (int i = 0; i < codigos.size(); i++) {
	
		string &x = codigos[i];

		string buffer;
		for (int j = 0; j < x.size(); j++) {
			buffer += mapa[x[j]];
		}

		vector<string> *l = &listagens[buffer.size()][calculaDistintas(buffer)];

		if (find(l->begin(),l->end(),buffer)==l->end()) {
			return false;
		}

	}
	return true;

}

// dick -> dick
// pick ->dick
int *encaixa(string original, string codificada) {

	for (int i = 0; i < original.length(); i++) {
		if (mapa[original[i]] != 0) {
			if (mapa[original[i]] != codificada[i]) {
				// mapeamento nao bate
				return ENCAIXA_NULL;
			}
		}
		else {
			if (inverso[codificada[i]] != 0) {
				// mapeamento nao bate
				return ENCAIXA_NULL;
			}
		}
	}

	int *mudadas = new int[18];
	for(int i=0;i!=18;i++) {
		mudadas[i]=0;
	}
	
	int x = 0;
	for (int i = 0; i < original.size(); i++) {
		if (inverso[codificada[i]] != 0 && mapa[original[i]] == 0) {
			desfaz(mudadas);
			return ENCAIXA_NULL;
		}
		if (mapa[original[i]] == 0) {
			mapa[original[i]] = codificada[i];
			inverso[codificada[i]] = 1;
			mudadas[x] = original[i];
			x++;
		}
	}
	
	return mudadas;
	
}

void desfaz(int mudadas[18]) {
	for (int i = 0; mudadas[i]!=0; i++) {
		inverso[mapa[mudadas[i]]] = 0;
		mapa[mudadas[i]] = 0;
	}
}

bool compara(string &s1,string &s2) {
	return calculaDecodificadas(s1) <= calculaDecodificadas(s2);
}

int calculaDistintas(string &s) {

	set<char> *temp = distintas[s];
	if (!temp) {
		temp = new set<char>;
		distintas[s] = temp;
	}

	int totalDistintas = s.size();
	for (int i = 0; i < s.size(); i++) {
		temp->insert(temp->end(),s[i]);
	}

	return temp->size();
	
}


void mostraCodificada() {

	//for(int i=0;i!=codigos.size();i++) {
	string buffer;
	//string x = codigos[i];
	string x = line;
	for (int j = 0; j < x.size(); j++) {
		char c;
		if (x[j] != ' ') {
			c = mapa[x[j]];
		} else {
			c = ' ';
		}
		buffer+=c;
	}
	cout << buffer << endl;
	//cout << buffer << " ";
	//}
	//cout << endl;

}


string codifica(string &s) {
	string nova;
	for (int i = 0; i < s.length(); i++) {
		char c = mapa[s[i]];
		nova += c;
	}
	return nova;
}

// este metodo foi verificado e esta ok
// retorna o numero de caracteres decodificados nessa string
int calculaDecodificadas(string &s) {

	int total = 0;
	
	for (int i = 0; i < s.size(); i++) {
		if (mapa[s[i]] != 0) {
			total++;
		}
	}
	// se decodificou todas, retorna -1
	if (total == s.size()) {
		return -1;
	}
	
	// retorna o numero de decodificadas
	return total;
	
}

