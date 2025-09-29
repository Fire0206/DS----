#include<stdio.h>
#include<string.h>
int isPalindrome(char s[]);
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	for(int j=0;j<t;j++){
		char str[1000];
		fgets(str, sizeof(str), stdin);
		if (str[strlen(str) - 1] == '\n') {
    	str[strlen(str) - 1] = '\0';
		}
		if(isPalindrome(str)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
int isPalindrome(char s[])
{
	int length=strlen(s);
	for(int i=0;i<length/2;i++){
		if(s[i]!=s[length-i-1]){
			return 0;
		} 
	}
	return 1;
}
