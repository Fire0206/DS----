#include<stdio.h>
#include<string.h>
int check(char str1[],char str2[]);
int main(){
	char str1[12];
	char str2[7];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str1);
		if(check(str1,str2)){
			printf("%s",str2);
		}
		else{
			printf("error");
		}
		if(i!=n-1){
			printf("\n"); 
		}
	}
	return 0;
}
int check(char str1[],char str2[])
{	
	if (strlen(str1)!= 11) {
        return 0;
    }
	char *legal[18]={"133","153","180","181","189","130","131","132","155","156","134","135","136","137","138","182","183","184"};

	char prefix[4];
    strncpy(prefix, str1, 3);
    prefix[3] = '\0';
    for (int i = 0; i < 18; i++) {
        if (strcmp(prefix, legal[i]) == 0) {
            str2[0]='6';
            for(int j=1;j<6;j++){
            	str2[j]=str1[j+5];
			}
			return 1;
		}
	}
	return 0;
}
