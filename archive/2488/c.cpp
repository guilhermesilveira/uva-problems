#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

#define FOR(a,b) for(int a=0;a<b;a++)
#define pb push_back

using namespace std;

bool ok(int a,int b,int c,int d) {
	return a>=0 && b>=0 && a<c && b<d;
}

int cus[200][200];
char l[200][200];
bool v[200][200];

bool valo(int y,int x) {
	return l[y][x]=='.' || l[y][x]=='s' || l[y][x]==' ';
}

bool fim(int a,int b,int c,int d) {
	return a==0 || b==0 || a==c-1 || b==d-1;
}

bool cmp(const pair<int,int> &p1,const pair<int,int> &p2) {
	if(v[p1.second][p1.first]) return false;
	if(v[p2.second][p2.first]) return true;
	return cus[p1.second][p1.first]<cus[p2.second][p2.first];
}

int main() {

	int X,Y,x,y,ins = 0;
	vector<pair<int,int> > p;
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};

	while(cin.getline(l[0],120)) {

		sscanf(l[0],"%d %d",&X,&Y);

		p.clear();
		if(!X && !Y) break;
		X=2*X+1; Y=2*Y+1;

		cout << "Maze " << ++ins << ": ";
		cout << X << " " << Y << endl;

		FOR(i,Y) cin.getline(l[i],120);
		FOR(i,Y) cout << l[i] << endl;
		FOR(i,Y) FOR(j,X) {
			v[i][j]=false; cus[i][j] = 1 << 14;
			if(l[i][j]=='s') { x=j;y=i; }
		}

		p.pb(make_pair(x,y));
		cus[y][x] = 0;
		while(p.size()!=0) {
			pair<int,int> pi = *min_element(p.begin(),p.end(),cmp);
			x = pi.first; y = pi.second;
			cout << "x=" << x << " " << y << "=" << y << endl;
			if(v[y][x]) continue;
			v[y][x] = true;
			if(fim(x,y,X,Y)) goto ok;
			FOR(i,4) {
				int x2 = x + dx[i]; int y2 = y + dy[i];
				cout << "t: " << y2 << "," << x2 << " " << endl;
				if(!ok(x2,y2,X,Y) || v[y2][x2]) continue;
				if(!valo(y2,x2)) continue;
				cout << "tt" << y2 << "," << x2 << " " << cus[y2][x2] << endl;
				if(cus[y2][x2]>cus[y][x]+1) {
					cus[y2][x2] = cus[y][x] + 1;
					cout << "adding " << x2 << " " << y2 << endl;
					p.pb(make_pair(x2,y2));
				}
			}
		}

		
		cout << "No escape!" << endl; continue;
	ok:
		cout << cus[y][x] << endl;	
	}
	
	return 0;

}

