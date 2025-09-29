#include<stdio.h>
int main()
{
	int a,b,r;
	char c;
	scanf("%d %d %c",&a,&b,&c);
	if(c=='+'){r=a+b;	printf("%d",r);
	}
	else if(c=='-'){r=a-b;	printf("%d",r);
	}
	else if(c=='*'){r=a*b;	printf("%d",r);
	}
	else if(c=='/'){
		if(b==0){
			printf("Divided by zero!");
		}
		else{r=a/b;
		}
	}
	else{
		printf("Invalid operator!");
	}

	return 0;
 } 
