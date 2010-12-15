#include <stdio.h>
#include <math.h>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAXI (30010)
#define TIPOS (11)

using namespace std;

void preenche(char *c,int nl, char nchar) {
	int len = strlen(c);
	if(len>=nl) return;
	int i, d = nl - len;
	for(i=len;i>=0;i--) c[i+d] = c[i];
	for(i=0;i!=d;i++) c[i] = nchar;
}

class Num {
	#define MAXIN (150)
	#define QUOTE (10000)
public:
	int mag;
	int val[MAXIN];
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
	}
	void print() {
		if(mag==0) { putchar('0'); return; }
		printf("%d",val[mag-1]);
		for(int i=mag-2;i>=0;i--) printf("%04d",val[i]);
	}
	void print(int len,char fill) {
		char s[len+1];
		int i;
		int p = 0;
		if(mag==0) {
			s[0] = '0';
			s[1] = '\0';
			p=1;
		} else {
			sprintf(s,"%d",val[mag-1]);
			p = strlen(s);
			for(int i=mag-2;i>=0;i--) {
				sprintf(s+p,"%04d",val[i]);
				p+=4;
			}
			s[p] = '\0';
		}
		preenche(s,len,fill);
		printf("%s",s);
	}
	void add(int i) {
		if(mag==0) mag=1;
		val[0] += i;
		correct();
	}
	void add(Num n) {
		int i;
		for(i=mag;i<n.mag;i++) val[i]=0;
		if(mag<n.mag) mag = n.mag;
		for(i=0;i!=mag;i++) val[i]+=n.val[i];
		correct();
	}
	void add(Num *n) {
		int i;
		for(i=mag;i<n->mag;i++) val[i]=0;
		if(mag<n->mag) mag = n->mag;
		for(i=0;i!=mag;i++) val[i]+=n->val[i];
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
	}
	void mul(Num &n) {
		if(n.mag==0 || mag==0) {
			mag = 0;
			return;
		}
		if(n.mag==1 && n.val[0]==1) return;
		int i,j;
		int temp[MAXIN];
		int nmag = mag;
		for(i=0;i!=MAXIN;i++) temp[i] = 0;
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
};


int main() {

	Num *val[MAXI+1];
	int m[TIPOS] = {10000,5000,2000,1000,500,200,100,50,20,10,5};

	int i,j,k;

	for(j=1;j<=MAXI;j++) val[j] = new Num(0);
	val[0] = new Num(1);

	for(i=0;i<TIPOS;i++) {
		k = m[i];
		for(j=k;j<=MAXI;j++) {
			val[j]->add(val[j-k]);
		}
	}

	double v;
	while((scanf(" %lf",&v))==1) {
		if(v==0) break;
		printf("%3.2lf ",v);
		v *= 100;
		v += 0.5;
		j = (int) v;
		val[j]->print(17,' ');
		putchar('\n');
	}
	return 0;

}
