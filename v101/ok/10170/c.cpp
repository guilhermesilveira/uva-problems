#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Num {
	#define MAXI (10)
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
	void add(Num n) {
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
	}
	void mul(Num &n) {
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

	// imprime em uma string
	char *sprint(char *s) {
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
		return s;
	}


};


int main() {

	int a;
	long long b;
	#define MAXZ (10000000)
	Num *val = (Num *) malloc(sizeof(Num) * MAXZ);
	val[0] = Num(0);
	//val[0] = 0;
	for(int i=1;i!=MAXZ;i++) {
		val[i] = Num(i);
		val[i].add(val[i-1]);
//		val[i] = val[i-1] + i;
//		printf("%d %Lu\n",i,val[i]);
	}
	for(int i=0;i!=20;i++) {
		int j = MAXZ - i - 1;
		cout << j << " ";
		val[j].print();
		cout << endl;
	}
	while((scanf("%d %Ld",&a,&b))==2) {
		

	}
	return 0;

}
