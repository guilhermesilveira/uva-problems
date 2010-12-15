#include <stdio.h>

int dna[20];
char linha[2][50];

int vz(char c) {
	if(c==' ') return 0;
	if(c=='.') return 1;
	if(c=='x') return 2;
	return 3;
}

char val(int h,int j) {
	int v = 0;
	if(j!=0) v += vz(linha[h][j-1]);
	if(j!=39) v += vz(linha[h][j+1]);
	v += vz(linha[h][j]);
	if(dna[v]==0) return ' ';
	if(dna[v]==1) return '.';
	if(dna[v]==2) return 'x';
	return 'W';
}

int main() {

	int i,h,j,k,l,t;
	scanf("%d",&t);
	while(t--) {
		for(i=0;i!=2;i++) { linha[i][40]='\n'; linha[i][41]='\0'; }
		for(i=0;i!=40;i++) linha[0][i]=' ';
		linha[0][19]='.';
		for(i=0;i!=10;i++) scanf("%d",&dna[i]);
		h = 0;
		for(i=0;i!=50;i++) {
			k = !h;
			printf("%s",linha[h]);
			for(j=0;j!=40;j++) linha[k][j]=val(h,j);
			h = k;
		}
		if(t) printf("\n");
	}
	return 0;

}
