#include <iostream>
#include <cstdio>
#include <cmath>

#define bs_isprime(x) (((x) == 2) || (((x) & 1) && (bitsieve[(x)>>4] & (1 << (((x)>>1)&7)))) )
#define _bs_set(x)     ( bitsieve[(x)>>4] |=  (1 << (((x)>>1)&7)) )
#define _bs_unset(x)   ( bitsieve[(x)>>4] &= ~(1 << (((x)>>1)&7)) )

char bitsieve[300000];
using namespace std;

void sieve(int upto)
{
   int i, j;
   int isqrt_upto = (int)::sqrt( upto );

   for ( i=3; i<=upto; i+=2 ) _bs_set(i);

   for ( i=3; i<=isqrt_upto; i+=2 )
      if ( bs_isprime(i) )
         for ( j=i*i; j<=upto; j+=i+i )
            _bs_unset( j );
   _bs_unset(1);


}


int n,m,d;

int esc[1010];
bool ja[1010];

void imp() { 
	int i;
	for(i=0;i!=m;i++)  {
		printf("%d",esc[i]);
		if(i!=m-1)
			putchar(',');
	}
	putchar('\n');
}

bool tenta(int l) {


	int i,j;
	if(l==m) {
		imp();
		return true;
	}

	long k;
	for(i=0;i!=m;i++) {
		if(ja[i]) continue;
		esc[l]=n+i;
		for(k=0,j=0;j<d;j++) {
			if(l-j<0) break;
			k += esc[l-j];
			if(j && bs_isprime(k)) goto nex;
		}
		ja[i]=1;
		if(tenta(l+1)) return true;
		ja[i]=0;
		nex:;
	}

	return false;

}

int main() {

	sieve(500010);
	while(true) {
		cin >> n >> m >> d;
		if(!n && !m && !d) break;
		m -= n;
		m++;
		for(int i=0;i!=m;i++) ja[i]=0;
		if(!tenta(0)) cout << "No anti-prime sequence exists." << endl;
	}
	return 0;

}
