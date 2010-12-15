#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

set<string> ign;

#define MINI(s) for(i=s.size()-1;i>=0;i--) if(s[i]>='A' && s[i]<='Z') s[i] = s[i] - 'A' + 'a';
int main() {
  int i,j;
  while(!cin.eof()) {
    string s;
    getline(cin,s);
    if(s[0]==':' && s[1]==':') break;
    MINI(s);
    ign.insert(s);
    cout << "p " << s << endl;
  }
  string s;
  while(getline(cin,s)) {
    vector<string> pal = split(s);
    
    cout << pal[0] << endl;
  }
  return 0;
}
