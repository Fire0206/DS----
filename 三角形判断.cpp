#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	float a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	if(a+b<=c||b+c<=a||a+c<=b){
		x=1;
	}
	else if(fabs(a-b)<0.001||fabs(a-c)<0.001||fabs(b-c)<0.001){
		if(fabs(a-b)<0.001&&fabs(a-c)<0.001&&fabs(b-c)<0.001){x=2;}
		else if(fabs(a*a+b*b-c*c)<0.001||fabs(a*a+c*c-b*b)<0.001||fabs(b*b+c*c-a*a)<0.001){x=3;}
		else {x=4;}
	}
	else {x=5;
	}
	switch(x){
		case(1):printf("非三角形");break;
		case(2):printf("等边三角形");break;
		case(3):printf("等腰直角三角形");break;
		case(4):printf("等腰三角形");break;
		case(5):printf("普通三角形");break;
	}
	return 0;
 } 
/*输入 输出
2 3 4  普通三角形
3 3 3  等边三角形
1 1 1.414  等腰直角三角形
3 3 4  等腰三角形
1 1 2  非三角形
*/
