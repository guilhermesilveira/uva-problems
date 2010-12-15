#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle {
public:
	float x1,x2;
	float y1,y2;
	void set(float xx1,float yy1,float xx2,float yy2) {
		if(xx1>xx2) {
			x2 = xx1;
			x1 = xx2;
		} else {
			x2 = xx2;
			x1 = xx1;
		}
		if(yy1>yy2) {
			y2 = yy1;
			y1 = yy2;
		} else {
			y2 = yy2;
			y1 = yy1;
		}
	}
	bool contains(float x,float y) {
		return (x>x1 && x<x2 && y>y1 && y<y2);
	}
};

int rectangles = 0;
Rectangle rectangle[10];

int main(int argc, char **argv) {

	char linha[51];
	float x,y;
	float x2,y2;

	while(true) {
	
		cin.getline(linha,51);
	
		if(linha[0]=='r') {
			sscanf(linha, "r %f %f %f %f", &x,&y,&x2,&y2);
			rectangle[rectangles].set(x,y,x2,y2);
			rectangles++;
		} else if(linha[0]=='*') {
			break;
		}
		
	}

	int p = 1;
	int i = 0;
	x2 = 9999.9;
	while(true) {
	
		cin.getline(linha,51);
		sscanf(linha, "%f %f", &x,&y);
		if(x==x2 && y==x2) break;
		bool found = false;
		for(i=0;i!=rectangles;i++) {
			if(rectangle[i].contains(x,y)) {
				found=true;
				printf("Point %d is contained in figure %d\n",p,i+1);
			}
		}
		if(!found) {
			printf("Point %d is not contained in any figure\n",p);
		}
		p++;
		
	}

	return 0;

}
