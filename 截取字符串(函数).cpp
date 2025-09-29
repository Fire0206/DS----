#include<stdio.h>
#include<string.h>
int Substring(char str1[],char str2[],int index);
int main(){
	int n,index;
	char str1[100],str2[100];
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		fgets(str1, sizeof(str1), stdin);
        if (str1[strlen(str1) - 1] == '\n') {
            str1[strlen(str1) - 1] = '\0';
        }
        scanf("%d", &index);
        getchar();
		if(Substring(str1,str2,index)==1){
			printf("%s\n",str2);
		}
		else{
			printf("IndexError\n");
		}
	}
	return 0;
}
int Substring(char str1[],char str2[],int index){
	int len=strlen(str1);
	int j=0;
	if(index<0||index>=len){
		return 0;
	}
	else{
		for(j=0;j<(len-index);j++){
			str2[j]=str1[index+j];
		}
		str2[j] = '\0';
    	return 1;
	}
} 
