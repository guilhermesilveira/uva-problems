#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(a,b) for(int a=0;a<b;a++)

using namespace std;


// Converte da base b para a base 10, eh isso?

unsigned long long toBase10(const char *in, int b) {
	unsigned long long v = 0;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			v = v * b + ((*in)-'0');
		} else if((*in)>='A' && (*in)<='F') {
			v = v * b + ((*in)-'A'+10);
		}
		in++;
	}
	return v;
}

char *ltoa(unsigned long long n, char *out, int rout) {
	int p = 0;
	char temp[50];
	long long t;
	while(n > 0) {
		t = n % rout;
		if(t<10) temp[p] = '0' + t;
		else temp[p] = 65 + t - 10;
		p++;
		n /= rout;
	}
	if(p==0) temp[p++] = '0';
	for(int i=0;i!=p;i++) {
		out[i] = temp[p-i-1];
	}
	out[p] = '\0';
	return out;
}

bool isdigit(char c) { return c>='0' && c<='9';}

char *base_convert(const char *in, char *out, int rin, int rout)
{
      unsigned long long n;
      char *dummy;
      n = toBase10(in, rin);
      dummy = ltoa(n, out, rout);
      return dummy;
}

using namespace std;

long long soma(char *s) {
	int l = strlen(s);
	long long e = 0;
	FOR(i,l) e += s[i];
	FOR(i,l) e -= (isdigit(s[i])?'0':'A'-10);
	return e;
}

int main() {

	int c = 0;
	long long v[3];
	long long va;
	char n[3][1000];

	while(true) {
		cin >> v[0] >> v[1];
		if(0==v[1] && v[0]==0) break;
		if(v[0]>v[1]) swap(v[0],v[1]);
		for(int k=v[0];k<=v[1];k++) {
			ltoa(k,n[0],10);
			va = soma(n[0]);
			if(soma(ltoa(k,n[1],12))!=va) continue;
			if(soma(ltoa(k,n[2],16))!=va) continue;
			printf("%s\n",n[0]);
		}
		cout << endl;
	}

	return 0;

}
