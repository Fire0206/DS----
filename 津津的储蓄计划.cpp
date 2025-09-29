#include<stdio.h>
int main()
{
	int monney,X,saving=0,remain=0;
	for(int i=1;i<=12;i++){
		scanf("%d",&monney);
		remain=remain+300-monney;
		if(remain<0){
			printf("-%d",i);
			break;
		}
		saving=saving+(remain/100)*100;
		remain=remain%100;	
	}
	if(remain>=0){
	saving=saving*1.2;
	printf("%d",saving+remain);}
	return 0;
 } 
