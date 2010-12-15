#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

#define LIVRE			-1

int maquinas, tarefas, instancia = 1;
int maquinaExecuta[100];
vector<Tarefa *> t;

class Tarefa {

public:

	Tarefa () {
		executada = false;
	}

	bool executada;
	
	double startTime;
	double endTime;
	
	double timeNeeded;
	int maxTime;
	int minTime;

};

bool compara(const Tarefa *t1, const Tarefa *t2) {

	return t1->minTime >= t2->minTime;

}

bool tentaEscalonar(int maquinaLivreTarefaMaxima, double tempoAtual) {

	//cout << "time: " << tempoAtual << endl;

	// PRUNE: VERIFICAR SE TODAS AINDA PODEM SER EXECUTADAS
	int executadas = 0;
	for(int i=0;i!=tarefas;i++) {
		if(executada[i]) {
			executadas++;
			// se estourar, para
			if(vaiTerminarEm[i] > t[i][2]) {
				return false;
			}
		} else {
			if(tempoAtual + t[i][0] > t[i][2]) {
				return false;
			}
		}
	}

	// SE CHEGOU NO FIM!
	if(executadas==tarefas) {
		/*for(int i=0;i!=tarefas;i++) {
			printf("tarefa %d termina em %lf\n", i, vaiTerminarEm[i]);
		}*/
		return true;
	}
	
	//cout << "time-2: " << tempoAtual << endl;

	// para cada maquina
	for(int m = 0; m != maquinas; m++) {

		//cout << tempoAtual << ": maquinaLivreComp[" << m << "]" << endl;

		// se a maquina esta livre
		if(maquinaExecuta[m]==LIVRE) {

			//cout << tempoAtual << ": maquinaLivre[" << m << "]" << endl;

			// tenta executar todas as tarefas possiveis nesse instante
			// verifica o tempo inicial de execucao dela e se ela ainda nao
			// foi executada
			for(int tar = maquinaLivreTarefaMaxima + 1; tar < tarefas; tar++) {
				//cout << tempoAtual << ": maquinaLivre[" << m <<"] tarefa[" << tar << "]: " << !executada[tar] << endl;
				if(!executada[tar]) {
					cout << tempoAtual << ": maquina[" << m << "] tenta tarefa[" << tar << "]" <<  endl;
					// tenta executar ela nesta maquina
					maquinaExecuta[m] = TAREFA(tar);
					executada[tar] = true;
					if(t[tar][1] <= tempoAtual) {
						vaiTerminarEm[tar] = tempoAtual + t[tar][0];
						if(tentaEscalonar(tar,tempoAtual)) {
							return true;
						}
					} else {
						vaiTerminarEm[tar] = t[tar][1] + t[tar][0];
						if(tentaEscalonar(tar,tempoAtual)) {
							return true;
						}
					}
					executada[tar] = false;
					maquinaExecuta[m] = LIVRE;
				}
			}

			/* tentou preencher essa livre com todas as tarefas */
			return false;

		}

	}
	
	//cout << "part 3: " << tempoAtual << " " << executadas << " executadas" << endl;

	double tempoMinimo = 999999999;
	int provavelMaquina = LIVRE;
	int tarefaFinalizada = LIVRE;

	// para cada maquina
	for(int m=0;m!=maquinas;m++) {
		
		int tar = maquinaExecuta[m];
		if(vaiTerminarEm[tar] - tempoAtual < tempoMinimo) {
			provavelMaquina = m;
			tarefaFinalizada = tar;
			tempoMinimo = vaiTerminarEm[tar] - tempoAtual;
		}
		
	}

	tempoAtual = vaiTerminarEm[tarefaFinalizada];

	//cout << "tentado substituir maquina: " << provavelMaquina << "@" << tempoAtual << endl;
	// achamos a tarefa que vai acabar, para cada nova tarefa
	for(int tar = 0; tar != tarefas; tar++) {
		
		if(!executada[tar]) {
			
			//cout << "tentado substituir maquina: " << provavelMaquina << "@" << tempoAtual << endl;
			maquinaExecuta[provavelMaquina] = tar;
			executada[tar] = true;

			if(tempoAtual >= t[tar][1]) {
			
				vaiTerminarEm[tar] = tempoAtual + t[tar][0];
				// se estourar o tempo dessa, ja pode parar
				if(tempoAtual + t[tar][0] > t[tar][2]) {
					executada[tar] = false;
					maquinaExecuta[provavelMaquina] = tarefaFinalizada;
					return false;
				}
				if(tentaEscalonar(maquinaLivreTarefaMaxima,tempoAtual)) {
					return true;
				}
			
			} else {

				vaiTerminarEm[tar] = t[tar][1] + t[tar][0];
				
				// se estourar o tempo dessa, ja pode parar
				if(t[tar][1] + t[tar][0] > t[tar][2]) {
					executada[tar] = false;
					maquinaExecuta[provavelMaquina] = tarefaFinalizada;
					return false;
				}
				
				if(tentaEscalonar(maquinaLivreTarefaMaxima,tempoAtual)) {
					return true;
				}

			}
			
			executada[tar] = false;
			maquinaExecuta[provavelMaquina] = tarefaFinalizada;

		}
	}
	
	return false;

}

int main(int argc, char **argv) {
	
	while(true) {
		
		cin >> maquinas >> tarefas;
		if(maquinas==0 && tarefas==0) break;
		
		if(instancia!=0) cout << endl;
		cout << "Instancia " << instancia++ << endl;
		
		double tempoMinimo = 99999;
		t.clear();

		for(int i=0;i!=tarefas;i++) {
			Tarefa *ts = new Tarefa();
			cin >> ts->timeNeeded >> ts->minTime >> ts->maxTime;
			if(t->minTime < tempoMinimo) {
				tempoMinimo = ts->minTime;
			}
			t.push_back(ts);
		}
		
		if(maquinas==0) {
			cout << "Nao viavel" << endl;
			goto proximo;
		}
		
		for(int m=0;m!=maquinas;m++) {
			maquinaExecuta[m] = LIVRE;
		}

		for(int m=0;m!=tarefas;m++) {
			if(t[m]->minTime + t[m]->timeNeeded > t[m]->maxTime) {
				cout << "Nao viavel" << endl;
				goto proximo;
			}
		}

		if(tentaEscalonar(-1, tempoMinimo)) {
			cout << "Viavel" << endl;
		} else {
			cout << "Nao viavel" << endl;
		}

		proximo:
		maquinas = 0;
		
	}

	return 0;

}
