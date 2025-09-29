#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int dimension;
		int a[10][10];
		scanf("%d",&dimension);
		for(int i=0;i<dimension;i++){
			for(int k=0;k<dimension;k++)
			scanf("%d",&a[i][k]);}
		int sum=0;
		for(int i=0;i<dimension;i++){
			sum+=a[i][i];}
		printf("%d\n",sum);		
	}
	return 0;
 } 
