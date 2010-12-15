#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define FOR(a,b) for(int a=0;a<b;a++)

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
        while((*st)!='\0') {
            if((*st)>='a' && (*st)<='z') {
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
    long *toLong() {
        long *z = (long *) malloc(sizeof(long) * tot);
        for(int i=0;i!=tot;i++) {
        	if(s[i][0]=='-') z[i] = -atol(s[i]+1);
        	else z[i] = atol(s[i]);
        }
        return z;
    }
};

#include <algorithm>
#include <string>

int cmp(char *s1,char *s2) {
	return strcmp(s1,s2)==0?1:0;
}

void par(char *s) {
	int len = strlen(s);
	if(s[len-2]=='\r' || s[len-2]=='\n') s[len-2]='\0';
	if(s[len-3]=='\r' || s[len-3]=='\n') s[len-3]='\0';
	if(s[len-1]=='\r' || s[len-1]=='\n') s[len-1]='\0';
}

int main() {

	int a,b,jj=0,l;
	char pal[30][30];
	char frase[30][100];
	char pos[30][100];
	char f[1000];
	int p[30];
	StrArray s = StrArray(1000);
	while(gets(f)) {
		sscanf(f,"%d %d",&a,&b);
		if(jj!=0) cout << endl;
		cout << "Excuse Set #" << ++jj << endl;
		FOR(i,a) { gets(pal[i]); par(pal[i]); }
		FOR(i,b) { gets(frase[i]); par(frase[i]); }
		FOR(i,b) {
			p[i] = 0;
			l = strlen(frase[i]);
			strcpy(pos[i],frase[i]);
			FOR(j,l) if(frase[i][j]>='A' && frase[i][j]<='Z') frase[i][j] = frase[i][j]-'A'+'a';
			strcpy(f,frase[i]);
			s.clear();
			s.split(f);
			FOR(j,s.tot) FOR(k,a) p[i] += cmp(pal[k],s.s[j]);
		}
		int maxi = *max_element(&p[0],&p[b]);
		FOR(i,b) if(p[i]==maxi) cout << pos[i] << endl;
	}

}
