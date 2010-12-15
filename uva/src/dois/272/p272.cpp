/* @JUDGE_ID: 39315ZN 272 C++ "Largura" */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv) {
	
	bool primeira = true;
	char c;
	
	while(scanf("%c",&c)==1) {
		
		if(c=='\"') {
			if(primeira) {
				cout << "``";
			} else {
				cout << "''";
			}
			primeira = !primeira;
		} else {
			cout << c;
		}

	}
	
	return 0;
	
}
