#include <iostream>
#include <string>
#include <math.h>
#include <iterator>
#include <vector>
#include <algorithm>


// TODO transformar para BACKTRACKING
// TODO passar de passou por atraves de NEGOCIO PELO OBJETO INTEIRO COM UM A FUNCIAO QUE CHECA O NIVEL!

using namespace std;

class Estado {
public:
	int mapa[4][4];
	int posicoes[16][2];
	int moves;
	int pontos;
	string code;
	char codes[51];
	// quanto menos pontos melhor!!!
	void calculaPontos() {
		pontos = 0;
		/*for(int i=0;i!=4;i++) {
			for(int i2=0;i2!=4;i2++) {
				int p = abs(mapa[i][i2]/4 - i) + abs(mapa[i][i2]%4 - i2);
				if(p>pontos) {
					pontos = p;
				}
			}
		}*/
		if(posicoes[0][0]!=0 || posicoes[0][1]!=0) {
			pontos = 6 - posicoes[0][0] - posicoes[0][1];
		} else if(posicoes[1][0]!=0 || posicoes[1][1]!=0) {
			pontos = posicoes[1][0] + posicoes[1][1];
		} else if(posicoes[2][0]!=0 || posicoes[2][1]!=0) {
		} else if(posicoes[3][0]!=0 || posicoes[3][1]!=0) {
		} else if(posicoes[4][0]!=0 || posicoes[4][1]!=0) {
		} else if(posicoes[5][0]!=0 || posicoes[5][1]!=0) {
			pontos = posicoes[5][1]>0?posicoes[5][1]- 1 : 1;
		} else if(posicoes[6][0]!=0 || posicoes[6][1]!=0) {
			pontos = posicoes[6][1]>0?posicoes[6][1]- 1 : 1;
		} else if(posicoes[7][0]!=0 || posicoes[7][1]!=0) {
			pontos = posicoes[7][1]>0?posicoes[7][1]- 1 : 1;
		} else if(posicoes[8][0]!=0 || posicoes[8][1]!=0) {
			pontos = posicoes[8][1]>0?posicoes[8][1]- 1 : 1;
		} else if(posicoes[9][0]!=0 || posicoes[9][1]!=0) {
			pontos = posicoes[9][1]>1?posicoes[9][1]- 2 : posicoes[9][1];
		} else if(posicoes[10][0]!=0 || posicoes[10][1]!=0) {
			pontos = posicoes[10][1]>1?posicoes[10][1]- 2 : posicoes[10][1];
		} else if(posicoes[11][0]!=0 || posicoes[11][1]!=0) {
			pontos = posicoes[11][1]>1?posicoes[11][1]- 2 : posicoes[11][1];
		} else if(posicoes[12][0]!=0 || posicoes[12][1]!=0) {
			pontos = posicoes[12][1]>1?posicoes[12][1]- 2 : posicoes[12][1];
		} else if(posicoes[13][0]!=0 || posicoes[13][1]!=0) {
		} else if(posicoes[14][0]!=0 || posicoes[14][1]!=0) {
		} else if(posicoes[15][0]!=0 || posicoes[15][1]!=0) {
		}
		//pontos = 6 - emptyY + emptyX;
		pontos += moves;
		calculaCode();
	}
	void imprime() {
		cout << "nivel " << moves << " " << pontos << endl;
		for(int i=0;i!=4;i++) {
			for(int i2=0;i2!=4;i2++) {
				cout << mapa[i][i2] << " ";
			}
			cout << endl;
		}
		cout << "----------------" << endl;
	}
	bool valido() {
		// verifica se eh valido
		int n = 0;
		for(int i=2;i!=16;i++) {
			int tn = 0;
			// pega a posicao do dito cujo
			int p = posicoes[i][1] * 4 + posicoes[i][0];
			for(int i2=1;i2<i;i2++) {
				// se a posicao do anterior for menor
				if(posicoes[i2][1] * 4 + posicoes[i2][0]>p) {
					tn++;
				}
			}
			//cout << i<< ": " << tn << "\t";
			n+=tn;
		}
		//cout << n << endl;
		return n%2==0;
	}
	void calculaCode() {
		code = "";
		for(int i=0;i!=4;i++) {
			for(int i2=0;i2!=4;i2++) {
				if(mapa[i][i2]>9) {
					code.push_back(' ');
					code.push_back('1');
					char c = (mapa[i][i2] - 10) + '0';
					code.push_back(c);
					code.push_back(' ');
				} else if(mapa[i][i2]==0) {
					code+=" 0 ";
				} else {
					code.push_back(' ');
					code.push_back((mapa[i][i2]) + '0');
					code.push_back(' ');
				}
			}
		}
	}

};

