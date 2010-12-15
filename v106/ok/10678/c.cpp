#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <math.h>

using namespace std;

double pi = 2 * (acos(0.0));

void start() {

	double d, l;
	cin >> d >> l;
	double a  = l/2;
	double alpha = acos(d / l);
	double b = (l/2) * sin(alpha);
	b = sqrt((l * l - d * d) / 4);
	printf("%.3lf\n",pi * a * b);
	return;
	assert(false);

}

int main() {

	int t;
	cin >> t;
	while(t--) start();
	return 0;

}
