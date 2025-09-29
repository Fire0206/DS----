#include<stdio.h>
int judge(int x,int y);
int main()
{
	int n,x,y;;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		if(judge(x,y)==1){
			printf("in\n");
		}
		else{
			printf("out\n");
		}	
	}
	return 0;
}
int judge(int x,int y){
	if((x>=1&&x<=5)&&(y>=1&&y<=5)){
		return 1;
	}
	return -1;
}