// posicoes passadas
vector<string> passado;

Estado *readData();
bool solve(Estado *atual);
bool finish(Estado *estado);
void troca(Estado *e, int x, int y);
Estado *filho(Estado *estado);

int main(char **argv,int argc) {

	int count;
	cin >> count;
	
	while(count--) {
	
		// le os dados desse nivel
		Estado *inicial = readData();
		Estado *temp = inicial;
		while(temp->posicoes[0][1]!=3) {
			temp = filho(temp);
			troca(temp,0,1);
		}
		//cout << "y: " << temp->posicoes[0][1] << endl;
		while(temp->posicoes[0][0]!=3) {
			temp = filho(temp);
			troca(temp,1,0);
		}
		//cout << "x: " << temp->posicoes[0][0] << endl;
		// temp->imprime();
		if(!temp->valido()) {
			cout << "This puzzle is not solvable." << endl;
			continue;
		}
		inicial->calculaPontos();
		if(finish(inicial)) {
			cout << endl;
			continue;
		}
		passado.clear();
		if(!solve(inicial)) {
			// invalido
			cout << "This puzzle is not solvable." << endl;
		}
	
	}

	return 0;

}

Estado *filho(Estado *estado) {
	Estado *e = new Estado;
	for(int i=0;i!=4;i++) {
		for(int i2=0;i2!=4;i2++) {
			e->mapa[i][i2] = estado->mapa[i][i2];
		}
	}
	for(int i=0;i!=16;i++) {
		e->posicoes[i][0] = estado->posicoes[i][0];
		e->posicoes[i][1] = estado->posicoes[i][1];
	}
	e->moves = estado->moves + 1;
	for(int i=0;i!=estado->moves;i++) {
		e->codes[i] = estado->codes[i];
	}
	e->code = estado->code;
	return e;
}

void troca(Estado *e, int x, int y) {
	int temp = e->mapa[e->posicoes[0][1]+y][e->posicoes[0][0]+x];
	e->mapa[e->posicoes[0][1]][e->posicoes[0][0]] = e->mapa[e->posicoes[0][1]+y][e->posicoes[0][0]+x];
	e->mapa[e->posicoes[0][1]+y][e->posicoes[0][0]+x] = 0;
	e->posicoes[temp][0] -= x;
	e->posicoes[temp][1] -= y;
	e->posicoes[0][0] += x;
	e->posicoes[0][1] += y;
}

int lastLevel = 0;

bool jaPassou(string &code) {
	return find(passado.begin(),passado.end(),code)!=passado.end();
}

void geraFilhos(Estado *estado, vector<Estado *> &filhos) {

	//string s = estado->calculaCode();

	// para cima
	if(estado->posicoes[0][1]!=0) {
		Estado *e = filho(estado);
		troca(e,0,-1);
		e->calculaPontos();
		// se os pontos > 50, ignora
		if(e->pontos<=50 && find(passado.begin(),passado.end(),e->code)==passado.end()) {
			e->codes[e->moves-1]='U';
			filhos.push_back(e);
		}
	}

	// para baixo
	if(estado->posicoes[0][1]!=3) {
		Estado *e = filho(estado);
		troca(e,0,1);
		e->calculaPontos();
		// se os pontos > 50, ignora
		if(e->pontos<=50 && find(passado.begin(),passado.end(),e->code)==passado.end()) {
			e->codes[e->moves-1]='D';
			filhos.push_back(e);
		}
	}

	// para a esquerda
	if(estado->posicoes[0][0]!=0) {
		Estado *e = filho(estado);
		troca(e,-1,0);
		e->calculaPontos();
		// se os pontos > 50, ignora
		if(e->pontos<=50 && find(passado.begin(),passado.end(),e->code)==passado.end()) {
			e->codes[e->moves-1]='L';
			filhos.push_back(e);
		}
	}

	// para a direita
	if(estado->posicoes[0][0]!=3) {
		Estado *e = filho(estado);
		troca(e,1,0);
		e->calculaPontos();
		// se os pontos > 50, ignora
		if(e->pontos<=50 && find(passado.begin(),passado.end(),e->code)==passado.end()) {
			e->codes[e->moves-1]='R';
			filhos.push_back(e);
		}
	}

}

