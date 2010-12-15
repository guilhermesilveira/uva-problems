#include <stdio.h>
#include <math.h>

int main (char **argv, int argc) {

	register int h,m;
	double pos1, pos2;
	
	while(true) {
		
		scanf(" %d:%d",&h,&m);
		if(h==0 && m==0) {
			break;
		}
		
		pos1 = (h % 12) * 30.0 + (m * 0.5);
		pos2 = m * 6.0;
		pos1 -= pos2;
	
		if(pos1 < 0) {
			pos1 *= -1;
		}
		if(pos1 > 180) {
			pos1 = 360 - pos1;
		}
		
		// arredondar
		printf("%.3lf\n",pos1);
		
	}
	
  return 0;

}
