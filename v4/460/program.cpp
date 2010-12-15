#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Quadrado {
public:
	int x1,y1;
	int x2,y2;
	void toString() {
		cout << x1 << "," << y1 << " " << x2 << "," << y2 << endl;
	}
};

int main(char **argv,int argc) {

	Quadrado *q1 = new Quadrado;	
	Quadrado *q2 = new Quadrado;	
	Quadrado *q3 = new Quadrado;	

	while(true) {
	
		if(!(cin >> q1->x1 >> q1->y1 >> q1->x2 >> q1->y2)) break;
		cin >> q2->x1 >> q2->y1 >> q2->x2 >> q2->y2;
		
		cout << endl << "para" << endl;
		q1->toString();
		q2->toString();
		
		if(q1->igual(q2)) {
			cout << "No Overlap" << endl;
		}

		if(q1->x1 == q2->x1) {
			q3->x1 = q1->x1
		} else if(q1->x1 > q2->x1) {
			// o primeiro comeca depois do segundo
			
		} else {
			// o segundo comeca depois do primeiro
		}

	}

	return 0;

}
