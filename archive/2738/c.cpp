#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int tot;

class Node {
public:
	bool ja;
};

Node nodes[5][1001];

int possivel;

int m;

//int tr[5000][2];

void imprime() {
	for(int i=0;i!=m;i++) {
	//	cout << tr[i][0] << "," << tr[i][1] << endl;
	}
	cout << endl;
}

void tenta(int y,int x, int vis) {

	if(x==0 && y == 0 && vis!=m) return;

//	cout << "x " << x << " y " << y << endl;
/*	tr[vis][0] = y;
	tr[vis][1] = x;*/

	if(vis==m) {
		if(y==0 && x==0) {
			//imprime();
			possivel++;
		}
		return;
	}

	if(y!=0) {
		if(!nodes[y-1][x].ja) {
			nodes[y-1][x].ja = true;
			tenta(y-1,x,vis+1);
			nodes[y-1][x].ja = false;
		}
	}

	if(y!=3) {
		if(!nodes[y+1][x].ja) {
			nodes[y+1][x].ja = true;
			tenta(y+1,x,vis+1);
			nodes[y+1][x].ja = false;
		}
	}

	if(x!=0) {
		if(!nodes[y][x-1].ja) {
			nodes[y][x-1].ja = true;
			tenta(y,x-1,vis+1);
			nodes[y][x-1].ja = false;
		}
	}

	if(x+1!=tot) {
		if(!nodes[y][x+1].ja) {
			nodes[y][x+1].ja = true;
			tenta(y,x+1,vis+1);
			nodes[y][x+1].ja = false;
		}
	}

}

int main() {

	char s[651];
	int len, j;
	while(true) {
		cin.getline(s,610,'\n');
		if(s[0]=='#') break;
		tot = atoi(s);
		for(int i=0;i!=4;i++) {
			for(j=0;j!=tot;j++) {
				nodes[i][j].ja = false;
			}
		}
		m = tot * 4;
		possivel = 0;
		nodes[1][0].ja = true;
		tenta(1,0,1);
		cout << tot << ": " << possivel*2 << endl;
	}
	return 0;

}
