/* @JUDGE_ID: 39315ZN 10327 C++ "Largura" */

#include <iostream>
#include <stdio.h>

using namespace std;

int total;
int pontos[1000];

int main(int argc, char **argv) {
	
	while(scanf("%d\n",&total)==1) {
		
		int nivel = 0;
		
		for(int z=0;z!=total;z++) {
			scanf("%d",&pontos[z]);
		}
		
		for(int z=0;z!=total-1;z++) {
			for(int z2=z;z2!=total;z2++) {
				if(pontos[z2]<pontos[z])
					nivel++;
			}
		}
		
		cout<<"Minimum exchange operations : " << nivel<<endl;

	}
		
	return 0;
	
}
