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

int n;


int main() {

	int i;
	char st[25][100];
	StrArray *ar[25];
	for(i=0;i!=25;i++) ar[i] = new StrArray(100);
       while(scanf("START %d",&n)==1) {
		scanf(" ");
//		cout << n << endl;
		for(i=0;i!=n;i++) {
	               gets(st[i]);
			ar[i]->clear();
			ar[i]->split(st[i],' ');
		}
		long long val,mini = -1;
		cin >> val;
		scanf(" ");
		for(i=0;i!=n;i++) {
			int *v = ar[i]->toInt();
			int tot = ar[i]->tot;
			int k = 0;
			unsigned long long t = 0;
			while(t<val) {
				t += v[k++];
				if(k==tot) k = 0;
			}
			if(mini==-1 || mini > t) mini = t;
		}
		cout << (mini-val) << endl;
               gets(st[0]);
		scanf(" ");
       }

}
