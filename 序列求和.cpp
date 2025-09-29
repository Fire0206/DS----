#include<stdio.h>
int main()
{
	int N,c;
	float sum=0,a=1,b=2;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		sum+=b/a;
		c=b;
		b+=a;
		a=c;
	}
	printf("%.2f",sum);
	return 0;
 } 
 
