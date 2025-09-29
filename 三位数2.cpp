#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d",&a);
	b=a%100,c=a%10,d=a/100,e=b/10,f=c*100+e*10+d;
	printf("%d",f);
	return 0;
 } 
