#include <iostream>
#include <math.h>

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



int main() {
	
	bool *v = new bool[1000000];
	int *vl[2];
	vl[0] = new int[1000001];
	vl[1] = new int[1000001];
	long long n;
	long long i,j,k;

	vl[0][0]=0;
	vl[1][0]=0;
	
	for(n=1;n!=100001;n++) {
		vl[0][n]=0;
		vl[1][n]=0;
		v[n]=true;
	}
	for(i=1;i<1001;i++) {
		for(j=i+1;j<1001;j++) {
			// calcula
			k = (long long) sqrt(0.0+j * j + i * i);
			if(k>1000000) break;
			if(k*k==j*j+i*i) {
				vl[0][k]++;
				cout << i << "," << j << "," << k << endl;
				v[i]=v[j]=v[k]=false;
			}
		}
	}
	int v1=0,v2=0;
	for(i=1;i<101;i++) {
		cout << i << ": " << vl[0][i] << "," << vl[1][i] << endl;
		v2++;
		v1+=vl[0][i];
		v2-=vl[1][i];
		vl[0][i]=v1;
		vl[1][i]=v2;
	}
	goto f;
	for(n=1;n<1001;n++) {
		vl[0][n] = vl[0][n-1];
		vl[1][n] = vl[1][n-1]+1;
		if(n%5000==0) cout << n << endl;
		long long sn = (long long) sqrt(0.0 + n)+1;
		sn = n /2  +10;
		for(i=1;i<=sn;i++) {
//			if(i*i>n*n) break;
			j = (long long) sqrt(0.0 + n*n - i*i);
			if(j<=i || j>n || j*j+i*i!=n*n) continue;
//			cout << "com n=" << n << " tem " << i << " e " << j << endl;
			if(v[i]) { v[i]=false; vl[1][n]--; }
			if(v[j]) { v[j]=false; vl[1][n]--; }
			if(v[n]) { v[n]=false; vl[1][n]--; }
			if(gcd(i,j)==1 && gcd(i,n)==1 && gcd(j,n)==1) {
	//			cout << "gcd" << endl;
				vl[0][n]++;
			}
		}
	}
	f:
	while((cin >> n)) {
		
		if(n==0) {
			cout << 0 << 0 << endl;
		} else {
			cout << vl[0][n] << " " << vl[1][n] << endl;
		}
		
	}
	
	
	return 0;
	
}
