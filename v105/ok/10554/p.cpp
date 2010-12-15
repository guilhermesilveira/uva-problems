#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

char type, str[100];

long le() {
int len = strlen(str); type = str[len-1];
str[len-1] = '\0'; return atol(str);
}

long getCal( long fat, char p, int mut) {
if(p=='C') return fat;
return fat * mut;
}

int main(){
int linhas=0,len;
long fat,prot,alc;
double totcal=0,totcalfat=0;
int por=0,cal=0;
while(true) {

totcal=totcalfat=0;
linhas=0;
while(true) {

por = cal = 0;
cin >> str;
if(str[0]=='-') break;
fat=le();
char pt = type;
if(pt=='%') por += fat; else cal += getCal(fat,pt,9);

for(int j=0;j!=3;j++) {
cin >> str;
prot=le();
if(type=='%') por += prot; else cal += getCal(prot,type,4);
}

cin >> str;
prot=le();
if(type=='%') por += prot; else cal += getCal(prot,type,7);

double tdv = (100.0*cal)/(100.0-por);
totcal += tdv;
if(pt=='%') totcalfat += (fat*tdv)/100.0;
else totcalfat += getCal(fat,pt,9);
linhas++;

}

if(linhas==0) return 0;
double v = (totcalfat * 100.0) / totcal;
cout << ((long) (v + 0.5)) << "%" <<  endl;



}




return 0;
}

