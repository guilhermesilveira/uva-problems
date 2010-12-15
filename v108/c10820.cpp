#include <iostream>

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

#define MAX (50001)

int main() {
	long val[MAX];
	register int i,j;
	val[0]=0; val[1]=1;
	for(i=2;i<MAX;i++) val[i]=(i-1)*2;
	for(i=2;i<MAX;i++) {
		if(i%3000==0) cerr << i << endl;
		for(j=1;j<i;j++) {
			if(gcd(i,j)!=1) val[i]-=2;
		}
		val[i] += val[i-1];
	}
	for(i=1;i<MAX;i++) {
		cout << "if(i==" << i << ")cout<<" << val[i] << ";";
	}
	cout << endl;
	return 0;
}
