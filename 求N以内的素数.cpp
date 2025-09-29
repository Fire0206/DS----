#include<stdio.h>
#include<math.h>
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=2;i<=N;i++){
		if(i==2){
			printf("2\n");
		}
		else if(i%2!=0){
			int a=1;
		for(int j=2;j<=(sqrt(i));j++){
			if(i%j==0){
			a=0;	
			break;}
		}
		if(a){
			printf("%d\n",i);
		}
		}
	}
	return 0;
 } 
