/* @JUDGE_ID: 39315ZN 10055 C++ "Minus" */

#include <stdio.h> 
#include <iostream> 
#include <string> 
#include <math.h>

using namespace std;

int main(int argc, char **argv) {
   
   long long i = 0;
   long long z = 0;
   while(cin >> i >> z) {
	   	cout << (z>i?z-i:i-z) << endl;
   }
   
   return 0;
   
}

