#include <stdio.h> 
#include <string.h> 

char str1[100000],str2[100000]; 

int main() 
{ 
	int top; 
	long i; 
	while(scanf("%s %s",str1,str2)!=EOF) 
	{ 
		top=0; 
		long len2 = strlen(str2);
		long len1 = strlen(str1);
		if(len1>len2) {
			printf("No\n");
			continue;
		}
		for(i=0;i<=len2-1;i++) 
		{ 
			 if(str1[top]==str2[i])  {
				top++; 
				if(top==len1) {
					break;
				}
			 }
		} 
		if(top==len1) 
			//printf("%s %s Yes\n",str1,str2); 
			printf("Yes\n"); 
		else 
			//printf("%s %s No\n",str1,str2); 
			printf("No\n"); 
	}
	return 0; 
}
