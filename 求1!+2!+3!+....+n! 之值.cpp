#include <stdio.h>
int main()
{
	int i=1,n,sum=0,a=1;
	scanf("%d",&n);
	while(i<=n){
		a*=i;
		sum+=a;
		i++;
	}
	printf("%d",sum);
}
