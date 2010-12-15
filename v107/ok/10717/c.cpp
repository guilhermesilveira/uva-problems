#include <iostream>
#include <cmath>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;


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

long lcm(long a,long b) {
	return (a*b)/gcd(a,b);
}

int main() {

	int n,t,i,j,k,l,tot;
	long long v;
	long val[60];
	long comb[240000];
	long men,mai;
	while((cin >> n >> t)) {
		FOR(i,n) cin >> val[i];
		tot = 0;
		FOR(i,n) for(j=i+1;j<n;j++) for(k=j+1;k<n;k++) for(l=k+1;l<n;l++) {
			comb[tot++] = lcm(val[i],lcm(val[j],lcm(val[k],val[l])));
			//cout << "hmm: " << val[tot-1] << endl;
		}
		while(t--) {
			cin >> v;
			FOR(i,tot) {
				l = v / comb[i];
				if(l*comb[i]==v) { men = mai = v; break; }
				if(!i || l*comb[i]>men) men = l * comb[i];
				if(!i || l*comb[i]+comb[i]<mai) mai = l * comb[i] + comb[i];
				// cout << i << " " << (l*comb[i]) << endl;
			}
			cout << men << " " << mai << endl;
		}
	}
	return 0;

}
