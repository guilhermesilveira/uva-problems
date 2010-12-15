#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)
#define PI pair<int,int>

int len,h;
int hat[100][2];

double calc(int i,int x,int y) {
	return sqrt((hat[i][0]-x+0.0)*(hat[i][0]-x)+(hat[i][1]-y+0.0)*(hat[i][1]-y));
}

void st() {
	cin >> len >> h;
	int i,j,k,x,y;
	FOR(i,h) cin >> hat[i][0]>>hat[i][1];
	int melhor[2];
	double dist = 0,c;
	bool p = false;
	FOR(x,len) if(x) FOR(y,len) if(y) {
		c=0;
		FOR(i,h) {
			if(hat[i][0]==x && hat[i][1]==y) goto nex;
			c = max(c,calc(i,x,y));
		}
		if(c>x || c>y || c>(len-x) || c>(len-y)) goto nex;
		dist=c;
		p=true;
		melhor[0]=x;melhor[1]=y;
		goto en;
nex:;
	}
	en:
	if(!p) cout << "poodle" << endl;
	else cout << melhor[0] << " " << melhor[1] << endl;
}

int main() {
	int t; cin>>t;while(t--)st();return 0;
}
