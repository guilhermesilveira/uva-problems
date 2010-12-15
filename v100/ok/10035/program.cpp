#include <stdio.h>
#include <iostream>

using namespace std;

int main(char **argv,int argc) {

	unsigned long long s1,s2,temp;
	while(true) {
	
		cin >> s1 >> s2;
		if(s1==0 && s2==0) break;
		
		if(s1>s2) {
			temp = s2;
			s2 = s1;
			s1 = temp;
		}
		
		int soma;
		int carry = 0;
		int count = 0;
		while(s1!=0 || s2!=0) {
			soma = (s1 % 10) + (s2 % 10) + carry;
			if(soma >= 10) {
				carry = 1;
				count++;
			} else {
				carry= 0;
			}
			s1 /= 10;
			s2 /= 10;
		}
		
		if(count==0) {
			printf("No carry operation.\n");
		} else if(count==1) {
			printf("1 carry operation.\n");
		} else {
			printf("%d carry operations.\n",count);
		}
		
	}

	return 0;

}
