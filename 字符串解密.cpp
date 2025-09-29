#include<stdio.h>
int main()
{
	int n;
	if (scanf("%d", &n)!= 1) {
        return 1;
        } 
	for(int j=0;j<n;j++){
		int k,b;
        if (scanf("%d %d", &k, &b)!= 2) {
            while (getchar()!= '\n');
            j--;
            continue;
        }
        char s[5001];
        while (getchar()!= '\n');
        if (scanf("%[^\n]", s)!= 1) {
            j--;
            continue;
        }
        while (getchar()!= '\n');
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
		printf("%s",s);
		if(j!=n-1){
			printf("\n");
		}
	}
	return 0;
}
