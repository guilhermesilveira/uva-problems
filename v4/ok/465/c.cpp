#include<stdio.h> 

void main() 
{ 
double n1,n2,result; 
char expression[1000],op[3]; 
while(gets(expression)) 
{ 
sscanf(expression,"%lf%s%lf",&n1,op,&n2); 
printf("%s\n",expression); 
if(n1>2147483647) 
printf("first number too big\n"); 
if(n2>2147483647) 
printf("second number too big\n"); 
if(op[0]=='+') 
result=n1+n2; 
else 
result=n1*n2; 
if(result>2147483647) 
printf("result too big\n"); 
} 
}