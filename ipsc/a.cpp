#include <iostream>

using namespace std;

long long mex(long long a, long long b, long long c) {
  long long d;
  if (b==0) return 1;
  if (b==1) return a%c;
  d=mex(a,b/2,c); d*=d; d%=c; d*=mex(a,b%2,c); d%=c;
  return d;
}

a % c

long long mmx(long long a,long long b,long long c) {
	
	if(c == 1) return 0;
	else 
	
}

int main(void){
  long long nx,mm,nz,ny;
  while (1) {
    if (!(cin >> nx >> nz >> mm)) return 0;
    if(mm == 1) ny = 0;
    else if(mm == nx % nz) ny = 1;
    else ;
    cout << nx << " " << ny << " " << nz << endl;
/*    if (x<0) { printf("too small\n"); continue; }
    if (y<0) { printf("too small\n"); continue; }
    if (z<=1) { printf("too small\n"); continue; }
    if (y>=z) { printf("too big\n"); continue; }
    if (z>=1000000010) { printf("too big\n"); continue; }*/
    printf("%lld %lld %lld\n",x,z,mex(x,y,z));
  }
}
