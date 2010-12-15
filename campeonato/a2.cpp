#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>

#define FOR(a,b) for(a=0;a<b;a++)
#define FOR3(a,b,c) for(a=b;a<c;a++)

using namespace std;


#include <stdio.h>

#define	MAXDIGITS	100		/* maximum length bignum */ 

#define PLUS		1		/* positive sign bit */
#define MINUS		-1		/* negative sign bit */

typedef struct {
        char digits[MAXDIGITS];         /* represent the number */
	int signbit;			/* 1 if positive, -1 if negative */ 
        int lastdigit;			/* index of high-order digit */
} bignum;
void zero_justify(bignum *n);
int compare_bignum(bignum *a, bignum *b);

   bignum copia(const bignum &c) {
   	bignum n;
   	n.lastdigit=c.lastdigit;
   	n.signbit=c.signbit;
   	for(int i=0;i!=MAXDIGITS;i++) n.digits[i]=c.digits[i];
   	return n;
   }

void print_bignum(bignum *n)
{
	int i;

	if (n->signbit == MINUS) printf("- ");
	for (i=n->lastdigit; i>=0; i--)
		printf("%c",'0'+ n->digits[i]);
}

void s_to_bignum(char *s, bignum *n)
{
	int i;				/* counter */
	int t;				/* int to work with */
	
	n->signbit = PLUS;

	for (i=0; i<MAXDIGITS; i++) n->digits[i] = (char) 0;

	int l = strlen(s);
	for(i=l-1;i>=0;i--)n->digits[i] = s[l-i-1]-'0';

	n->lastdigit = l-1;

}

void int_to_bignum(int s, bignum *n)
{
	int i;				/* counter */
	int t;				/* int to work with */

	if (s >= 0) n->signbit = PLUS;
	else n->signbit = MINUS;

	for (i=0; i<MAXDIGITS; i++) n->digits[i] = (char) 0;

	n->lastdigit = -1;

	t = abs(s);

	while (t > 0) {
		n->lastdigit ++;
		n->digits[ n->lastdigit ] = (t % 10);
		t = t / 10;
	}

	if (s == 0) n->lastdigit = 0;
}

void initialize_bignum(bignum *n)
{
	int_to_bignum(0,n);
}


int max(int a, int b)
{
	if (a > b) return(a); else return(b);
}

/*	c = a +-/* b;	*/

void subtract_bignum(bignum *a, bignum *b, bignum *c);

void add_bignum(bignum *a, bignum *b, bignum *c)
{
	int carry;			/* carry digit */
	int i;				/* counter */

	initialize_bignum(c);

	if (a->signbit == b->signbit) c->signbit = a->signbit;
	else {
		if (a->signbit == MINUS) {
			a->signbit = PLUS;
			subtract_bignum(b,a,c);
			a->signbit = MINUS;
		} else {
                        b->signbit = PLUS;
                        subtract_bignum(a,b,c);
                        b->signbit = MINUS;
		}
		return;
	}

	c->lastdigit = max(a->lastdigit,b->lastdigit)+1;
	carry = 0;

	for (i=0; i<=(c->lastdigit); i++) {
		c->digits[i] = (char) (carry+a->digits[i]+b->digits[i]) % 10;
		carry = (carry + a->digits[i] + b->digits[i]) / 10;
	}

	zero_justify(c);
}


void subtract_bignum(bignum *a, bignum *b, bignum *c)
{
	int borrow;			/* has anything been borrowed? */
	int v;				/* placeholder digit */
	int i;				/* counter */

	if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
                b->signbit = -1 * b->signbit;
                add_bignum(a,b,c);
                b->signbit = -1 * b->signbit;
		return;
        }

	if (compare_bignum(a,b) == PLUS) {
		subtract_bignum(b,a,c);
		c->signbit = MINUS;
		return;
	}

        c->lastdigit = max(a->lastdigit,b->lastdigit);
        borrow = 0;

        for (i=0; i<=(c->lastdigit); i++) {
		v = (a->digits[i] - borrow - b->digits[i]);
		if (a->digits[i] > 0)
			borrow = 0;
		if (v < 0) {
			v = v + 10;
			borrow = 1;
		}

                c->digits[i] = (char) v % 10;
        }

	zero_justify(c);
}

