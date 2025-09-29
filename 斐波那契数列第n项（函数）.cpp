#include<stdio.h>
int add(int a,int b);
int main()
{
	int n,c;
	int a=0,b=1;
	scanf("%d",&n);
	for(int i=0;i<(n-1);i++){
		c=add(a,b);
		a=b;
		b=c;
	}
	printf("%d",b);
	return 0;
}
int add(int a,int b)
{
	int c=a+b;
	return c;
}

int fibonacci(int n)
{
	int a=0,b=1,c=0;
	for(int i=1;i<n-2;i++)
	{
		c=add(a,b);
		a=b;
		b=c;
	}
	return c;
}
