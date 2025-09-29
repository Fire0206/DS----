#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==0||n>=30){
        return 1;
    }
	int a[30][30];
	memset(a,0,sizeof(a)); 
	a[0][(n-1)/2]=1;
	int m=1,b=(n+1)/2;
	for(int i=2;i<n*n+1;i++){
		if(m==1&&b!=n){
			m=n;
			b+=1;
			a[m-1][b-1]=i;
			continue;
		}
		else if(b==n&&m!=1){
			b=1;
			m-=1;
			a[m-1][b-1]=i;
			continue;
		}
		else if(m==1&&b==n){
			m+=1;
			a[m-1][b-1]=i;
			continue;
		}
		else if(m!=1&&b!=n){
			if(a[m-2][b]==0){
				m-=1;
				b+=1;
				a[m-1][b-1]=i;
			}
			else{
				m+=1;
				a[m-1][b-1]=i;
			}
			continue;
		}
	}
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			printf("%d",a[i][k]);
			if(k!=(n-1)){
				printf(" ");
			}
		}
		if(i!=n-1){
		printf("\n");
		}
	}	
	return 0;
 } 
