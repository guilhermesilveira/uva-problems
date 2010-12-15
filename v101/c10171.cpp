#include <iostream>
#include <stdio.h>
using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int n;

int con[2][30][30];

int val(char c) {
  if(c=='M') return 0;
  return 1;
}


void st() {

  int i,j,k; char a[2],b[2],c[2],d[2];
  int z;
  FOR(i,30) FOR(j,30) FOR(k,2) con[k][i][j] = 0;
  FOR(i,n) {
    //cout << i << endl;
    scanf("%s %s %s %s %d",a,b,c,d,&k);
    //cout << a << b << c << d << k << endl;
    z=c[0]-'A'; j=d[0]-'A';
    con[val(a[0])][z][j] = k;
    if(b[0]=='B') {
      con[val(a[0])][j][z] = k;
    }
  }
  cin >> a >> b;
  //  cout << "teste"  << a << b << endl;
a[0]-='A'; b[0]-='A';
  FOR(z,2) {
    FOR(i,30) FOR(j,30) if(i!=j && con[z][j][i]) 
      FOR(k,30) if(i!=k && j!=k && con[z][i][k]) {
	if(con[z][j][k]==0 || con[z][j][k]<con[z][j][i]+con[z][i][k])
	  con[z][j][k]=con[z][j][i]+con[z][i][k];
      }
  }
  /*  FOR(z,2) {
    FOR(i,5) {
      FOR(j,5) cout << con[z][i][j] << " ";
      cout << endl;
    }
    cout << endl;
    }*/
  if(a[0]==b[0]) {
    cout << 0 << endl;
  } else {
    int mini = -1; char atual;
    FOR(i,30) if(con[0][b[0]][i] && con[1][a[0]][i] && ( mini==-1 || mini<con[0][b[0]][i] + con[1][a[0]][i])) {
      mini = con[0][b[0]][i] + con[1][a[0]][i];
      atual = i + 'A';
    }
    if(mini==-1) cout << "You will never meet." << endl;
    else cout << mini << " " << atual << endl;
  }

}

int main() {

  while((cin >> n) && n){
    st();
  }
  return 0;

}

