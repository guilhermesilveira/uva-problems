#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

typedef map< string, int > treeType;

treeType treeList;

int main(){
   string elem;
   double count;
   int caseNum, l;
   char buf[500];

   cin >> caseNum;
   cin.getline(buf, sizeof(buf));

   for( l = 0; l < caseNum; l++ ){
      count = 0;
   
      while( cin.getline(buf, sizeof(buf)) ){

         if( int(buf[0]) == 0 )
            break;

         elem = buf;
         count++;
         treeList[elem]++;
      }


      treeType::iterator l = treeList.begin();
      while( l != treeList.end() ){
         cout.setf(ios::fixed);
         cout.precision(4);
         cout << (*l).first << " " << double((*l).second)/count*100.0 << endl;   
         l++;
      }
   }

   return 0;
} 