int compare_bignum(bignum *a, bignum *b)
{
	int i;				/* counter */

	if ((a->signbit == MINUS) && (b->signbit == PLUS)) return(PLUS);
	if ((a->signbit == PLUS) && (b->signbit == MINUS)) return(MINUS);

	if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);
	if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);

	for (i = a->lastdigit; i>=0; i--) {
		if (a->digits[i] > b->digits[i]) return(MINUS * a->signbit);
		if (b->digits[i] > a->digits[i]) return(PLUS * a->signbit);
	}

	return(0);
}

void zero_justify(bignum *n)
{
	while ((n->lastdigit > 0) && (n->digits[ n->lastdigit ] == 0))
		n->lastdigit --;

        if ((n->lastdigit == 0) && (n->digits[0] == 0))
		n->signbit = PLUS;	/* hack to avoid -0 */
}


void digit_shift(bignum *n, int d)		/* multiply n by 10^d */
{
	int i;				/* counter */

	if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;

	for (i=n->lastdigit; i>=0; i--)
		n->digits[i+d] = n->digits[i];

	for (i=0; i<d; i++) n->digits[i] = 0;

	n->lastdigit = n->lastdigit + d;
}



void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
	bignum row;			/* represent shifted row */
	bignum tmp;			/* placeholder bignum */
	int i,j;			/* counters */

	initialize_bignum(c);

	row = *a;

	for (i=0; i<=b->lastdigit; i++) {
		for (j=1; j<=b->digits[i]; j++) {
			add_bignum(c,&row,&tmp);
			*c = tmp;
		}
		digit_shift(&row,1);
	}

	c->signbit = a->signbit * b->signbit;

	zero_justify(c);
}


void divide_bignum(bignum *a, bignum *b, bignum *c)
{
        bignum row;                     /* represent shifted row */
        bignum tmp;                     /* placeholder bignum */
	int asign, bsign;		/* temporary signs */
        int i,j;                        /* counters */

	initialize_bignum(c);

	c->signbit = a->signbit * b->signbit;

	asign = a->signbit;
	bsign = b->signbit;

	a->signbit = PLUS;
        b->signbit = PLUS;

	initialize_bignum(&row);
	initialize_bignum(&tmp);

	c->lastdigit = a->lastdigit;

	for (i=a->lastdigit; i>=0; i--) {
		digit_shift(&row,1);
		row.digits[0] = a->digits[i];
		c->digits[i] = 0;
		while (compare_bignum(&row,b) != PLUS) {
			c->digits[i] ++;
			subtract_bignum(&row,b,&tmp);
			row = tmp;
		}
	}

	zero_justify(c);

	a->signbit = asign;
	b->signbit = bsign;
}



char s1[100],s2[10],s3[100];
char v1[100],v2[100];


bignum zero;
bignum temp,temp2;
void resto(bignum *a,bignum *b,bignum *r) {
	divide_bignum(a,b,&temp);
//	print_bignum(&temp);cout << endl;
	multiply_bignum(b,&temp,&temp2);
	subtract_bignum(a,&temp2,r);	
}

bignum *gcd(bignum *a,bignum *b)
{
    bignum *r = new bignum();
    initialize_bignum(r);
    
    while(compare_bignum(&zero,b)!=0){
    	resto(a,b,r);
//    	print_bignum(r);cout << endl;
    	a = b;
    	b = r;
    }
    
    return a;
    
}

void st() {
	cin >> s1 >> s2 >> s3;
	int l = strlen(s1);
	int i;
	
	//cout << s1 << " e " << s3 << endl;
	
	bignum n1,n2,n3,n4;
	int_to_bignum(0,&zero);
	s_to_bignum(s1,&n1);
	s_to_bignum(s3,&n2);

	bignum t1 = copia(n1), t2 = copia(n2);
	if(compare_bignum(&t1,&t2)<0) swap(t1,t2);
/*	cout << "t1: "; print_bignum(&t1);
	cout << endl;
	cout << "t2: "; print_bignum(&t2);
	cout << endl;*/
	
	bignum *val = gcd(&t2,&t1);
//	cout << "result: "; print_bignum(val);
	//cout << endl;

	divide_bignum(&n1,val,&n4);
	print_bignum(&n4);
	cout << " / ";
	divide_bignum(&n2,val,&n4);
	print_bignum(&n4);
	cout << endl;
}

int main() {

	int t; cin >> t;
	while(t--)st();
return 0;
}
