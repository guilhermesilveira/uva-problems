#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>

#define FOR(a,b) for(a=0;a<b;a++)
#define FOR3(a,b,c) for(a=b;a<c;a++)

using namespace std;

class Num {
	#define MAXI (100)
	#define QUOTE (10000)
public:
	int mag;
	int val[MAXI];
	Num(char *s) {
		int len = strlen(s);
		int k = 1;
		int p = 0;
		val[0] = 0;
		for(int i=len-1;i>=0;i--) {
			val[p] += k*(s[i]-'0');
			k *= 10;
			if(k==QUOTE) {
				k = 1;
				p++;
				val[p] = 0;
			}
		}
		mag = p+1;
		if(val[mag-1]==0) mag--;
		correct();
	}
	Num(int i) {
		mag = 1;
		val[0] = i;
		correct();
	}
	void print() {
		if(mag==0) { putchar('0'); return; }
		printf("%d",val[mag-1]);
		for(int i=mag-2;i>=0;i--) printf("%04d",val[i]);
	}
	void add(int i) {
		if(mag==0) mag=1;
		val[0] += i;
		correct();
	}
	void add(const Num &n) {
		int i;
		for(i=mag;i<n.mag;i++) val[i]=0;
		if(mag<n.mag) mag = n.mag;
		for(i=0;i!=mag;i++) val[i]+=n.val[i];
		correct();
	}
	void correct() {
		for(int i=0;i!=mag;i++) {
			if(val[i]>=QUOTE) {
				if(i==mag-1) { mag++; val[i+1] = 0;}
				val[i+1] += (val[i]/QUOTE);
				val[i] %= QUOTE;
			}
		}
		for(int i=mag-1;i>=0;i--) {
			if(val[i]!=0) break;
			mag--;
		}
		for(int i=mag;i<MAXI;i++) val[i]=0;
	}
	void mul(const Num &n) {
		if(n.mag==0 || mag==0) {
			mag = 0;
			return;
		}
		if(n.mag==1 && n.val[0]==1) return;
		int i,j;
		int temp[MAXI];
		int nmag = mag;
		for(i=0;i!=MAXI;i++) temp[i] = 0;
		for(i=0;i!=n.mag;i++) {
			for(j=0;j!=mag;j++) {
				temp[j+i] += val[j] * n.val[i];
				if(nmag<=j+i) nmag = j + i + 1;
				if(temp[j+i]>=QUOTE) {
					if(nmag<=j+i+1) nmag = j + i + 2;
					temp[j+i+1] += (temp[j+i]/QUOTE);
					temp[j+i] %= QUOTE;
				}
			}
		}
		mag = nmag;
		for(i=0;i!=mag;i++) val[i] = temp[i];
		correct();
	}
	// multiplies by a positive integer
	void mult(int v) {
		for(int i=0;i!=mag;i++) val[i] *= v;
		correct();
	}
	void div(int v) {
		for(int i=mag-1;i>=0;i--) {
			if(val[i]%v!=0 && i!=0) val[i-1] += (val[i]%v)*QUOTE;
			val[i] /= v;
		}
		correct();
	}
	Num(const Num &n) {
		copy(n);
	}
	void copy(const Num &n) {
		mag = n.mag;
		for(int i=0;i!=MAXI;i++) val[i] = n.val[i];
		correct();
	}
	bool eq(const Num &n) {
		if(n.mag!=mag) return false;
		for(int i=0;i!=mag;i++) if(n.val[i]!=val[i]) return false;
		return true;
	}
	int cmp(const Num &n) {
		if(mag!=n.mag) return mag-n.mag;
		for(int i=mag-1;i>=0;i--) if(val[i]!=n.val[i]) return val[i]-n.val[i];
		return 0;
	}
	// subtracts a smaller number
	void sub(const Num &n) {
		for(int i=n.mag-1;i>=0;i--) {
			val[i] -= n.val[i];
			while(val[i]<0) {
				val[i+1]--;
				val[i]+=QUOTE;
			}
		}
		correct();
	}
	void resto(Num &n,Num *r) {
	
	}

};

char s1[100],s2[10],s3[100];
char v1[100],v2[100];

Num zero = Num(0);

Num *gcd(Num *a,Num *b){
{
    Num r;

    while(!b.eq(zero)){
		a.resto(b,&r);
    	a = b;
    	b = r;
    }

    return(a);
}



void st() {
	cin >> s1 >> s2 >> s3;
	Num n1 = Num(s1), n2 = Num(s3);
	Num n3 = gcd(Num(s1),Num(s2));
	n1.div(n3);
	n2.div(n3);
	n1.print(); cout << " / "; n2.print; cout << endl;
	
	
}

int main() {

	int t; cin >> t;
	while(t--)st();
return 0;
}
