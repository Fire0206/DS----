#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a>=100&&a<=999){
		int b,c,d;
		b=a/100,c=(a%100)/10,d=a%10;
		if(a==b*b*b+c*c*c+d*d*d){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else{
		printf("ERROR");
	}
	return 0;
}
