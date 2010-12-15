#include <iostream>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int p[100][2];
bool hat[50][50];
int s,h;

void le() {

	int a,b,c;
	cin >> s >> h;
	FOR(a,s+1) FOR(b,s+1) hat[a][b] = false;
	FOR(c,h) {
		cin >> a >> b;
		p[c][0] = a;
		p[c][1] = b;
		hat[b][a] = true;
	}

}

int min(int a,int b) {
	return a<b?a:b;
}

int DIST(int x,int y,int pt) {
	return (x-p[pt][0])*(x-p[pt][0]) + (y-p[pt][1])*(y-p[pt][1]);
}

bool st() {
	le();
	int mx,my,x,y,i,j,k,pt;
	int menor=-1,dist,maior,temp;

	FOR(x,s) {
		FOR(y,s) {
			if(hat[y][x]) continue;
			maior = min(min(x,s-x),min(y,s-y));
			maior *= maior;
			cout << x << " " << y << " " << maior << endl;
			temp = -1;
			FOR(pt,h) {
				dist = DIST(x,y,pt);
				if(dist>maior) break;
				if(dist>temp) temp = dist;
			}
			cout << "t: " << pt << " " << dist << endl;
			if(pt!=h) continue;
			if(menor==-1 || temp<menor) {
				menor = temp;
				mx = x; my = y;
			}
		}
	}

	if(menor==-1) return false;
	cout << mx << " " << my << endl;
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		if(!st()) cout << "poodle" << endl;
	}
	return 0;
}



