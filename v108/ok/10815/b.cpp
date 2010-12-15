#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>

#define FOR(a,b) for(a=0;a<b;a++)
#define FOR3(a,b,c) for(a=b;a<c;a++)

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
    void split(char *st) {
        clear();
        bool b = false;
        char *start = st;
        char cz;
        while((*st)!='\0') {
        	cz=*st;
            if((cz>='a' && cz<='z') || (cz>='A' && cz<='Z')) {
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


char dic[5001][201];
char linha[201];
StrArray l = StrArray(201);

int comp(const void *s1, const void *s2) {
	char *c1 = (char*)s1;
	char *c2 = (char*)s2;
	return strcmp(c1,c2);
}

int main() {

	int dn = 0;
	int i,j,k;
	char *z;
	while(gets(linha)) {
		l.clear();
		l.split(linha);
		FOR(i,l.tot) {
			z = l.s[i];
			j=strlen(z);
			for(k=0;k!=j;k++) if(z[k]>='A' && z[k]<='Z') z[k] = z[k] - 'A' + 'a';
			FOR(j,dn) if(strcmp(dic[j],z)==0) goto nex;
			strcpy(dic[dn++],z);
			//cout << "nova: " << z << " " << dic[dn-1] << endl;
			nex:;
		}
	}
	qsort(dic,dn,sizeof(dic[0]),comp);
	FOR(i,dn) cout << dic[i] << endl;
	return 0;

}
