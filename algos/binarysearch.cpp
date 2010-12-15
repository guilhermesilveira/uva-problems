#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define FOR(a,b) for(a=0;a<b;a++)

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
    void split(char *st, char c=' ') {
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


StrArray ar1 = StrArray(1000);
StrArray ar2 = StrArray(1000);

char l[2][10000];

void st() {

	ar1.split(l[0]);
	ar2.split(l[1]);

	int tot = ar1.tot;
	vector<int> v1;
	int i,j;
	FOR(i,tot) v1.push_back(atoi(ar1.s[i]));
	sort(v1.begin(),v1.end());
	//FOR(i,tot) cout << v1[i] << " "; cout << endl;

	int found = 0;
	bool extra = false;
	int tot2 = ar2.tot;
	FOR(j,tot2) {
		i = atoi(ar2.s[j]);
//		cout << "procurando " << i << endl;
//		cout << binary_search(v1.begin(),v1.end(),i) << endl;
		if(!binary_search(v1.begin(),v1.end(),i)) {
			extra = true;
		} else {
			found++;
		}
	}

	//cout << extra << " " << found  << " " << ar1.tot << " " << ar2.tot<<endl;

	if(extra) {
		if(found==tot) cout << "A is a proper subset of B" << endl;
		else if(found==0) cout << "A and B are disjoint" << endl;
		else cout << "I'm confused!" << endl;
	} else {
		if(found==tot) cout << "A equals B" << endl;
		else if(found<tot) cout << "B is a proper subset of A" << endl;
	}

}

int main() {

	while((gets(l[0]))) {
		gets(l[1]);
		st();
	}
	return 0;

}
