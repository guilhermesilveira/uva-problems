#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    void split(char *st, char c = ' ') {
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
        for(int i=0;i!=tot;i++) {
        	if(s[i][0]=='-') z[i] = -atoi(s[i]+1);
        	else z[i] = atoi(s[i]);
        }
        return z;
    }
};


#define FOR(a,b) for(a=0;a<b;a++)


int t[200];
int k,n;
char lin[1000];
StrArray sz = StrArray(1000);

long long val[200][200];
bool con[200][200];

void st() {

	int i,j,l,de,para;
	int *mat;
	gets(lin);
	sz.split(lin);
	FOR(i,n) { t[i] = atoi(sz.s[i]); }
	FOR(i,100) FOR(j,100) val[i][j]=con[i][j]=0;
	FOR(i,n) {
		gets(lin); sz.split(lin);
		mat = sz.toInt();
		FOR(j,sz.tot-1) {
			de = mat[j];
			l = j + 1;
			para = mat[l];
			if(!con[de][para] || val[de][para]<t[i]*(para-de)) {
				val[de][para]=t[i]*(para-de);
				con[de][para]=1;
			}
		}
	}

	cout << "imprime"<<endl;
	FOR(i,10) { FOR(j,10) cout << val[i][j] << " ";cout<<endl; }

	int N = 100;

	// floyid
	FOR(i,N) FOR(j,N) if(i!=j && con[j][i]) FOR(l,N) if(i!=l && j!=l && con[i][l]) {
		if(!con[j][l] || val[j][k]<val[j][i]+val[i][l]) {
			val[j][l]=val[j][i]+val[i][l];
			con[j][l]=1;
		}
	}

	cout << "imprime"<<endl;
	FOR(i,15) { FOR(j,15) cout << val[i][j] << " ";cout<<endl; }

	if(!con[0][k]) cout << "IMPOSSIBLE"<<endl;
	else cout << val[0][k] << endl;
	

}

int main() {

	while((gets(lin))) {
		sscanf(lin,"%d %d",&n,&k);
		cout << n << " " << k << endl;
		st();
	}

}
