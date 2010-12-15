#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(char **argv,int argc) {

	char ns[40];
	map<string,string> m;
	set<string> ms;
	
	while(true) {
		
		char s1[15], s2[15];
		
		fgets(ns,30,stdin);
		
		//cout << ns << endl;
		if(ns[0]=='\0' || ns[0]=='\n' || ns[0]=='\r') break;
		sscanf(ns,"%s %s",s1,s2);
		
		string ss1 = "",ss2 = "";
		ss1 += s1;
		ss2 += s2;
		//printf("%s\n",s1);
//		cout <<ss1 <<"," << ss2 <<endl;
		//m[ss2] = ss1;
		ms.insert(ss2);
//		cout << ss1 << "," << m[ss1] << endl;
		
	}
	
	string s;
	while((cin >> s)) {
		/*cout << s << endl;
		cout << m[s] << endl;*/
		if(binary_search(ms.begin(),ms.end(),s)) {
		//	cout << m[s] << endl;
		} else {
			cout << "eh" << endl;
		}
	}

	return 0;

}
