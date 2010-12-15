#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*
**  Calling parameters: 1 - Number string to be converted
**                      2 - Buffer for the  converted output
**                      3 - Radix (base) of the input
**                      4 - Radix of the output
**  Returns: Pointer to converted output
*/
char *base_convert(const char *in, char *out, int rin, int rout)
{
      unsigned long long n;
      char *dummy;
      n = toBase10(in, rin);
      dummy = ltoa(n, out, rout);
      return dummy;
}

bool eh(char *in,int b) {
	if((*in)=='-') in++;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			if((*in)-'0'>=b) return false;
		} else if((*in)>='A' && (*in)<='F') {
			if((*in)-'A'+10>=b) return false;
		} else {
			return false;
		}
		in++;
	}
	return true;
}



int main() {

	char st[1000],st2[1000];
	int t,i,j,k;
	cin >> t;
	while(t--) {
		cin >> st;
		base_convert(st,st2,10,2);
		j=0;
		k = strlen(st2);
		for(i=0;i!=k;i++) if(st2[i]=='1') j++;
		cout << j << " ";
		base_convert(st,st2,16,2);
		j = 0;
		k = strlen(st2);
		for(i=0;i!=k;i++) if(st2[i]=='1') j++;
		cout << j << endl;
	}
	return 0;

}
