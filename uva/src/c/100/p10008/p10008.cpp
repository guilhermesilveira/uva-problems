/* @JUDGE_ID: 39315ZN 10008 C++ "Count" */

#include <vector.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

long long vezes[256];
vector<char> caracteres;

bool ordenadora(const char &c1, const char &c2) {
	return vezes[c1]==vezes[c2]?c2>c1:vezes[c1]>vezes[c2];
}

int main(int argc, char **argv) {
	
	int i = 0;
	cin >> i;
	
	for(;i!=-1;i--) {
		
		string str;
		getline(cin,str);
		const char *line = str.c_str();
		for(int z=str.length()-1;z!=-1;z--) {
			char c = line[z];
			if((c<'A' || c>'Z') && (c<'a' || c>'z')) continue;
			if(c>='a') c-=32;
			if(vezes[c]==0) {
				caracteres.push_back(c);
			}
			vezes[c]++;
		}
		
	}
	
	sort(caracteres.begin(),caracteres.end(),ordenadora);
	for(int i=0;i!=caracteres.size();i++) {
		cout << caracteres[i] << " " << vezes[caracteres[i]] << endl;
	}
	
	return 0;
	
}

