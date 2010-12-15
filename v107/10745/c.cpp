#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

bool comp(const char *c1,const char *c2) {
	return strcmp(c1,c2);
}

int main() {

	vector<char * > str;
	int tot = 0;
	while(true) {
		char *st = new char[12];
		if(!(cin >> st)) {
			break;
		}
		str.push_back(st);
		tot++;
	}

	sort(str.begin(),str.end(),comp);

	int tab[30];
	int len[15001];
	int tab[15001][30];
	int i,j,k,l;

	for(i=0;i!=tot;i++) {
		len[i] = strlen(str[i]);
		for(j=0;j!=30;j++) tab[i][j] = 0;
		for(j=0;j!=l;j++) tab[str[i][j]-'a']++;
	}

	for(i=0;i!=tot;i++) {
		l = strlen(str[i]);
/*		for(j=0;j!=30;j++) tab[j] = 0;
		for(j=0;j!=l;j++) tab[str[i][j]-'a']++;
		for(j=0;j!=i;j++) {
			cout << str[i] << " dom " << str[j] << endl;
			
		}*/
	}

	return 0;

}
