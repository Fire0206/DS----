#include <stdio.h>
int main()
{
	int a,b,c,V,S;
	scanf("%d%d%d",&a,&b,&c);
	V=a*b*c,S=2*(a*b+b*c+a*c);
	printf("V=%d\nS=%d",V,S);
	return 0;
 } 
