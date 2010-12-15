#include <iostream>
#include <stdio.h>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int vis[500][500],sec[500][500];
char linha[500][100];

int setor,val;
int n;
int am[500],ini[500];

bool valido(int y,int x) {
	return !(y<0 || x<0 || x==n || y==n);
}

bool f;

int marca(int y,int x,char c,int sect) {
	
	if(!valido(y,x) || vis[y][x] || linha[y][x]=='.' || linha[y][x]=='*') return 0;
	if(sec[y][x]!=sect) return 0;
	
	// inimigo
	if(linha[y][x]!=c) {
		cout << "fight " << y << "," << x << endl;
		if(c=='B')
		f = true;
		return 0;
	}

	cout << "marca: " << y << "," << x << endl;

	vis[y][x] = 1;
	marca(y-1,x,c,sect);
	marca(y+1,x,c,sect);
	marca(y,x+1,c,sect);
	marca(y,x-1,c,sect);
	return 1;
	
}

void search(int sect) {

	int i,j;	
	FOR(i,n) FOR(j,n) vis[i][j] = 0;

	// sei que eh setor
	am[sect]=ini[sect]=0;
	
	FOR(i,n) {
		FOR(j,n) {
			if(vis[i][j]==0 && sec[i][j]==sect && linha[i][j]!='*') {
				cout << "vou tentar " << i << "," << j << endl;
				f = false;
				int v = marca(i,j,linha[i][j],sect);
				if(f) { val++; cout << f << endl;}
				//cout << "achei " << v << endl;
				if(linha[i][j]=='B') am[sect]+=v;
				else ini[sect]+=v;
				vis[i][j] = 1;
			}
		}
	}

	cout << "Sector #" << sect << " contain " << am[sect] << " freedom fighter group(s) & " << ini[sect] << " enemy group(s)" << endl;
	
}

void sector(int y,int x) {
	
	if(!valido(y,x) || vis[y][x] || linha[y][x]=='.') { return; }
	
	// marco como visitado e como terreno nosso
	sec[y][x] = setor;
	vis[y][x] = 1;
	sector(y-1,x);
	sector(y+1,x);
	sector(y,x+1);
	sector(y,x-1);

}

void start(int y,int x) {
	if(linha[y][x]=='.') {
		vis[y][x] = 1; return;
	}
	setor++;
	//cout << "setor " << setor<< endl;
	sector(y,x);
}

int main() {
	
	int i,j;
	while((cin >> n)) {
		cout << n << endl;
		if(n==0) break;
//		scanf(" ");
		FOR(i,n) {
		//	cin.getline(linha[i],100);
		cin >> linha[i];
			cout << linha[i] << endl;
		}
		val = 0;
		FOR(i,n) FOR(j,n) vis[i][j] = sec[i][j] = 0;
		setor = 0;
		FOR(i,n) FOR(j,n) if(!vis[i][j]) start(i,j);
		cout << "tot: " << setor << endl;
		FOR(i,setor) search(i+1);
		cout << "Total " << (val*2) << " group(s) are in fighting position." << endl;
	}
	return 0;
		
}
