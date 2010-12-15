#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int tot;
int t[201];


class StrArray {
public:
    char **s;
    int tot;
    StrArray(int i){
        s = (char **) malloc(sizeof(char *)*i);
        clear();
    }
    void clear() {
        tot = 0;
    }
    void add(char *c) {
        s[tot++] = c;
    }
    void split(char *st, char c) {
        clear();
        bool b = false;
        char *start = st;
        while((*st)!='\0') {
            if((*st)!=c) {
                if(!b) {
                    start = st;
                    b = true;
                }
            } else {
                (*st) = '\0';
                if(b) {
                    b = false;
                    add(start);
                }
            }
            st++;
        }
        if(b) add(start);
    }
    int *toInt() {
        int *z = (int *) malloc(sizeof(int) * tot);
        for(int i=0;i!=tot;i++) z[i] = atoi(s[i]);
        return z;
    }
    long *toLong() {
        long *z = (long *) malloc(sizeof(long) * tot);
        for(int i=0;i!=tot;i++) z[i] = atol(s[i]);
        return z;
    }
};


StrArray val = StrArray(610);
int *v;

#define media (total/n)

int mini = 0, total, wt;

void tenta() {
	int soma = 0;
	int tot = 0, n = 1;
	/*for(int i=1;i!=val.tot;i++) {
		cout << v[i] << " ";
	}
	cout << endl;*/
	for(int i=1;i!=val.tot;i++) {
//		cout << "i: " << i << " soma: " << (soma+v[i]) << "  " << n << endl;
//		cout << (soma+v[i])*(val.tot-1) << " e " << total*n << endl;
		if((soma+v[i])*(val.tot-1) == total*n ) {
			soma = 0; n = 1;
		} else {
			soma += v[i];
			tot++; n++;
		}
	}
	if(mini>tot) mini = tot;
}

int main() {

	char s[651];
	int len, j;
	while(true) {
		cin.getline(s,610,'\n');
		if(s[0]=='#') break;
		val.split(s,' ');
		for(j=0;j!=val.tot;j++) cout << (char) (val.s[j][0]>='a' && val.s[j][0]<='z'?val.s[j][0]-'a'+'A':val.s[j][0]);
		cout << ": ";
		cin.getline(s,610,'\n');
		val.split(s,' ');
		mini = val.tot - 2;
		total = 0;
		v = val.toInt();
		for(int i=1;i!=val.tot;i++) total += v[i];
		//cout << "n" << val.tot << endl;
	//	cout << "total" << total << endl;
		wt = val.tot - 2;
		for(int i=1;i!=val.tot;i++) {
			// tenta
			tenta();
			// gira 1
			for(j=0;j!=val.tot;j++) v[j-1] = v[j];
			v[val.tot-1] = v[0];
		}
		cout << mini << endl;
	}
	return 0;

}
