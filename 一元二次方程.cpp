#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	float e,f;
	scanf("%d %d %d",&a,&b,&c);
	d=b*b-4*a*c;
	e=(-b+sqrt(d))/(2*a);
	f=(-b-sqrt(d))/(2*a); 
	printf("x1=%.2f x2=%.2f",e,f);
	return 0;
}
