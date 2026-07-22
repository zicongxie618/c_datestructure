#include <stdio.h>
#include <stdlib.h>
typedef struct{
int numerator;  
int denominator; 
}RatNum;
RatNum create(int a,int b){
	if(b==0){
		printf("Error");
		exit(1);
	}
	RatNum c;
	c.numerator=a;
	c.denominator=b;
	return c;
}
int gcd(int m, int n)
{
    m = abs(m);
    n = abs(n);
    while(n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}
void reduce(RatNum *a){
	int g=gcd(abs(a->denominator),abs(a->numerator));
	a->denominator=a->denominator/g;
	a->numerator=a->numerator/g;
}
RatNum plus(RatNum *a,RatNum *b){
	RatNum c;
	c.denominator=a->denominator*b->denominator;
	c.numerator=a->denominator*b->numerator+a->numerator*b->denominator;
	reduce(&c);
	return c;
}
RatNum sub(RatNum *a,RatNum *b){
	RatNum c;
	c.denominator=a->denominator*b->denominator;
	c.numerator=a->numerator*b->denominator-a->denominator*b->numerator;
	reduce(&c);
	return c;
}
RatNum mult(RatNum *a,RatNum *b){
	RatNum c;
	c.denominator=a->denominator*b->denominator;
	c.numerator=a->numerator*b->numerator;
	reduce(&c);
	return c;
}
RatNum divide(RatNum *a,RatNum *b){
	RatNum c;
	c.denominator=a->denominator*b->numerator;
	c.numerator=a->numerator*b->denominator;
	reduce(&c);
	return c;
}
void Print(RatNum *a){
	if(a->numerator==0){printf("the result is 0");
	}
	else if(a->denominator==1){printf("the result is %d",a->numerator);
	}
	else{printf("the result is %d/%d",a->numerator,a->denominator);
	}
    printf("\n"); 
}
int main(int argc, char *argv[]) {
	int a,b;
	RatNum c,d,p,s,m,di;
	printf("please input a,b as numerator and denominator:\n");
	scanf("%d %d",&a,&b);
	c=create(a,b);
	printf("please input a,b as new numerator and denominator:\n");
	scanf("%d %d",&a,&b);
	d=create(a,b);
	p=plus(&c,&d);
	printf("plus:");
	Print(&p);
	s=sub(&c,&d);
	printf("sub:");
	Print(&s);
	m=mult(&c,&d);
	printf("mult:");
	Print(&m);
	di=divide(&c,&d);
	printf("div:");
	Print(&di);
	return 0;
}
