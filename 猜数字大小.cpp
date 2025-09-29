#include<stdio.h>
#include <stdlib.h>
int main()
{
	int num=rand()%100+1
	int a=0;
	while(1){
		scanf("%d",&a;
		if(a>num){
			printf("太大了"); 
		}
		else if(a<num){
			printf("太小了"); 
		}
		else{printf("正确");
		break;
		}
	}
	return 0;
}
