#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,delt,x1,x2,d,e;
	scanf("%f %f %f",&a,&b,&c);
	delt=b*b-4*a*c;
	if(a==0){x1=-b/c;printf("x=%.3f",x1); 
	}
	else{
	switch(delt>=0){
	case 1:
		x1=(-b+sqrt(delt))/(2*a);
		x2=(-b-sqrt(delt))/(2*a);
		printf("x1=%.3f x2=%.3f",x1,x2);break;

	case 0:
		d=-b/2/a;
		e=sqrt(-delt)/(2*a);
		printf("x1=%.3f+%.3fi x2=%.3f-%.3fi",d,e,d,e);break;
			}}
	return 0;
 } 
/* ‰»Î  ‰≥ˆ
4 1 1 x1=-0.125+0.484i x2=-0.125-0.484i
1 2 1 x1=-1.000 x2=-1.000
1 3 1 x1=-0.382 x2=-2.618*/ 
