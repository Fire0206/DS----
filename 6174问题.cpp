#include<stdio.h>
void swap(int *x, int *y);
void sort(int a[], int n);
void sort_desc(int a[], int n);
int circle(int num);
int main(){
	int n,num;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		scanf("%d",&num);
		printf("%d\n",circle(num));
	}
	return 0;
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sort(int a[], int n){
	for(int u=0;u<(n-1);u++){
		for(int m=0;m<(n-u-1);m++){
			if(a[m]>a[m+1]){
				swap(&a[m], &a[m+1]);
			}
		}
	}
}
void sort_desc(int a[], int n) {
    for(int u=0;u<(n-1);u++){
		for(int m=0;m<(n-u-1);m++){
			if(a[m]<a[m+1]){
				swap(&a[m], &a[m+1]);
			}
		}
	}
}
int circle(int num){
	int sum=0,x,y;
	int a[4];
	while(num!=6174){
	a[0]=num/1000;
	a[1]=(num%1000)/100;
	a[2]=(num%100)/10;
	a[3]=num%10;
	sort(a,4);
	x=a[0]*1000+a[1]*100+a[2]*10+a[3];
	sort_desc(a,4);
	y=a[0]*1000+a[1]*100+a[2]*10+a[3];
	num=y-x;
	sum+=1;
	}
	sum+=1;
	return sum;
}
