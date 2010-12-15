#include <stdio.h>
#include <math.h>

#ifndef PI
	#define PI	(2*acos(0))
#endif

int main (char **argv, int argc) {
	
	double r;
	double n;
	double alpha;
	
	while((scanf(" %lf %d",&r,&n))==2) {
		
		alpha = (180 / n) * PI / 180;
		printf("%.3lf\n", sin(alpha) * r * cos(alpha) * r * n);
		
	}


  return 0;

}
