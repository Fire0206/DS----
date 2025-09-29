#include<stdio.h>
int main()
{
	int a,b,c,x=1,y=1,z=1,sum1=0,sum2=0;
	float sum3=0,sum=0;
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=a;i++){
		sum1+=i;
	}
	for(int i=1;i<=b;i++){
		sum2+=i*i;
	}
	for(int i=1;i<=c;i++){
		sum3+=1.0/i;
	}
	sum=sum1+sum2+sum3;
	printf("%.2f",sum);
	return 0;
}
