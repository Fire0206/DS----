#include<stdio.h>
void move(int str[],int n,int m);
int main(){
	int n,m;
	scanf("%d",&n);
	int str[n];
	for(int i=0;i<n;i++){
		scanf("%d",&str[i]);
	}
	scanf("%d",&m);
	move(str,n,m);
	for(int i=0;i<n;i++){
		printf("%d ",str[i]);
	}
	return 0;
}
void move(int str[],int n,int m){
	int temp[n];
    for(int i=0;i<n;i++){
        temp[(i+m)%n]=str[i];
    }
    for(int i=0;i<n;i++) {
        str[i]=temp[i];
	}
}
