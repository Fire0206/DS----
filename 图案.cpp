#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int a=(n-i);a>=1;a--){
		printf(" ");	
	}
		for(int b=1;b<=(2*i-1);b++){
			printf("#");
		}
		printf("\n");
 }
 return 0;
}
