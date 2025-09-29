#include<stdio.h>
int check(int A,int B);
int main()
{
	int t,A,B;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		scanf("%d %d",&A,&B);
		if(check(A,B)==1){
			printf("YES");
		}
		else{
			printf("NO");
		}
		if(j!=t-1){
			printf("\n");
		}
	}
	return 0;
}
int check(int A,int B)
{	
	if(A==B){
		return 0;
	}
	int sum1=0;
	int sum2=0;
	for(int i=1;i<A;i++){
		if(A%i==0){
			sum1+=i;
		}
	}
	for(int i=1;i<B;i++){
		if(B%i==0){
			sum2+=i;
		}
	}
	if((sum1==B)&&(sum2==A)){
		return 1;
	}
	return 0;
} 
