#include <iostream>
#include <stdio.h>

using namespace std;

#define mineIt(a,b) mines[a][b]=0; if(m[a][b]!='M') for(k=-1;k<=1;k++) for(l=-1;l<=1;l++) if(m[a+k][b+l]=='M') mines[a][b]++;

int mx, my;
char m[50][50];
int mines[50][50];
int des[50][50];
int pilha[50*50][2];
int pc;

#define YES 1
#define FLAG 2
#define MINE 3
#define NO  0

#define pa(a,b); pilha[pc][0]=a;pilha[pc++][1]=b;

void limpa() {
	int i, j;
	for(i=0;i<=my+1;i++) {
		for(j=0;j<=mx+1;j++) {
			des[i][j] = YES;
		}
	}
	for(i=1;i<=my;i++) {
		for(j=1;j<=mx;j++) {
			des[i][j] = NO;
		}
	}
	for(i=0;i<=my+1;i++) {
		for(j=0;j<=mx+1;j++)
		cout << des[i][j];
		cout << endl;
	}
}

void start(int x,int y) {
	
	limpa();
	pc = 0;
	int i,j,flaged,open;
	pa(x,y);
	
	while(pc!=0) {
		
		x = pilha[pc-1][0];
		y = pilha[pc-1][1];
		pc--;

		flaged = open = 0;
		for(i=-1;i<=1;i++) { for(j=-1;j<=1;j++) {
			if((i!=0 || j!=0) && des[y+i][x+j]==FLAG) flaged++;
			if((i!=0 || j!=0) && des[y+i][x+j]==NO) open++;
		} }
		
		if(flaged==mines[y][x]) {
			// os abertos nao sao mina
			for(i=-1;i<=1;i++) { for(j=-1;j<=1;j++) {
				if(i!=0 || j!=0) {
					if(des[y+i][x+j]==NO) {
//						pa(x+j,y+i);
					}
				}
			} }
		}

		if(open + flaged==mines[y][x]) {
			// os abertos sao minas
			for(i=-1;i<=1;i++) { for(j=-1;j<=1;j++) {
				if(i!=0 || j!=0) {
					if(des[y+i][x+j]==NO) {
						des[y+i][x+j] = MINE;
					}
				}
			} }
		}

	}
	
}

void mine() {

	int i, j, k, l;
	for(i=1;i<=my;i++) {
		for(j=1;j<=mx;j++) {
			mineIt(i,j);
			des[i][j] = NO;
		}
	}
	for(i=1;i<=my;i++) {
		for(j=1;j<=mx;j++)
		cout << mines[i][j];
		cout << endl;
	}

}

void le() {
	
	int i, j;
	
	for(i=1;i<=my;i++) {
		scanf(" %s",&m[i][1]);
		m[i][0] = m[i][mx+1] = '.';
		m[i][mx+2] = '\0';
	}
	
	for(i=0;i<=mx+1;i++) {
		m[0][i] = m[my+1][i] = '.';
	}
	
	m[0][mx+2] = m[my+1][mx+2] = '\0';
	
	for(i=0;i<=my+1;i++) {
		cout << i << ":: " << m[i] << endl;
	}
	
}

int main() {
	
	int i,j;
	
	while((scanf(" %d %d",&my,&mx))==2) {
		if(mx==0 && my==0) break;
		cout << "le" <<endl;
		le();
		//novo();
		mine();
		for(i=1;i<=my;i++) {
			for(j=1;j<=mx;j++) {
				if(m[i][j]=='.') start(i,j);
			}
		}
		cout << endl;
		break;
	}
	
	return 0;
	
}
