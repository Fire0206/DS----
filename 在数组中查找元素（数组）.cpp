#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++){
		int arr[10];
		for(int i=0;i<10;i++){
			scanf("%d",&arr[i]);
		}
		int a;
		scanf("%d",&a);
		int found=0;
		for(int i=0;i<10;i++){
			if(arr[i]==a){
				printf("%d\n",i);
				found=1;
				break;
			}
		}
			if(found==0){
				printf("Not found\n");
			}
	}
	return 0;	
}


