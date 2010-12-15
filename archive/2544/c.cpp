#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int mx,my;
char mat[30][30];

bool tenta(int x,int y) {
       if(x==-1 || x==mx) return false;
       if(y==my) return false;
       if(mat[y][x]=='P') return false;
	if(mat[y][x]=='!') return false;
	if(mat[y][x]=='S') return false;
	int j = (y-1) % 4;
	int i;
	if(y==0) goto n;
	if(j==0) {
		for(i=y;i!=my;i++) if(mat[i][x]=='S') goto h;
	} if(i==1) {
		for(i=x;i>=0;i--) if(mat[y][i]=='S') goto h;
	} if(i==2) {
		//cout << "pos: " << y << "," << x << " procurando para cima" << endl;
		for(i=y;i>=0;i--) if(mat[i][x]=='S') goto h;
	} if(i==3) {
		for(i=x;i!=mx;i++) if(mat[y][i]=='S') goto h;
	}
	n:
	cout << y << "," << x << endl;
	if(mat[y][x]=='G') return true;
       if(tenta(x-1,y+1)) return true;
       if(tenta(x,y+1)) return true;
       if(tenta(x+1,y+1)) return true;
h:
	if(mat[y][x]=='O') mat[y][x] = '!';
	return false;
}

int main() {

	int i;
	char st[100];
       while(true) {
               scanf(" ");
               gets(st);
               if(st[0]=='E') break;
               sscanf(st,"START %d %d",&mx,&my);
               for(i=0;i!=my;i++) gets(mat[i]);
               int pos;
		for(i=0;i!=mx;i++) if(mat[0][i]=='L') break;
               if(tenta(i,0)) {
                       cout << "FERRET" << endl;
               } else {
                       cout << "GARRET" << endl;
               }
               gets(st);
       }

}
