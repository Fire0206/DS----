#include<stdio.h>
int main()
{
	int N,peach=1;
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		peach=(peach+1)*2;
	}
	printf("%d",peach);
	return 0;
 } 
