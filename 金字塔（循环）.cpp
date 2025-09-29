#include<stdio.h>
int main()
{
	char c;
	int n,t;
	scanf("%d",&t);
	for(int m=0;m<t;m++){
		scanf("%d %c",&n,&c);
		for(int i=1;i<=n;i++){
			for(int j=0;j<2*(n-i);j++){
				printf(" ");	
			}
			for(int j=0;j<i*2-1;j++){
				printf("%c",c);
			}
			printf("\n");
		}
		if(m!=t-1){
			printf("\n");
		}
	}
	return 0;
}
