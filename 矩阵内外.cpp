#include<stdio.h>
int main()
{
	int x,y,a,b,c,d;
	scanf("%d  %d\n%d  %d\n%d  %d",&a,&b,&c,&d,&x,&y);
	if(x>=a&&x<=c&&y>=d&&y<=b){
		printf("IN");
	}
	else{
		printf("OUT");
	}
	return 0;
 } 
