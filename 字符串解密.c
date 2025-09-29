#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		int k,b;
		scanf("%d %d",&k,&b);
		char s[5001];
		scanf("%d",&s);
		for(int i=0;i<5000&&s[i]!='\0';i++){
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
			 	int x;
			 	if(s[i]>='a'&&s[i]<='z'){
			 		x=s[i]-'a';
				}else{
					x=s[i]-'A';
				}
				int y=(k*x+b)%26;
				if(s[i]>='a'&&s[i]<='z'){
					s[i]=y+'a';
				}else{
					s[i]=y+'A';
				}
			}
		}
		printf("%s\n",s);
	}
	return 0;
}
