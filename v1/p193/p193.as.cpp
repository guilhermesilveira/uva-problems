#include <stdio.h>
#include <vector>

using namespace std;

#define INCOLOR		0
#define BLACK		1
#define	WHITE		2

struct node {
	int id;
	int color;
	vector<node *> filhos;
	int nfilhos;
};

// os nodes cacheados e a lista de estado
int nodeCount;
vector<node> pool;

int maxBlackCount;
bool melhor[100];

void recursao(int i,int blackCount,int whiteCount) {
	
	// se chegou no ultimo no
	if(i==nodeCount) {
		if(blackCount>maxBlackCount) {
			maxBlackCount = blackCount;
			for(int z=0;z!=nodeCount;z++) {
				melhor[z] = (pool[z].color==BLACK);
			}
			//cout << "melhor novo: " << maxBlackCount << endl;
		}
		return;
	}
	
	// se o maximo de numeros faltando
	if((nodeCount-i)+blackCount<=maxBlackCount) {
		// nao adianta todos serem pretos
		return;
	}
	
	if(pool[i].nfilhos==0) {
		pool[i].color = BLACK;
		recursao(i+1,blackCount+1,whiteCount);
		pool[i].color = INCOLOR;
		return;
	}
	
	// tenta com white
	pool[i].color = WHITE;
	recursao(i+1,blackCount,whiteCount+1);
	pool[i].color = INCOLOR;

	// se algum dos filhos for black, nao pode ser black
	for(int z=0;z!=pool[i].nfilhos;z++) {
		if(pool[i].filhos[z]->color==BLACK) return;
	}
	
	pool[i].color = BLACK;
	recursao(i+1,blackCount+1,whiteCount);
	pool[i].color = INCOLOR;
	
}

int main(int argc, char **argv) {
	
	int inst;
	scanf("%d",&inst);

	// cacheia todos os nos	
	for(int i=0;i!=100;i++) {
		node n;
		n.id = i;
		pool.push_back(n);
	}
	
	while(inst--!=0) {

		// limpa todos os nos		
		maxBlackCount = 0;
		long int n;
		int a,b;
		scanf("%d %ld",&nodeCount,&n);
		for(int i=0;i!=nodeCount;i++) {
			pool[i].color = INCOLOR;
			pool[i].filhos.clear();
		}
		
		// le todos as conexoes
		for(int i=0;i!=n;i++) {
			scanf("%d %d", &a, &b);
			pool[a-1].filhos.push_back(&pool[b-1]);
			pool[b-1].filhos.push_back(&pool[a-1]);
			//pool[a-1].filhos.push_back(b-1);
			//pool[b-1].filhos.push_back(a-1);
		}
		
		// seta o numero de conexoes de cada um, e as cores do estado inicial
		for(int i=0;i!=nodeCount;i++) {
			pool[i].nfilhos = pool[i].filhos.size();
		}
		
		recursao(0,0,nodeCount);

		// imprime o resultado
		printf("%d\n",maxBlackCount);
		for(int i=0;i!=nodeCount;i++) {
			if(melhor[i]) {
				if(--maxBlackCount==0) printf("%d",i+1);
				else printf("%d ",i+1);
			}
		}
		printf("\n");
		
	}
	
	return 0;

}

// o primeiro teste tem que retornar 3
// o segundo teste tem que retornar 2
// o terceiro teste retorna 1
// o quarto retorna 6
