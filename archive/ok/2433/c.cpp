#include <iostream>

using namespace std;

int k;
int v[10];

bool tenta(int l,int n,int maxi) {

       //cout << "tn: " << n << " " << l << "," << v[l] << endl;

       if(n==0) return true;

       if(l==k) {
               // nao foi possivel
               return false;
       }

       // se nao sobra suficiente, nao, valeu
       if(n<v[l]) return false;

       // se eh multiplo, ok
       if(n%v[l]==0 && (maxi==-1 || n/v[l]<=maxi)) {
               return true;
       }

       int t = 1;
       while(n>v[l]) {
               n -= v[l];
               if(tenta(l+1,n,t)) return true;
               t++;
               if(maxi!=-1 && t>maxi) break;
       }

       return false;

}

void st() {

       int n;
       cin >> n;
       cin >> k;
       //cout << "N: " << n << " " << k << endl;
       int i;
       for(i=0;i!=k;i++) cin >> v[i];
       if(tenta(0,n,-1)) cout << "YES" << endl;
       else cout << "NO" << endl;

}

int main() {

       int t; cin >> t; while(t--)st();
       return 0;

}