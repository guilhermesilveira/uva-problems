#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

vector<int> conn[30];
bool ac[30];

int main() {

  int i,j,k,l;
  char s[10000];
  int len;
  while((gets(s))) {
    len = strlen(s);
    if(s[0]=='#') break;
    FOR(i,30) conn[i].clear();
    FOR(i,30) ac[i]=0;
    i = 0;
    char atual;
    int ordem = 0;
    while(true) {
      atual = s[i];
      i++;
      ordem = 1;
      while(s[i]!=';' && s[i]!='.') {
	if(s[i]!=':') {
	  // cout << "c " << atual << " e " << s[i] << endl; 
	    conn[atual-'A'].push_back(s[i]-'A');
	}
	i++;
      }
      if(s[i]=='.') break;
      i++;
    }
    char at = s[i+2] - 'A';
    char last = s[i+4] - 'A';
    int delta;
    sscanf(&s[i+6],"%d",&delta);
    //       cout << (at+'A') << " " << (last+'A') << " " << delta << endl;
    int move = 0;
    while(true) {
      j = conn[at].size();
      FOR(k,j) {
	i = conn[at][k];
	if(i!=last && !ac[i]) {
	  //	  cout << "vai para " << (char)(i+'A') << endl;
	  //cout << "e o cara chega em " << (char)(at+'A') << endl;
	  move++;
	  if(move==delta) {
	    //	    cout << "acende em ";
	    cout << (char)(at+'A')<<" ";
	    ac[at] = 1;
	    move = 0;
	  }
	  last = at;
	  at = i;
	  goto n; 
	}
      }
      // nao conseguiu, foi capturado
      cout << "/" << (char)(at+'A') << endl;
      break;
    n:;
    }
  }
  return 0;
}
