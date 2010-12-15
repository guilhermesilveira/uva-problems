#include <iostream>
#define max 30002
using namespace std;

int main(void)
{
int n;
   long long t[max+1];
   int i;
   for (i=0;i<max;i++) t[i] = 1; 
   for (i=5;i<max;i++) t[i]+=t[i-5];
   for (i=10;i<max;i++) t[i]+=t[i-10];
   for (i=25;i<max;i++) t[i]+=t[i-25];
   for (i=50;i<max;i++) t[i]+=t[i-50];

while (cin>>n)
     if (t[n]==1){
           cout << "There is only 1 way to produce " << n << " cents change." << endl;}
     else{
           cout << "There are " << t[n] << " ways to produce " << n << " cents change. " << endl;}

  return 0;
} 
