#include<stdio.h>
int main()
{
	int a,n;
	int sum=0;
	scanf("%d %d",&a,&n);
	int temp=a;
	for(int i=1;i<=n;i++){ 
		sum+=a;
		temp*=10;
		a+=temp;
	}
	printf("%d",sum);
	return 0;
}
