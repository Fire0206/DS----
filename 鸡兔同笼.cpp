#include<stdio.h>
int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(a%2!=0||a<=0){
			printf("0 0\n");
		}
		else if(a==2){
			printf("1 1\n");
		}
		else if(a%4==0){
			printf("%d %d\n",a/4,a/2);
		}
		else{
			printf("%d %d\n",(a+2)/4,a/2);
		}
	}
	return 0;
 } 
