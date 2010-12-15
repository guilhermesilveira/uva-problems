#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>


#define vale(a) (iguais(s[i],a))
#define iguais(a,b) (strcmp((a),(b))==0)
#include <string.h>

using namespace std;


class StrArray {
public:
    char **s;
    int tot;
    StrArray(int i){
        s = (char **) malloc(sizeof(char *)*i);
        clear();
    }
    void clear() {
        tot = 0;
    }
    void add(char *c) {
        s[tot++] = c;
    }
    void split(char *st, char c) {
        clear();
        bool b = false;
        char *start = st;
        while((*st)!='\0' && (*st)!='\r' && (*st)!='\n') {
            if((*st)!=c) {
                if(!b) {
                    start = st;
                    b = true;
                }
            } else {
                (*st) = '\0';
                if(b) {
                    b = false;
                    add(start);
                }
            }
            st++;
        }
        if(b) {
        	(*st) = '\0';
        	add(start);
        }
    }
};


bool isCharacter(char c) {
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool isVocal(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
		c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}


int main() {

	char str[10000];
	StrArray ar = StrArray(500);
	char **s;
	int tot,len;
	while((gets(str))) {
		ar.clear();
		ar.split(str,' ');
		s = ar.s;
		tot = ar.tot;
		bool negative = false;
		long long val = 0;
		int temp = 0;
		bool tempUsed = false;
		for(int i=0;i!=tot;i++) {
			if(strcmp(s[i],"negative")==0) {
				negative = true;
			} else {
				//cout << "::" << s[i] << endl;
				if(vale("one")) {
					temp = 1; tempUsed = true;
				} else if(vale("zero")) {
					temp = 0; tempUsed = true;
				} else if(vale("two")) {
					temp = 2; tempUsed = true;
				} else if(vale("three")) {
					temp = 3; tempUsed = true;
				} else if(vale("four")) {
					temp = 4; tempUsed = true;
				} else if(vale("five")) {
					temp = 5; tempUsed = true;
				} else if(vale("six")) {
					//cout << "six" << endl;
					temp = 6; tempUsed = true;
				} else if(vale("seven")) {
					temp = 7; tempUsed = true;
				} else if(vale("eight")) {
					temp = 8; tempUsed = true;
				} else if(vale("nine")) {
					//cout << "nine" << endl;
					temp = 9; tempUsed = true;
				} else if(vale("ten")) {
					temp = 10; tempUsed = true;
				} else if(vale("twenty")) {
					temp = 20; tempUsed = true;
				} else if(vale("thirty")) {
					temp = 30; tempUsed = true;
				} else if(vale("fourty")) {
					temp = 40; tempUsed = true;
				} else if(vale("fifty")) {
					temp = 50; tempUsed = true;
				} else if(vale("eleven")) {
					temp = 11; tempUsed = true;
				} else if(vale("twelve")) {
					temp = 12; tempUsed = true;
				} else if(vale("thirteen")) {
					temp = 13; tempUsed = true;
				} else if(vale("fourteen")) {
					temp = 14; tempUsed = true;
				} else if(vale("fifteen")) {
					temp = 15; tempUsed = true;
				} else if(vale("sixteen")) {
					temp = 16; tempUsed = true;
				} else if(vale("seventeen")) {
					temp = 17; tempUsed = true;
				} else if(vale("eighteen")) {
					temp = 18; tempUsed = true;
				} else if(vale("nineteen")) {
					temp = 19; tempUsed = true;
				}
				if(tempUsed) {
					if(i != tot - 1 && 
						(
							(iguais(s[i+1],"hundred")) ||
							(iguais(s[i+1],"million")) ||
							(iguais(s[i+1],"thousand"))
							)
					) {
						i++;
						long long v = 1;
						if(vale("hundred")) {
							v = 100;
						} else if(vale("thousand")) {
							v = 1000;
						} else if(vale("million")) {
							v = 1000000;
						}
						val += temp * v;
						tempUsed = false;
					} else {
						// last one
						//cout << "last: " << temp << endl;
						val += temp;
						tempUsed = false;
					}
				}
			}
		}
		if(negative /* && val!=0 */) {
			cout << "-";
		}
		cout << val;
		cout << endl;
	}
	
	return 0;

}
