#include<stdio.h>
#include<string.h>
void anti(char s[]);
int main()
{
	char s[100];
	scanf("%s",s);
	anti(s);
	printf("%s",s);
	return 0;
}
void anti(char s[]){
	int len=strlen(s);
	int temp;
	for(int i=0;i<(len/2);i++){
		temp=s[i];
		s[i]=s[len-1-i];
		s[len-1-i]=temp;
	}
}
