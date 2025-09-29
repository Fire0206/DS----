#include<stdio.h>
int main()
{
	int a,b,c,max,mid,min;
	scanf("%d %d %d",&a,&b,&c);
	max=a,mid=b,min=c;
	if(a>b&&a>c){
		if(b>c){mid=b;
		}
		else{min=b,mid=c;
		}
	}
	else if(b>a&&b>c){max=b;
		if(a>c){mid=a;
		}
		else{min=a,mid=c;
		}
	}
	else{max=c;
		if(a>b){min=b,mid=a;
		}
		else{min=a,mid=b;
		}
	}
	printf("%d %d %d",min,mid,max);
	return 0;
 } 
