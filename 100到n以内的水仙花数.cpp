#include<stdio.h>
int main(){
	int n,num=100,a=0,b=0,c=0;
	scanf("%d",&n);
	do{
		a=num/100,b=(num%100)/10,c=num%10;
		if(num==a*a*a+b*b*b+c*c*c){
			printf("%d\n",num);
		}
		num++;
	}while(num<=n);
	return 0;
}

 
