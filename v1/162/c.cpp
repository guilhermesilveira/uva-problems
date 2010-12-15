#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	//int t;
	//int inst = 0;
	
	int tot;
	char carta[100][3];
	
	int pcartas[3];
	int player[3][100];
	bool valida[3][100];

	while(true) {
		cin >> carta[0];
		if(carta[0]=='#') break;
		for(int i=1;i!=52;i++) cin >> carta[i];
		int atual = 1;
		pcartas[0] = 26;
		pcartas[1] = 26;
		for(int i=0;i<52;i+=2) {
			player[(i+1)%2][i/2] = carta[i][1];
			player[(i)%2][i/2] = carta[i+1][1];
		}
		
		while(true) {
			if(!pcartas[0] || !pcartas[1]) break;
			tot = 0;
			char c = player[atual][pcartas[atual]-1];
			
			if(c=='J') {
			} else if(c=='Q') {
			} else if(c=='K') {
			} else if(c=='A') {
			}
			carta[tot++][0] = c;
		}
	}
	
	
	return 0;
	
}
