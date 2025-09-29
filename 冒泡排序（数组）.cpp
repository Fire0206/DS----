#include<stdio.h>
int main()
{
	int T,i,n;
	scanf("%d",&T);
	for(int j=0;j<T;j++){
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(i=0;i<(n-1);i++){
			for(int a=0;a<(n-i-1);a++){
				if(arr[a]>arr[a+1]){
					int temp=arr[a];
					arr[a]=arr[a+1];
					arr[a+1]=temp;
				}
			}
			for(int t=0;t<n;t++){
				printf("%d",arr[t]);
				if(t!=(n-1)){
					printf(" ");
				}
			}
			if(j!=(T-1)||i!=(n-2)){
				printf("\n");
			}
		}	
	}
	return 0;
 } 
