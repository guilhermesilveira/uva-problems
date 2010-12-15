#include <stdio.h>

int main() {
	
	int c[] = {5,10,25,50};
	int i,man[7490],v;
	for(i=0;i!=7490;i++) man[i]=1;
	for(v=0;v!=4;v++) for(i=c[v];i<7490;i++) man[i] += man[i-c[v]];
	while((scanf("%d",&v))==1) printf("%d\n",man[v]);
	return 0;

}
