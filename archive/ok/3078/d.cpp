#include <stdio.h>
#include <string.h>

using namespace std;

char l[10100];
int len;
unsigned long long pos[10100];

void tenta(int p) {

	if(l[p]=='0') return;

	pos[p+1] += pos[p];

	if(p!=len-1 && l[p]=='1') pos[p+2] += pos[p];
	if(p!=len-1 && l[p]=='2' && l[p+1]<='6') pos[p+2] += pos[p];

}

int main() {

	int i;
	while(true) {
		scanf("%s",l);
		if(!strcmp(l,"0")) break;
		len = strlen(l);
		memset(pos,0,sizeof(unsigned long long)*(len+5));
		pos[0] = 1;
		for(i=0;i!=len;i++) if(pos[i]) tenta(i);
		printf("%Lu\n",pos[len]);
	}
	return 0;

}
