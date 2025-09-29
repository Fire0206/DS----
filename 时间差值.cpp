#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	scanf("%d:%d:%d\n%d:%d:%d",&a,&b,&c,&d,&e,&f);
	g=a*3600+b*60+c-d*3600-e*60-f,h=g/3600,i=(g%3600)/60,j=g%60;
	printf("%d:%d:%d",h,i,j);
	return 0;
 } 
