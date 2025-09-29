#include<stdio.h>
void cin(int arr[],int N);
void cout(int arr[],int N);
int main()
{
	int t,N;
	scanf("%d",&t);
	for(int j=0;j<t;j++){
		scanf("%d",&N);
		int arr[N];
		cin(arr,N);
		for(int i=0;i<N-1;i++){
			for(int m=0;m<N-i-1;m++){
				if(arr[m]>arr[m+1]){
					int temp=arr[m];
					arr[m]=arr[m+1];
					arr[m+1]=temp;
				}
			}
			if(i==0){
			cout(arr,N);}
		}
		cout(arr,N);
	}
	return 0;
}
void cin(int arr[],int N)
{
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
}
void cout(int arr[],int N)
{
	for(int i=0;i<N;i++){
		printf("%d",arr[i]);
		if(i!=N-1){
			printf(" ");
		}
	}
	printf("\n");	
}
