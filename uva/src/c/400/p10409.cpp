#include <stdio.h> 
#include <iostream> 
#include <string> 

using namespace std;

int main() {
	
	int inicial;
	cin >> inicial;
	
	while(inicial!=0) { 
		
		int top = 1;
		int north = 2;
		int west = 3;
		
		string comando;

		for(int i=0;i!=inicial;i++) {
			
			cin >> comando;
			if(comando=="north") {
				int tempNorth = north;
				north = top;
				top = 7 - tempNorth;
			} else if(comando=="south") {
				int tempTop = top;
				top = north;
				north = 7 - tempTop;
			} else if(comando=="east") {
				int tempTop = top;
				top = west;
				west = 7 - tempTop;
			} else if(comando=="west") {
				int tempWest = west;
				west = top;
				top = 7 - tempWest;
			}
			//cout << comando << " " << top << endl;
			
		}
		
		cout << top << endl;
		
		cin >> inicial;
	}
	
	return 0; 
	
}
