#include <iostream>
#include <cmath>
#define FOR(a,c,b) for(a=c;a<b;a++)

using namespace std;

#define bs_isprime(x) (((x) == 2) || (((x) & 1) && (bitsieve[(x)>>4] & (1 << (((x)>>1)&7)))) )
#define bs_set(x)     ( bitsieve[(x)>>4] |=  (1 << (((x)>>1)&7)) )
#define bs_unset(x)   ( bitsieve[(x)>>4] &= ~(1 << (((x)>>1)&7)) ) 

int main() {

#define MAXI 10000001

	//bool *eh = new bool[MAXI];
	char *bitsieve = new char[10000000];
	int *pr = new int[670000];
	int prc = 0;
	pr[prc++] = 2;
	bs_set(2);

	register int i,j,k;
	for(i=3;i<MAXI;i+=2) bs_set(i);

	int upto = 4000;
	
	for(i=3;i<MAXI;i+=2) if(bs_isprime(i)) {
		pr[prc++] = i;
		for(j=i+i+i;j<MAXI;j+=i+i) bs_unset(j);
	}
	cout <<prc<< endl;

	int n,a,b,c;
	while((cin >> n)) {
		if(n<8) { cout << "Impossible." << endl; continue; }
		if(n%2==0) {cout << "2 2"; n-=4;}
		else if(n%2==1) {cout << "2 3"; n-=5;}
		FOR(i,0,prc) {
			if(pr[i]>n) break;
			if(bs_isprime(i)) {
				cout << " " << pr[i] << " " << (n-pr[i]) << endl;
				goto f;
			}
		}
		while(true);
		f:;
	}

	return 0;

}
