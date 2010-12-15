#include <iostream>

// DIVIDE AND CONQUER?

// NAO CALCULAR TODAS E SIM FAZER UMA COMBINATORIA:
// NUMERO DE PESSOAS	NUMERO DE FRENTE	NUMERO DE TRAS	COMBINACOES
// 2			2			1		1
// 2			1			2		1
// 1			1			1		1
// 3			3			1		1
// 3			1			1, 2 ou 3	1
// 3			2			2		2

// para cada grupo, por exemplo de 4, divido em 2 grupos
// se o numero de frente era 4 e tras era 3


using namespace std;

unsigned long long casos;

int n;
int frente;
int tras;

int pessoas[13];
bool jaColocou[13];

long long paraValores(int n,int frente,int tras) {
	if(n==1) {
		return frente==1 && tras==1 ? 1 : 0;
	}
	if(n==2) {
		if(frente==2 && tras==1) {
			return 1;
		}
		return frente==1 && tras==2 ? 1 : 0;
	}
	if(n==3) {
		if(frente==3 && tras==1) {
			return 1;
		}
		if(frente==1 && (tras>0 && tras<4)) {
			return 1;
		}
		if(frente==2 && tras==2) {
			return 2;
		}
	}
	return 0;
}

void imprimeSequencia(int n) {
	for(int i=0;i!=n;i++) {
		cout << pessoas[i] << " ";
	}
	cout << endl;
}

void proximoNivel(int atual,int frenteAtual,int trasAtual, int maior) {

	//cout << atual << "/" << n << endl;
	
	// calcula quantos tem olhando de tras
	
	// se for impossivel alcancar o limite
	/*if(frenteAtual + n - atual<frente) {
		return;
	}*/


	if(atual==n) {
		if(frenteAtual==frente) {
			//imprimeSequencia(atual);
			// se o resultado bateu, ok
			//cout << "end: " << frenteAtual << " e " << novoTotal << endl;
			if(trasAtual==tras) {
				casos++;
				/*if(casos % 10000==0) {
					imprimeSequencia(atual);
					cout << "C: " << casos << endl;
				}*/
				//cout << "end (anterior valido)" << endl;
			} /*else {
				//cout << "end (anterior nao valido)" << frente << endl;
			}*/
		} /*else {
			cout << "useless " << frenteAtual << " - ";
			imprimeSequencia(atual);
		}*/
		return;
	}
	
	for(int i=0;i!=n;i++) {
		// para cada pessoa	
		if(!jaColocou[i]) {
			// coloca essa pessoa nessa posicao, se ainda nao esta colocada
			jaColocou[i] = true;
			//cout << "coloca em " << (atual-1) << " o valor " << i << endl;
			pessoas[atual] = i;
			if(i>maior) {
				// se for maior que o maior
				// se estourou, para
				if(frenteAtual==frente) {
					// purge
					goto proximo;
				}
				// se somado com n-maior for menor que o valor objetivo, cancela
				if(n - i + frenteAtual<frente) {
					/*imprimeSequencia(atual+1);
					cout << "n " << n << endl;
					cout << "maior " << i << endl;
					cout << "frenteAtual " << frenteAtual << endl;*/
					goto proximo;
				}
				proximoNivel(atual+1,frenteAtual+1,1,i);
			} else {
				// se for menor que o maior
				if(i<pessoas[atual-1]) {
					// se for menor que o anterior, trasAtual+1
					proximoNivel(atual+1,frenteAtual,trasAtual+1,maior);
				} else {
					// se ficar no meio, recalcula
					int maiorInverso = -1;
					trasAtual = 0;
					for(int i=atual-1;i!=-1;i--) {
						//cout << "i: " << i << " e " << pessoas[atual] << "," << minimo << endl;
						if(pessoas[i]>maiorInverso) {
							//cout << "+1 " << minimo << endl;
							maiorInverso = pessoas[i];
							trasAtual++;
							if(trasAtual>tras) {
								// se explodir, para
								goto proximo;
							}
						}
					}
					proximoNivel(atual+1,frenteAtual,trasAtual,maior);
				}
			}
			proximo:
			// retira a pessoa
			jaColocou[i] = false;
		}
	}

}

int main(char **argv,int argc) {

	int count;
	cin >> count;
	
	while(count-->0) {
	
		casos = 0;
		
		cin >> n >> frente >> tras;
		
		/*if(n<=3 && n>=1) {
		
			casos = paraValores(n,frente,tras);
		
		} else {*/
		
			for(int i=0;i!=n;i++) {
				pessoas[i] = 0;
				jaColocou[i] = false;
			}

			proximoNivel(0,0,0,-1);
			
		//}
		
		cout << casos << endl;
		
	}

	return 0;

}
