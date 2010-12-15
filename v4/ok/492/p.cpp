#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool isCharacter(char c) {
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

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
    void splitWords(char *st) {
        clear();
        bool b = false;
        char *start = st, c;
        while((*st)!='\0') {
        	c = (*st);
            if(isCharacter(c)) {
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
                if(c!=' ' && c!='\r' && c!='\n') {
    	           	char *h = new char[2];
	               	h[0] = c; h[1] = '\0';
        	       	add(h);
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

bool isVocal(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
		c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int main() {

	char str[10000];
	StrArray ar = StrArray(500);
	char **s;
	int tot,len;
	while((gets(str))) {
		ar.clear();
		ar.splitWords(str);
		s = ar.s;
		tot = ar.tot;
		bool ant = false;
		for(int i=0;i!=tot;i++) {
			if(isCharacter(s[i][0])) {
				if(i!=0 && ant) putchar(' ');
				ant = true;
				if(isVocal(s[i][0])) {
					cout << (s[i]) << "ay";
				} else {
					cout << (s[i]+1) << s[i][0] << "ay";
				}
			} else {
				ant = false;
				cout << s[i];
			}
		}
		cout << endl;
	}
	
	return 0;

}
