#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define FOR(a,b) for(a=0;a<b;a++)
#define DEBUG(a) 

using namespace std;

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
};
// readers
StrArray linha = StrArray(100);
char l[1000];

// subjects, teachers, new guys
int s,m,n;

// maximum value and minimum values
#define MVAL (3*3*3*3*3*3*3*3*3)
long mval = MVAL;
long val[MVAL+100];
bool filled[MVAL+100];

int r[10];

int caminho[10];
int caminho2[10];
int lend;

// builds a path into "caminho" with the current id (v)
void caminhoDe(int v) {
	int p = s;
	for(int i=0;i!=s;i++) caminho[i]=0;
	while(v) {
		p--;
		caminho[p] = v % 3;
		v /= 3;
	}
}

// gets the id for the path pointed from "v"
int posicao(int *v) {
	int p=0;
	for(int i=0;i!=s;i++) {
		p*=3; p+=v[i];
	}
	return p;
}

void imp(int *v) {
	for(int i=0;i!=s;i++) cout << v[i] << " "; cout << endl;
}


void add(int start,long cost) {

	int i,j;

	// start=0.... could be =minimum, would be faster???
	for(i=lend+1;i>=start;i--) {
		if(filled[i]) {
			DEBUG(cout << "try " << i << " " << cost << endl;)
			caminhoDe(i);
			DEBUG(cout << "caminho: "; imp(caminho);)
			// decides the new place
			for(j=0;j<s;j++) caminho2[j]=min(caminho[j]+r[j],2);
			int p = posicao(caminho2);
			DEBUG(cout << "nova posicao: " << p << endl;)
			if(!filled[p] || val[p]>val[i] + cost) {
				val[p]=val[i] + cost;
				filled[p]=1;
			}
		}
	}

}

long best() {
	int i;
	FOR(i,s) caminho2[i]=2;
	return val[posicao(caminho2)];
}

void st() {

	int i,j,k;

	FOR(i,s) caminho2[i]=2;
	lend=posicao(caminho2);

	// impossible to get anywhere
	FOR(i,mval) val[i]=filled[i]=0;

	// current teachers
	long inicio = 0;

	// how many teachers are already available for each subject
	int ja[10];
	FOR(i,10) ja[i]=0;
	FOR(i,m) {
		gets(l);
		linha.split(l,' ');
		// sum up its value to current teachers
		inicio += atol(linha.s[0]);
		for(j=1;j<linha.tot;j++) {
			int kz = atoi(linha.s[j])-1;
			// we need maximum 2 teachers!
			ja[kz] = min(ja[kz] + 1, 2);
		}
	}

	// marks its position as with this value
	val[posicao(ja)]=inicio;

	// inicial
	//cout << "initial: " << inicio << endl;
	filled[posicao(ja)]=1;

	int start = 0;
	FOR(i,n) {
		gets(l);
		linha.split(l,' ');
		long custo = atol(linha.s[0]);
		DEBUG(cout << "user " << i << " " << custo << endl;)
		FOR(j,s) r[j]=0;
		for(j=1;j<linha.tot;j++) {
			int kz = atoi(linha.s[j]) - 1;
			r[kz] = 1;
		}
		DEBUG(imp(r);)
		add(start,custo);
	}

	cout << best() << endl;
	DEBUG(i = posicao(caminho2);FOR(j,i) cout << val[i] << " "; cout << endl;)

}

// starting point
int main() {
	while(true) {
		gets(l);
		sscanf(l,"%d %d %d",&s,&m,&n);
		if(!s) break;
		st();
	}
	return 0;
}
