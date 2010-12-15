#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Rectangle {
public:
    int x1, x2, y1, y2;
    Rectangle(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    bool contains(int x, int y) {
        return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
    }
};

Rectangle *rectangle[25];
int icon[50][3];
double dist[50];
int icons = 0;
int rectangles = 0;
bool comecou = false;
char c[205];

double distancia(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + 0.0);
}

bool instancia() {

    //fgets(c, 200, stdin);
    cin.getline(c, 200);
//    cout << c << endl;
    if(c[0]=='#') return false;

    if (c[0] == 'I') {

		sscanf(c,"I %d %d",&icon[icons][0],&icon[icons][1]);
        icon[icons][2] = 0;
        icons++;

    } else if (c[0] == 'R') {

		int a,b,cc,d;
		sscanf(c,"R %d %d %d %d",&a,&b,&cc,&d);
        Rectangle *r = new Rectangle(a,b,cc,d);
        rectangle[rectangles] = r;
        rectangles++;

    } else if (c[0] == 'M') {

        if (!comecou) {

            for (int i = 0; i != icons; i++) {
                for (int i2 = 0; i2 != rectangles; i2++) {
                    if (rectangle[i2]->contains(icon[i][0], icon[i][1])) {
                        icon[i][2] = -1;
                        break;
                    }
                }
            }

        }

        int x, y;
		sscanf(c,"M %d %d",&x,&y);
		
        bool contains = false;
        for (int i2 = rectangles - 1; i2 >= 0; i2--) {
            if (rectangle[i2]->contains(x, y)) {
                cout << "" << ((char) (i2 + 'A')) << endl;
                contains = true;
                break;
            }
        }
        if (!contains) {
            // testa os icones
           // cout << "mouse at " << x << "," << y << endl;
            double minDist = 99999999;
            for (int i = 0; i != icons; i++) {
                if (icon[i][2] == 0) {
                    // se o icone esta ativo, ve se eh menor que minDist
                    if ((dist[i] = distancia(icon[i][0], icon[i][1], x, y)) < minDist) {
                        minDist = dist[i];
                    }
                }
            }
            for (int i = 1; i != icons + 1; i++) {
                if (icon[i - 1][2] == 0) {
                    if (dist[i - 1] == minDist) {
                        if (i < 10) {
                            cout << "  " << i;
                        } else {
                            cout << " " << i;
                        }
                    }
                }
            }
			cout << endl;
        }

    }

    return true;

}

int main() {
    while (instancia()) {
    }
}

