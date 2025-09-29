#include<stdio.h>
int main()
{
	int a[6];
	int b[8];
	int i;
	for(i=0;i<6;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<8;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<8;i++){
		for(int j=0;j<6;j++){
			if(a[j]==b[i]){
				printf("%d\n",b[i]);
			}
		}
	}
	return 0;	
 } 
