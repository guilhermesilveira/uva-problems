#include <stdio.h>
#include <iostream>

using namespace std;

#define GRAUS(Y) ((Y) * 360 / 40)

int main(char **argv,int argc) {

	while(true) {
		
		int start,b,c,d;
		scanf(" %d %d %d %d",&start,&b,&c,&d);
		if(start==0 && b==0 && c==0 && d==0) break;
		
		int atual = start;
		int degrees = 720;
		degrees += 360;
		//cout << "atual:: " << atual << ", deg: " << degrees << endl;
		
		if(atual < b) {
			atual += 40;
		}
		//cout << atual << "," << b << endl;
		
		degrees += GRAUS(atual - b);
		atual = b;
		//cout << degrees << endl;
		
		if(atual > c) {
			atual -= 40;
		}
		int x = GRAUS(c - atual);
		if(x < 0) {
			x = 0 - x;
		}
		degrees += x;
		atual = c;
		
		if(atual < d) {
			atual += 40;
		}
		
		degrees += GRAUS(atual - d);
		atual = d;
		
		cout << degrees << endl;

	}

	return 0;

}
