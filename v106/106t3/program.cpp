



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int primos[33010], nprimos;
int lista[3000][5], tam[1000], tot;

void eh(int n) {
  int i;
  for (i = 0; primos[i]*primos[i] <= n; i++)
    if (n%primos[i] == 0)
      return;
  primos[nprimos++] = n;
  return;
}



int main() {
  int i,j,k,l,m,n,x,y;

  primos[0] = 2;
  nprimos = 1;
  for (i = 3; i <= 33000; i+=2)
    eh(i);

  while(1) {
    scanf("%d %d",&x, &y);
    if (x == 0 && y == 0)
      break;
    if (x > y) {
      k = x;
      x = y;
      y = k;
    }
    i = 0;
    while(primos[i] < x) i++;
    if (primos[i]-primos[i-1] == primos[i+1]-primos[i])
      i++;
    for (; primos[i+2] <= y; i++) {
      if (primos[i+1]-primos[i] == primos[i+2]-primos[i+1]) {
		k = i;
		i += 2;
		while(primos[i+1]-primos[i] == primos[i]-primos[i-1]) i++;
		if (primos[i] > y)
		  break;
		printf("%d",primos[k]);
		for (k++; k <= i; k++)
		  printf(" %d",primos[k]);
		putchar('\n');
      }
    }
  }

  return 0;
}
