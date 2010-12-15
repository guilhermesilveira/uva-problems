#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

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
	for(int i=0;i!=p;i++) out[i] = temp[p-i-1];
	out[p] = '\0';
	return out;
}

char *base_convert(const char *in, char *out, int rin, int rout)
{
      unsigned long long n;
      char *dummy;
      n = toBase10(in, rin);
      dummy = ltoa(n, out, rout);
      return dummy;
}


long gcd( long a, long b)
{
  int t;

  if (a < 0) a = -a;
  if (!b) return a;
  if (b < 0) b = -b;
  if (!a) return b;
  t = 0;
  while (! ((a|b) & 1)) {a >>= 1; b >>= 1; ++t;}
  while (! (a&1)) a >>= 1;                     
  while (! (b&1)) b >>= 1;
  while (a != b)
     {
     if (a > b)
         {
         a -= b; 
         do {a >>= 1;} while (! (a&1));
         }
     else {
         b -= a;
         do {b >>= 1;} while (! (b&1));
         }
     }
  return(a<<t);
}


int k = 0;
char s[2][100];
char n[2][100];

void st() {

	int i,j,l,m;
	long v[2];
	for(i=0;i!=2;i++) {
		cin >> s[i];
		v[i]=atol(base_convert(s[i],n[i],2,10));
	}
	long max = gcd(v[0],v[1]);
	cout << "Pair #" << ++k << ": ";
	if(max==1) cout << "Love is not all you need!";
	else cout << "All you need is love!";
	cout << endl;


}


int main() {

	int t; cin >> t; while(t--) { st(); } return 0;

}
