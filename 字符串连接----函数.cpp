#include<stdio.h>
#include<string.h>
void add(char a[],char b[]);
int main(){
	char a[1000];
	char b[1000];
	fgets(a, sizeof(a), stdin);
    if (a[strlen(a) - 1] == '\n') {
        a[strlen(a) - 1] = '\0';
    }
    fgets(b, sizeof(b), stdin);
    if (b[strlen(b) - 1] == '\n') {
        b[strlen(b) - 1] = '\0';
    }
	add(a,b);
	printf("%s",a);
	return 0;
}
void add(char a[],char b[]){
	int len=strlen(a);
	int i;
	for(i=0;b[i]!='\0';i++){
		a[len+i]=b[i];
	}
	a[len+i+1]='\0';
}
