#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int totalWords;
int totalLevel;

int minSize;
int maxSize;

int totalSize;

string targetWord;

class palavra {
public:
	string text;
	bool usado;
	int tamanho;
	bool existeOutra;
};

vector<palavra *> mapas;

bool tentaLinha(int level) {

	int t, alvo;

	// se for o ultimo nivel, esta ok
	if(level==totalLevel) {
		return true;
	}
	
	for(int i=0;i!=totalWords;i++) {
		if(!mapas[i]->usado) {
			mapas[i]->usado = true;
			for(int i2=0;i2!=totalWords;i2++) {
				if(!mapas[i2]->usado
					/*&& mapas[i]->tamanho + mapas[i2]->tamanho == totalSize*/
					&& mapas[i]->text+mapas[i2]->text == targetWord ) {
					mapas[i2]->usado = true;
					if(tentaLinha(level+1)) return true;
					mapas[i2]->usado = false;
				}
			}
			mapas[i]->usado = false;
		}
	}

	return false;
	
}

void add(string p) {
	palavra *nova = new palavra;
	nova->text = p;
	nova->tamanho = p.size();
	if(nova->tamanho < minSize) {
		minSize = nova->tamanho;
	}
	if(nova->tamanho > maxSize) {
		maxSize = nova->tamanho;
	}
	totalWords++;
	mapas.push_back(nova);
}

void reset() {

	mapas.clear();
	totalWords = 0;
	minSize = 300;
	maxSize = 0;
	totalSize = 0;

}

int main(char **argv,int argc) {

	int v;
	scanf("%d\n",&v);
	
	string p;

	int min, max;
	palavra *smin, *smax;
	
	while(v--) {
	
		reset();

		while(getline(cin,p)) {
			if(p[0]==0) {
				break;
			}
			add(p);
		}

		totalLevel = totalWords / 2;
		totalSize = minSize + maxSize;
		
		// se for nivel 1, eh facil
		if(totalLevel==1) {
			//assert(false);
			cout << mapas[0]->text << mapas[1]->text << endl;
			goto final;
		}

		// comeca com a primeira linha palavra X
		for(int i=0;i!=totalWords;i++) {
			mapas[i]->usado = true;
			for(int i2=0;i2!=totalWords;i2++) {
				if(i2!=i && mapas[i]->tamanho+mapas[i2]->tamanho==totalSize) {
					mapas[i2]->usado = true;
					targetWord = mapas[i]->text + mapas[i2]->text;
					if(tentaLinha(1)) {
						cout << targetWord << endl;
						goto final;
					}
					mapas[i2]->usado = false;
				}
			}
			mapas[i]->usado = false;
		}

		assert(false);
		final:
		if(v!=0) {
			cout << endl;
		}

	}

	return 0;

}
