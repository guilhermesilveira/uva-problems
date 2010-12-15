#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void tenta(int m, int l, int b, int *box,long soma) {

	int possivel[m+1];
	for(int i=0;i<=m;i++) possivel[i] = -2;
	possivel[0] = -1;
	
	if(m>=soma) {
		cout << b;
		for(int i=0;i!=b;i++) cout << " " << (i+1);
		cout << endl;
		return;
	} else if(l>=soma) {
		cout << "0 " << endl;
		return;
	}

	//cout << "novo " << m << "," << l  << endl;

	for(int i=0;i!=b;i++) {
		for(int j=m;j>=box[i];j--) {
			if(possivel[j-box[i]]!=-2 && possivel[j]==-2) {
				possivel[j] = i;
			}
		}
	}
	
	for(int i=m;i>0;i--) {
		if(possivel[i]!=-2) {
			if(l < soma - i) {
				cout << "Impossible to distribute" << endl;
				return;
			} else {
				int pilha[b];
				int pc = 0;
				while(i!=0) {
					pilha[pc++] = possivel[i];
					i -= box[possivel[i]];
				}
				//for(i=0;i<=m;i++) cout << i << "=" << possivel[i] << " ";
				//cout << endl;
				cout << pc << " ";
				for(i=pc-1;i>=0;i--) cout <<  (pilha[i]+1) << " ";
				cout<< endl;
				return;
			}
		}
	}
	
	if(l>=soma) {
		cout << b << " 0 ";
		cout << endl;
	} else {
		cout << "Impossible to distribute" << endl;
	}

}

void start(int M, int L) {
	int box; long soma = 0;
	cin >> box;
	int b[box];
        for(int i=0;i!=box;i++) {cin >> b[i]; soma+= b[i];}
        tenta(M, L, box, b,soma);
}

int main () {
    while (true) {
    	int a,b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;
        start(a, b);
    }
    return 0;
}
