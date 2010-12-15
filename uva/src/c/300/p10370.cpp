/* @JUDGE_ID: 39315ZN 10370 C++ "counting" */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv) {
	
	int total;
	int pontos[1000];

	int count;
	cin >> count;
	
	while(count--!=0) {
		
		float geral;
		float achados;
		geral = 0;
		achados = 0;
		cin >> total;
		for(int i=0;i!=total;i++) {
			cin >> pontos[i];
			geral += pontos[i];
		}
		
		geral /= total;
		for(int i=0;i!=total;i++) {
			if(pontos[i]>geral) {
				achados++;
			}
		}
		
		printf("%.3f%%\n",(achados * 100 / total));
		
	}
		
	return 0;
	
}
