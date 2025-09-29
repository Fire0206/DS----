#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d/%d/%d",&a,&b,&c);
	d=a+b+c;
	scanf("%d/%d/%d",&a,&b,&c);
	e=a+b+c;
	if((d%2==0 && e%2==0)||(d%2==1 && e%2==1)){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}