bool finish(Estado *estado) {

	if(estado->mapa[0][0]==1 && estado->mapa[0][1]==2 && estado->mapa[0][2]==3 && estado->mapa[0][3]==4 && 
	   estado->mapa[1][0]==5 && estado->mapa[1][1]==6 && estado->mapa[1][2]==7 && estado->mapa[1][3]==8 && 
	   estado->mapa[2][0]==9 && estado->mapa[2][1]==10 && estado->mapa[2][2]==11 && estado->mapa[2][3]==12 && 
	   estado->mapa[3][0]==13 && estado->mapa[3][1]==14 && estado->mapa[3][2]==15 && estado->mapa[3][3]==0) {
	   cout << estado->codes << endl;
	   return true;
	}

	return false;

}

bool sortFunction(Estado *e1,Estado *e2) {
	return e1->pontos<e2->pontos;
}

bool solve(Estado *inicial) {

	lastLevel = 0;

	// adiciona a situacao inicial
	vector<Estado *> toGo;
	toGo.push_back(inicial);
	inicial->calculaCode();
	passado.push_back(inicial->code);
	vector<Estado *> filhos;
	
	int counter = 0;

	while(toGo.size()!=0) {

		// pega o primeiro da lista (busca em largura)
		Estado *atual = toGo.front();
		toGo.erase(toGo.begin());

		// se mudou de nivel agora
		/*if(atual->moves>lastLevel) {
			lastLevel++;
			atual->imprime();
		}*/

		// se estourou, retorna falso, ignora
		if(atual->moves>=50) {
			continue;
		}

		// se nao, gera filhos
		geraFilhos(atual,filhos);
		for(int i=0;i!=filhos.size();i++) {
			// imprime o filho
			if(finish(filhos[i])) {
				return true;
			} else {
				// adicionando
				//filhos[i]->imprime();
				/*if(filhos[i]->posicoes[0][0]==3 && filhos[i]->posicoes[0][1]==3) {
					if(!filhos[i]->valido()) {
						return false;
					}
				}*/
				toGo.push_back(filhos[i]);
				passado.push_back(filhos[i]->code);
			}
		}
		filhos.clear();
		
		if(counter++==200) {
			sort(toGo.begin(),toGo.end(),sortFunction);
		}

	}
	
	return false;

}

Estado *readData() {
	Estado *atual = new Estado;
	cin >> atual->mapa[0][0] >> atual->mapa[0][1] >> atual->mapa[0][2] >> atual->mapa[0][3];
	cin >> atual->mapa[1][0] >> atual->mapa[1][1] >> atual->mapa[1][2] >> atual->mapa[1][3];
	cin >> atual->mapa[2][0] >> atual->mapa[2][1] >> atual->mapa[2][2] >> atual->mapa[2][3];
	cin >> atual->mapa[3][0] >> atual->mapa[3][1] >> atual->mapa[3][2] >> atual->mapa[3][3];
	atual->moves = 0;
	for(int i=0;i!=4;i++) {
		for(int i2=0;i2!=4;i2++) {
			atual->posicoes[atual->mapa[i][i2]][0] = i2;
			atual->posicoes[atual->mapa[i][i2]][1] = i;
		}
	}
	return atual;
}
