#include<stdio.h>
int main()
{
	char a;
	int letters=0,numbers=0,spaces=0,others=0;
	while( (a=getchar())!='\n'){
	if(a==' '){
		spaces++;
	}
	else if((a>='A'&&a<='Z')||(a>='a'&&a<='z')){
		letters++;
	}
	else if(a>='0'&&a<='9'){
		numbers++;
	}
	else{others++;
	}
	}
	printf("%d %d %d %d",letters,numbers,spaces,others);
	return 0;
}
