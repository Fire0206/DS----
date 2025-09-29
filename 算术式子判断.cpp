#include<stdio.h>
int main()
{
	int a,b,c,result;
	char x;
	scanf("%d%c%d=%d",&a,&x,&b,&c);
	switch(x){
	case '+':
		result=a+b;
		if(result==c) {printf("%d%c%d=%d correct",a,x,b,c);}
		else {printf("%d%c%d=%d wrong",a,x,b,c);}
		break;
	case '-':
		result=a-b;
		if(result==c) {printf("%d%c%d=%d correct",a,x,b,c);}
		else {printf("%d%c%d=%d wrong",a,x,b,c);}
		break;
	case '*':
		result=a*b;
		if(result==c) {printf("%d%c%d=%d correct",a,x,b,c);}
		else {printf("%d%c%d=%d wrong",a,x,b,c);}
		break;
	case '/':
		result=a/b;
		if(result==c) {printf("%d%c%d=%d correct",a,x,b,c);}
		else {printf("%d%c%d=%d wrong",a,x,b,c);}
		break;
	case '%':
		result=a%b;
		if(result==c) {printf("%d%c%d=%d correct",a,x,b,c);}
		else {printf("%d%c%d=%d wrong",a,x,b,c);}
		break;	
	default:printf("%d%c%d=%d error op",a,x,b,c);	
}
return 0;
}
/* ‰»Î  ‰≥ˆ
2+2=4 2+2=4 correct
2+2=0 2+2=0 wrong
3-2=1 3-2=1 correct
3-2=0 3-2=0 wrong
2*2=4 2*2=4 correct
2*2=0 2*2=0 wrong
4/2=2 4/2=2 correct
4/2=1 4/2=1 wrong
4%2=0 4%2=0 correct
4%2=1 4%2=1 wrong
6&7=1 6&7=1 error op
*/
