#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	
	unsigned long long v[50001];
	v[1]=1;
	for(unsigned long long i=2;i!=50001;i++) v[i]=v[i-1]+i*i*i;

	int n;
	while((cin >> n)) cout << v[n] << endl;
	
	return 0;
	
}
