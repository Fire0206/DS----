#include<stdio.h>
#include<math.h>
int main()
{
	int T,n,m;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d %d",&n,&m);
		int sum=0;
		for(int j=n;j<=m;j++){
			int a=1;
			if(j==2){printf("2 ");sum+=2;a=0;
			}
			if(j==1||j==0){a=0;
			}
			else if(j%2!=0){
			for(int v=2;v<=(sqrt(j));v++){
			if(j%v==0){
			a=0;	
			break;}
		}
		if(a){
			sum+=j;
			printf("%d ",j);
		}
		}
		}
		if(sum==0){
			printf("NO\n");
		}
		else{
		printf("\n%d\n",sum);}
	}
	return 0;
 } 
