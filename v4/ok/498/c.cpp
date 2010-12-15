#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char c[10000];
char x[10000];

class StrArray {
public:
    char **s;
    int tot;
    StrArray(int i){
        s = (char **) malloc(sizeof(char *)*i);
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

int main() {

    StrArray pol = StrArray(1000);
    StrArray v = StrArray(1000);
    int *pi, *vi, i, j;
    long long k, f;
    
    while((cin.getline(c,10000,'\n'))) {
        cin.getline(x,10000,'\n');
        pol.split(c,' ');
        v.split(x,' ');
        pi = pol.toInt();
        vi = v.toInt();
        for(i=0;i!=v.tot;i++) {
            k = 1;
            f = 0;
            for(j=pol.tot-1;j>=0;j--) {
                f += pi[j] * k;
                k *= vi[i];
            }
            cout << f;
            if(i!=v.tot-1) cout << " ";
        }
        cout << endl;
    }

    return 0;

}
