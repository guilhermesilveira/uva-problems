#include <iostream>
#include <math.h>
using namespace std;


int main() {

	long long end = 50000;
	long long primo[6000];
	int t,i=0,j=0;
	unsigned long long v1,v2;
	int pc = 0;
	primo[pc++] = 2;
	primo[pc++] = 3;
	
	for(i=5;i<=end;i++) {
		for(j=0;j!=pc;j++) {
			if(i % primo[j] == 0) goto n;
		}
		primo[pc++] = i;
		n:;
	}
	//cout << pc << endl;
	
	cin >> t;
	unsigned long long min,k,l,u;
	int mind, temp;
	while(t--) {
		cin >> v1 >> v2;
		if(v1>v2) {
			k = v2; v2 = v1; v1 = k;
		}
		min = 0;
		mind = 0;
		l = v1;
		while(l<=v2) {
			temp = 1;
			k = l;
			for(i=0;i!=pc;i++) {
				if(primo[i]>k) break;
				if(k % primo[i]==0) {
					long long z = 0;
					while(k%primo[i]==0) {z++; k/=primo[i];}
					temp *= (z + 1);
				}
			}
			if(temp>mind || min==0) {
				min = l;
				mind = temp;
			}
			l++;
		}
		cout << "Between " << v1 << " and " << v2 << ", " << min << " has a maximum of " << (mind) << " divisors." << endl;
	}

	return 0;
	
}
