#include<stdio.h>
int main()
{
	int T,n,i,v,j;
	scanf("%d",&T);
	for(int a=1;a<=T;a++){
		scanf("%d",&n);
		for(i=1;i<=((n-1)/2);i++){
			for(v=1;v<i;v++){
				printf(" ");
			}
			for(j=1;j<=(n-2*i+2);j++){
				printf("*");
			}
			printf("\n");
		}
		for(i=1;i<=((n+1)/2);i++){
			for(j=1;j<=((n+1)/2-i);j++){
				printf(" ");
			}
			for(v=0;v<(i*2-1);v++){
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
