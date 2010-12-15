#include <stdio.h>

char map[250][251];
long maxY=0,maxX=0;

void pinta(int y,int x,char corAtual, char corFinal) {
	map[y][x] = corFinal;
	if(y>0 && map[y-1][x]==corAtual) {
		pinta(y-1,x,corAtual,corFinal);
	}
	if (y<maxY && map[y+1][x]==corAtual) {
		pinta(y+1,x,corAtual,corFinal);
	}
	if(x>0 && map[y][x-1]==corAtual) {
		pinta(y,x-1,corAtual,corFinal);
	}
	if (x<maxX && map[y][x+1]==corAtual) {
		pinta(y,x+1,corAtual,corFinal);
	}
}

int main(char **argv,int argc) {

	char line[256];
	/*char name[256];*/
	
	long i,i2;
	char cor;
	long x,y,x2,y2;
	
	while(1) {
	
		gets(line);
		if(line[0]=='X') {
			return 0;
		} else if(line[0]=='I') {
			sscanf(line+2,"%d %d",&maxX,&maxY);
			for(i=0;i!=maxY;i++) {
				for(i2=0;i2!=maxX;i2++) {
					map[i][i2] = 'O';
				}
				map[i][maxX] = 0;
			}
		} else if(line[0]=='C') {
			for(i=0;i!=maxY;i++) {
				for(i2=0;i2!=maxX;i2++) {
					map[i][i2] = 'O';
				}
				/*map[i][maxX] = 0;*/
			}
		} else if(line[0]=='S') {
			/*sscanf(line,"S %s",&line);*/
			printf("%s\n",line+2);
			for(i=0;i!=maxY;i++) {
				printf("%s\n",map[i]);
			}
		} else if(line[0]=='L') {
			sscanf(line+2,"%d %d %c",&x,&y,&cor);
			map[y-1][x-1] = cor;
		} else if(line[0]=='F') {
			sscanf(line+2,"%d %d %c",&x,&y,&cor);
			if(map[--y][--x]!=cor) {
				pinta(y,x,map[y][x],cor);
			}
		} else if(line[0]=='V') {
			sscanf(line+2,"%d %d %d %c",&x,&y,&y2,&cor);
			x--;
			if(--y2<--y) {
				i = y2;
				y2 = y;
				y = i;
			}
			for(;y<=y2;y++) {
				map[y][x] = cor;
			}
		} else if(line[0]=='H') {
			sscanf(line+2,"%d %d %d %c",&x,&x2,&y,&cor);
			y--;
			if(--x2<--x) {
				i = x2;
				x2 = x;
				x = i;
			}
			for(;x<=x2;x++) {
				map[y][x] = cor;
			}
		} else if(line[0]=='K') {
			sscanf(line+2,"%d %d %d %d %c",&x,&y,&x2,&y2,&cor);
			if(--y2<--y) {
				i = y2;
				y2 = y;
				y = i;
			}
			if(--x2<--x) {
				i = x2;
				x2 = x;
				x = i;
			}
			i = x;
			for(;y<=y2;y++) {
				for(x=i;x<=x2;x++) {
					map[y][x] = cor;
				}
			}
		}
	}

	return 0;

}
