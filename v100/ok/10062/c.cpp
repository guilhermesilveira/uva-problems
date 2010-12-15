#include <iostream>
#include <cstdio>
#define FOR(a,b) for(a=0;a<b;a++)
#include <vector>
#include <algorithm>

using namespace std;

int freq[200];
vector<char> car;

bool comp(char c1,char c2) {
	if(freq[c1] != freq[c2]) return freq[c1] < freq[c2];
	return c1 > c2;
}

int main() {

	int z=0;
	char lin[1010];
	int i,j,k,l;

	while((gets(lin))) {

		if(z++) cout << endl;

		FOR(i,200) freq[i]=0;

		l=strlen(lin);
		FOR(i,l) freq[lin[i]]++;

		car.clear();
		for(i=32;i<130;i++) if(freq[i]) car.push_back(i);

		sort(car.begin(), car.end(), comp);

		l = car.size();
		FOR(i,l) cout << (int) car[i] << " " << freq[car[i]] << endl;


	}
	return 0;

}
