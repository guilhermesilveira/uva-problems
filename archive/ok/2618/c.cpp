#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double precos[100010];
int prod[100010];

int lista[200];
double como[200];

void tenta(int l, int tot) {
        for (int i = 0; i != l; i++)
            como[i] = -1;
        int maxi = 0;
        for (int i = 0; i != tot; i++) {
            for (int j = maxi; j > 0; j--) {
                if (lista[j] == prod[i]) { // && como[j - 1] != -1) {
                    // se eh possivel chegar no anterior
                    if (como[j] > como[j - 1] + precos[i] || como[j] == -1) {
                        // se eh mais barato entao marca
                        como[j] = como[j - 1] + precos[i];
                        if(j==maxi && maxi!=tot-1) maxi++;
                    }
                }
            }
            if (lista[0] == prod[i]) {
                if (como[0] == -1 || como[0] > precos[i]) {
                    como[0] = precos[i];
                    if(maxi==0) maxi = 1;
                }
            }
        }
        //cout << "preco mais barato para o " << lista[0] << ": " << como[0] << endl;
        if (como[l - 1] == -1) {
            cout << ("Impossible") << endl;
        } else {
            printf("%.2lf\n",como[l-1]);
        }
}

void start(int l, int tot) {
        for(int i=0;i!=l;i++) cin >> lista[i];
        for (int i = 0; i != tot; i++) {
        	cin >> prod[i] >> precos[i];
        }
        tenta(l, tot);
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
