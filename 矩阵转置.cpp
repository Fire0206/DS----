#include<stdio.h>
int main()
{
	int n,m;
	int a[10][10];
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++)
		scanf("%d",&a[i][k]);}
	for(int k=0;k<n;k++){
		for(int i=0;i<m;i++){
		printf("%d",a[i][k]);
		if(i!=(m-1)){
			printf(" ");
		}
		}
		printf("\n");
	}
	return 0;
}
