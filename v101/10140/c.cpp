#include <iostream>

using namespace std;

#define MAX_PRIME (1000001)
#define MAX_PRIME2 (100001)

int primo[MAX_PRIME2];
int primos = 1;

void gera() {
	primo[0] = 2;
	int i,j;
	for(i=3;i<=MAX_PRIME;i+=2) {
		for(j=1;j!=primos;j++) if(i % primo[j] == 0) goto n;
		primo[primos++] = i;
		n:;
	}
}

int main() {

	cout << "gera" << endl;
	gera();
	cout << primos << endl;

	return 0;
	
}
