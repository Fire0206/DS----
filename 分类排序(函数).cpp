#include<stdio.h>
void swap(int *x, int *y);
void sort_desc(int a[], int n);
void sort(int a[], int n);
int find(int a[],int n,int value);
void display(int a[], int n);
void reverse(int a[], int n);

int main()
{
	int t,value,n;
	int a[20];
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		for(int j=0;j<10;j++){
			scanf("%d",&a[j]);}
		scanf("%d",&value);
		if((value%2!=0)&&(find(a,10,value)!=-1))
		{
			int b=find(a,10,value);
			a[b]=0;
			for(int y=b;y<10;y++){
				a[y]=a[y+1];
			}
			n=9;
			sort(a,n);
		}
		else if((value%2==0)&&(find(a,10,value)==-1)){
			a[10]=value;
			n=11;
			sort_desc(a,n);
		}
		else{
			int left = 0;
    		int right = 9;
    		while (left < right) {
    
        		while (left < right && a[left] % 2 == 1) {
            	left++;
        		}
        
        		while (left < right && a[right] % 2 == 0) {
            	right--;
        		}
        		
       			if (left < right) {
            	swap(&a[left], &a[right]);
            	left++;
            	right--;
        		}
    		}
			n=10;
    		sort_desc(a, left);
    		sort_desc(a + left, 10 - left);
		}
		display(a,n);
	}
	return 0;
}

void display(int a[], int n){
	for(int x=0;x<n;x++){
		printf("%d",a[x]);
		if(x!=n-1) 
		printf(" ");
		else
		printf("\n");
	}
}

int find(int a[],int n,int value){
	int z;
	for(z=0;z<n;z++){
		if(a[z]==value)
		return z;
	}
	return -1;
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

void reverse(int a[], int n){
	for(int j=0;j<(n/2);j++){
		int tenp=a[j];
		a[j]=a[n-1-j];
		a[n-1-j]=tenp;
	}
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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
