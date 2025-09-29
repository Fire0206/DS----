#include <stdio.h>
int main()
{
    int a;
	scanf("%d",&a);
	int b=a/100,c=(a%100)/10,d=a%10,e=b+c+d;
	printf("%d",e);
	return 0;
} 
