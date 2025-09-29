#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	e=(c*60+d-a*60-b)/60;
	f=(c*60+d-a*60-b)%60;	
	printf("%d %d",e,f);
	return 0;
}
