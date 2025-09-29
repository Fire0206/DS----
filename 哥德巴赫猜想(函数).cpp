#include<stdio.h>
#include<math.h>
int isPrime(int x);
int main()
{
	int x;
	int num=0;
	scanf("%d",&x);
	for(int i=2;i<=x/2;i++){
		if(isPrime(i)&&isPrime(x-i)){
			num++;
		}
	}
	printf("%d",num);
	return 0;
}
int isPrime(int x){
	if(x<2){
		return 0;
	}
	if(x==2){
		return 1;
	}
	if(x%2==0){
		return 0;
	}
	for(int j=3;j<=sqrt(x);j+=2){
		if(x%j==0){
			return 0;
		}
	}
	return 1;
}
