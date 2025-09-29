#include <stdio.h>
#include <math.h>
int main()
{
	float r,area;
	int n;
	scanf("%f,%d",&r,&n);
	area=n*r*r*sin(2*3.1415926/n)/2;
	printf("Area=%.2f",area);
	return 0;
}
