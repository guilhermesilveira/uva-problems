#include <iostream>
#include <string>
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


int pos[111];
int posfinal;
int preco[111];
long long dp[111][211];
int n;
long long melhor;

bool calc() {

	int i,j,k,lev;
	long long v = 0;
	bool b;

	for(i=0;i<=n;i++) for(j=0;j!=201;j++) dp[i][j] = -1;

	if(pos[0]>100) return false;

	dp[0][100-pos[0]] = 0;

	for(lev=0;lev!=n;lev++) {

		b = false;
		for(i=0;i!=200;i++) {
			if(dp[lev][i]!=-1) {
				b = true;
				v = preco[lev] + dp[lev][i];
				for(j=i+1; j<=200 ; j++, v+=preco[lev]) {
					if(dp[lev][j]==-1 || dp[lev][j]>v)
						dp[lev][j]=v;
				}
			}
		}

		if(lev==n-1) break;
		if(!b) return false;

		k = pos[lev+1] - pos[lev];
		for(i=k;i<=200;i++) {
			if(dp[lev][i]!=-1) {
				dp[lev+1][i-k] = dp[lev][i];
			}
		}

	}

	k = posfinal - pos[n-1] + 100;
	v = -1;
	for(i=k;i<=200;i++) {
		if(dp[n-1][i]!=-1) {
			if(v==-1 || dp[n-1][i]<v) v = dp[n-1][i];
		}
	}
	melhor = v;
	if(v==-1) return false;
	return true;

}

StrArray ar = StrArray(300);

void st() {
	cin >> posfinal;
	n = 0;
	char c[1000];
	int len,i,j,k;
	cin.getline(c,1000);
	while((true)) {
		cin.getline(c,1000);
		len = strlen(c);
		if(c[len-1]=='\n') c[len-1]='\0';
		if(c[len-1]=='\r') c[len-1]='\0';
		ar.clear();
		ar.split(c,' ');
		if(ar.tot==0) break;
		int *iz = ar.toInt();
		pos[n] = iz[0];
		preco[n] = iz[1];
		n++;
	}
	if(calc()) {
		cout << melhor << endl;
	} else {
		cout << "Impossible" << endl;
	}
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		st();
		if(t!=0) cout << endl;
	}
	return 0;

}
