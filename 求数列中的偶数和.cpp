#include<stdio.h>
int main()
{
	int n,num,sum=0,i=0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d",&num);
		if(num%2==0){
			sum+=num;
		}
		i++;
	}
	printf("%d",sum);
	return 0;
 } 
