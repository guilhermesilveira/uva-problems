#include <iostream> 
#include <string> 

using namespace std;

int m;
int n;
string mapa[100];

void findNext(int &lastL,int &lastP, char c) {
	if(lastP!=0 && mapa[lastL][lastP-1]==c) {
		cout << "left";
		lastP--;
	} else if(lastP!=(n-1) && mapa[lastL][lastP+1]==c) {
		cout << "right";
		lastP++;
	} else {
		cout << "forth";
		lastL--;
	}
}

int main(int argc,char **argv) {
	
	int total;
	cin >> total;
	
	while(total--!=0) {
		
		cin >> m >> n;
		
		for(int i=0;i!=m;i++) {
			cin >> mapa[i];
		}
		
		int lastL = m-1;
		int lastP = mapa[lastL].find('@');
		findNext(lastL,lastP,'I');
		cout << " ";
		findNext(lastL,lastP,'E');
		cout << " ";
		findNext(lastL,lastP,'H');
		cout << " ";
		findNext(lastL,lastP,'O');
		cout << " ";
		findNext(lastL,lastP,'V');
		cout << " ";
		findNext(lastL,lastP,'A');
		cout << " ";
		findNext(lastL,lastP,'#');
		cout << endl;
		
	}	

	return 0; 
	
}
