#include<stdio.h>
int main()
{
	int n;
	double h;
	scanf("%lf %d",&h,&n);
	double x=h,y=h;
	for(int i=1;i<n;i++){
	y/=2;
	y=(int)((y*1000+5)/10) / 100.0;
	x+=y*2;
	x=(int)((x*1000+5)/10) / 100.0; 
	}
	y/=2;
	y=(int)((y*1000+5)/10) / 100.0;
	printf("%.2lf\n%.2lf",x,y);
	return 0;
 } 
