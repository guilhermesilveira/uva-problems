#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(a,b,c) for(int a=b;a<c;a++)

int main() {

	int a,b,c;
	int v[12000];
	fill(v,&v[12000],0);
	while((cin >> a >> b >> c)) FOR(i,a,c) v[i] = max(v[i],b);
	// c eh o maior valor
	FOR(i,0,12000) if(v[i]) c = i+1;
	FOR(i,1,c) if(v[i]!=v[i-1]) cout << i << " " << v[i] << " ";
	cout << c << " " << 0 << endl;
	return 0;

}
