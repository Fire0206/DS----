#include<stdio.h>
int main()
{
	char a,max='z';
	while((a=getchar())!='\n'){
		if(a<max){
			max=a;
		}
	}
	printf("%c",max);
	return 0;
 } 
