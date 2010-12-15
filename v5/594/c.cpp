
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define REP(a,c,b) for(int _n=b,a=c;a<_n;a++)

unsigned long long toBase10(const char *in, int b) {
	unsigned long long v = 0;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			v = v * b + ((*in)-'0');
		} else if((*in)>='A' && (*in)<='Z') {
			v = v * b + ((*in)-'A'+10);
		}
		in++;
	}
	return v;
}

char *ltoa(long long n, char *out, int rout) {
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
	for(int i=0;i!=p;i++) out[i] = temp[p-i-1];
	out[p] = '\0';
	return out;
}

char *base_convert(const char *in, char *out, int rin, int rout)
{
      unsigned long long n = toBase10(in, rin);
      return ltoa(n, out, rout);
}


int main() {

	long long v;
	int i,len,d;
	char s[2][1000];
	while((cin >> v)) {
		ltoa(v,s[0],2);
		len = strlen(s[0]);
		d = 32 - len;
		for(i=0;i!=d;i++) s[1][i]='0';
		for(i=0;i!=len;i++) {
			s[1][i+d] = s[0][len-1-i];
		}
		s[1][32]='\0';
		cout << s[0] << " " << s[1] << endl;
		cout << v << " converts to " << base_convert(s[1],s[0],2,10) << endl;
	}
	return 0;

}
