#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,k;
	scanf("%d",&n);
	int a[n][n],b[n][n],c[n][n];
	char x[20];
	for(i=0;i<n;i++){
		for(k=0;k<n;k++)
		scanf("%d",&a[i][k]);}
	while(1){
	scanf("%s",x);
	if (strcmp(x,"TRANSLATE")==0){
	for(i=0;i<n;i++){
		for(k=0;k<i;k++){
		int temp=a[i][k];
		a[i][k]=a[k][i];
		a[k][i]=temp;}
	}
	}
 	else if(strcmp(x,"ADD")==0){
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		scanf("%d", &b[i][k]);}
	}
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		a[i][k]+=b[i][k];}
	}
	}
	else if(strcmp(x, "MULTIPLY") ==0){
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		scanf("%d", &b[i][k]);}
	}
	memset(c,0,sizeof(c));
	for (i=0;i<n;i++){
		for(k=0;k<n;k++)
			for(int j=0;j<n;j++)
			c[i][k]+=a[i][j]*b[j][k];
		}
	memcpy(a, c, sizeof(a));
	}
	else if(strcmp(x, "SUM") ==0){
	int sum=0;
	for(i=0; i<n; i++){
	sum+=a[i][i];
	if(i!=n-i-1){
	sum+=a[i][n-i-1];}
	}
	printf("%d\n", sum);
	}
	else if (strcmp(x, "OVER") == 0){
	break;}
	if(strcmp(x, "SUM") !=0&&strcmp(x, "OVER") != 0){
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		printf("%d",a[i][k]);
		if(k!=(n-1)){
			printf(" ");
		}
	}
	printf("\n");
	}
}
}
return 0;
}
