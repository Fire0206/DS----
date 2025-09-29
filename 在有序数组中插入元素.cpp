#include<stdio.h>
int main()
{
	int arr[10];
	int i;
	for(i=0;i<9;i++){
		scanf("%d",&arr[i]);
	}
	int num;
	scanf("%d",&num);
	i=8;
	while(i>=0&&arr[i]>num){
		arr[i+1]=arr[i];
		i--;
	}
	arr[i+1]=num;
	for(i=0;i<10;i++){
		printf("%d\n",arr[i]);
	}
	return 0; 
} 
