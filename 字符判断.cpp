#include<stdio.h>
int main()
{
	char a;
	scanf("%c",&a);
	if(a>='A'&&a<='Z'){
		printf("upper");
	}
	else if(a>='a'&&a<='z'){
		printf("lower");
	}
	else if(a>='1'&&a<='9'){
		printf("digit");
	}
	else{
		printf("others");
	}
	return 0;
 } 
