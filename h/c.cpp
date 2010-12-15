#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(a,b) for(a=0;a!=b;a++)

using namespace std;

int main() {
	
	long v[10001][2];
	vector<long> val;
	
	long i,j,k,l,n;
	while((cin >> n >> k)) {
		
		cout << endl << n << k << endl;
		
		val.clear();
		FOR(i,10001) v[i][0]=v[i][1]=0;
		
		FOR(i,n) {
			cin >> j;
			if(j>=0) v[j][0]++;
			else v[0-j][1]++;
//			val.push_back(j);
			val.push_back(j>=0?j:0-j);
		}
		
		sort(val.begin(),val.end());
		
		long som = 0;
		long valor,valor2,valor3;
		for(int i=n-1;i>=0;i--) {
			valor = val[i];
			if(k==1) {
				// verifica se o cara dessa posicao eh positivo
				if(v[valor][0]>0) {
					// adiciona ele
					cout << "soma " << valor << endl;
					som += v[valor][0];
					break;
				} else {
					// ignora ele
					continue;
				}
			} else {
				// tenho que selecionar 2
				valor2 = val[i-1];
				cout << valor << " e " << valor2 << endl;
				if((v[valor][0]>0 && v[valor2][0]>0)) {
					// vale a pena eles dois
					v[valor][0]--;
					v[valor2][0]--; k-= 2;
					som+=valor+valor2;
					i--; continue;
				} else if (v[valor][1]>0 && v[valor2][1]>0) {
					// vale a pena eles dois
					som-=valor;
					som-=valor2;
					v[valor][1]--;
					v[valor2][1]--; k-= 2;
					i--; continue;
				} else {
					cout << "dif" << endl;
					// um eh pos outro eh neg
					if(k==2 && i==1) {
						// se so sobraram esses dois
						if(v[valor][0]>0) {
							som+=valor;
							som-=valor2;
						} else {
							som+=valor2;
							som-=valor;
						}
						break;
					}
					// pega o terceiro anterior
					valor3 = val[i-2];
					if(v[valor3][0]>0) {
						// acha o outro positivo
						v[valor3][0]--;
						som+=valor3;
						if(v[valor][0]>0) {
							som+=valor;
							val[i-2] = valor2;
						} else {
							som+=valor2;
							val[i-2] = valor;
						}
					} else {
						// acha o outro negativo
						som-=valor3;
						v[valor3][1]--;
						if(v[valor][1]>0) {
							som-=valor;
							val[i-2] = valor2;
						} else {
							som-=valor2;
							val[i-2] = valor;
						}
					}
					i--;
					continue;
				}
			}
		}

/*		int st = 0;
		int en = n-1;
		int som=0;
		while(k!=0) {
			// se for para pegar um so, pega o maior positivo
			if(k==1) {
				//cout << "termina com ele: " << val[en] << endl;
				som += val[en--];
				k--;
			} else {
				// pega de dois em dois
				// se os dois negativos multiplicados sao maiores que os dois positivos
				if(val[st]*val[st+1]>val[en]*val[en-1]) {
					// pega os dois do comeco
					som += val[st++] + val[st++];
				} else {
					// pega os dois do fim
					som += val[en--] + val[en--];
				}
				k-=2;
			}
		}*/
		cout << som << endl;
		
	}
	
	return 0;
	
}
