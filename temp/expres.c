#include <iostream>
#include <stdio.h>

using namespace std;

#define QUOTE (10000)

class BigNum {
	
	int mag;
	int val[101];
	
	// temp variable
	int i;
	
public:
	BigNum() { init(0); }
	BigNum(int v) { init(v); }
	
	void init(int v) {
		mag = 1;
		val[0] = v;
	}
	
	void copia(BigNum &o) {
		mag = o.mag;
		for(i=0;i!=mag;i++) {
			val[i] = o.val[i];
		}
	}
	
	void soma(BigNum &o) {
	}
	
	void mult(BigNum &o) {
	}
	
	void mult(int n) {
	}
	
	void imprime() {
		if(!mag) cout << 0;
		else {
			for(i=mag-1;i>=0;i--) {
				printf("%0d",val[i]);
			}
		}
	}
	
};

bool done[301][151];
BigNum val[301][151];
BigNum zero;
BigNum um = BigNum(1);

void start(int n,int d) {
	
	if(done[n][d]) return;
	
	int tot;
	BigNum temp;

	// numero impar de parenteses
	if(n%2) {
		val[n][d].copia(zero);
		goto fim;
	}
	
	// nao sobrou parenteses
	if(n==0) {
		if(d!=0) {
			// precisamos de mais levels... nao da
			val[n][d].copia(zero);
		} else {
			// d == 0, ultimo level
			val[n][d].copia(um);
		}
		goto fim;
	}
	
	// level eh 0 mas sobrou varios parenteses
	if(d==0) {
			// nao da... pq vai aprofundar
			val[n][d].copia(zero);
			goto fim;
	}
	
	// level eh 1 mas sobrou varios parenteses
	if(d==1) {
		val[n][d].copia(n%2?zero:um);
		goto fim;
	}
	
	// level eh no minimo 2, sobrou no minimo um parenteses
	
	// se so sobrou um parenteses
	if(n==2) {
		// precisava de no minimo 2, nao da!!!
		val[n][d].copia(zero);
		goto fim;
	}
	
	// se sobrou mais de um parenteses....
	
	// se nao da pra preencher com o numero de parenteses
	if(d*2>n) {
		val[n][d].copia(zero);
		goto fim;
	}
	
	val[n][d].copia(zero);
	
	// total
	tot = n / 2;
	temp = BigNum(1);
	cout << "[" << n << "][" << d << "]=";
	for(int i=1;i!=tot;i++) {
		// coloca (i)*2 parenteses do lado esquerdo e (tot-i)*2 do lado direito
		temp.init(0);
		//start(i*2,d-1);
	//	start((tot-i)*2,d);
		//temp.soma(val[i*2][d-1]);
		//temp.mult(val[(tot-i)*2][d]);
		cout << " ([" << (i*2) << "][" << (d-1) << "]*" << "[" << (tot-i)*2 << "]["<<d<<"])";
		val[n][d].soma(temp);
	}
	cout << endl;

	fim:
	done[n][d] = true;

}

int main() {
	
	for(int i=0;i!=301;i++){
		for(int j=0;j!=151;j++) {
			done[i][j] = false;
		}
	}
	
	start(4,2);
return 0;

	for(int i=0;i<=4;i++) {
		//cout << i << ": ";
		for(int j=0;j<=4;j++) {
			start(i,j);
//			val[i][j].imprime();
			//cout << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	
	return 0;
	
	
	int n,d;
	while((cin >> n >> d)) {
		if(n%2 || d*2>n) {
			cout << 0 << endl;
			continue;
		}
		start(n,d);
		val[n][d].imprime();
		cout << endl;
	}
	
}
