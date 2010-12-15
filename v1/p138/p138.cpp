/* @JUDGE_ID: 39315ZN 138 C++ "Rua" */

//#include <iostream>
#include <stdio.h>

//using namespace std;

long long anteriores=0;
long long posteriores=0;
long long casa = 1;
long long b = 1;
int found = 0;

int main(int argc, char **argv) {
	
	while(found!=10) {
		while(anteriores<posteriores) {
			anteriores+=casa++;
			posteriores-=casa;
		}
		if(anteriores==posteriores && anteriores!=0) {
			found++;
			printf("%10lli %10lli\n",casa,b);
			posteriores+=++b;
		}else if(posteriores<=anteriores) {
			posteriores+=++b;
		}
	}
	
	return 0;

}
