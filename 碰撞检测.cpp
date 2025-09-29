#include<stdio.h>
int main()
{
	int t;
	int x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d %d %d\n%d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if((x2<x3&&x2<x4)||(x4<x1&&x4<x2)||(y2<y3&&y2<y4)||(y4<y1&&y4<y2)){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
 } 
