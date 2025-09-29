#include<stdio.h>
int main()
{
	int T,A,B,k;
	scanf("%d",&T);
	for(int j=0;j<T;j++){
		int a[100][100];
		scanf("%d %d",&A,&B);
		for(int i=0;i<A;i++){
			for(int k=0;k<B;k++)
			scanf("%d",&a[i][k]);}
		int z=0;
		for(int i=0;i<A;i++){
			int max=a[i][0],num=0;
			for(k=0;k<B;k++)
			if(a[i][k]>max){
				max=a[i][k];
				num=k;
			}
			int y=1;
			for(int v=0;v<A;v++)
			if(a[v][num]<max){
				y=0;
				break;
			}
		if(y){
			printf("%d %d\n",i,num);
			z=1;
			break;
		}
	}
	if(z==0){
		printf("-1\n");
	}
	}
	return 0;
 } 
