#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int v=0;v<t;v++){
		int n;
		int a[10][10];
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		}
		for(int j=0;j<n;j++){
			int max=a[0][j];
			int num=0,sum=0;
			for(int i=0;i<n;i++){
				if(a[i][j]>max){
					max=a[i][j];
					num=i;
				}
				sum+=a[i][j];
			}
			printf("%d %d\n",a[num][j],sum);
		}
	}
	return 0;
}
