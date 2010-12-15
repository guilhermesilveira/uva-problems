#include <iostream>
#include <stdio.h>
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
        for(int i=0;i!=tot;i++) {
        	if(s[i][0]=='-') z[i] = - atoi(s[i]+1);
        	else z[i] = atoi(s[i]);
        }
        return z;
    }
    long *toLong() {
        long *z = (long *) malloc(sizeof(long) * tot);
        for(int i=0;i!=tot;i++) {
        	if(s[i][0]=='-') z[i] = - atol(s[i]+1);
        	else z[i] = atol(s[i]);
        }
        return z;
    }
};

int main() {
	
	int k;
	char str[1000000];
	StrArray ar = StrArray(10011);
	while((cin >> k)) {
		scanf(" ");
		gets(str);
		ar.clear();
		ar.split(str,' ');
		int tot = ar.tot;
		long *v = ar.toLong();
		cout << "q(x):";
		if(tot==1) {
			cout << " 0";
		} else {
			for(int i=0;i<tot-1;i++) {
				cout << " " << v[i];
				int val = k * v[i];
				v[i+1] += val;
			}
		}
		cout << endl << "r = " << v[tot-1] << endl << endl;
	}
	return 0;
	
}
