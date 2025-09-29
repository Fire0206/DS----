#include<stdio.h>
int main()
{
	int T,N;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&N);
		int sum=0;
		for(int a=1;a<=N;a++){
			if(a%3!=0&&a%4!=0&&a%7==0){
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
