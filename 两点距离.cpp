#include<stdio.h>
#include<math.h>
int main()
{
	int x1,x2,y1,y2;
	float D;
	scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
	D=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	printf("%.2f",D);
	return 0;
}
