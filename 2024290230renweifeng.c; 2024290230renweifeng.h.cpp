#include<stdio.h>
#include<math.h>
#include<string.h>
float average(float a,float b,float c);
int DecompositionOfThreeDigitNumbers(int a);
int lowercase(char a);
void rootsOfEquation(int a,int b,int c,int d,float e,float f);
void compareSize(int a,int b,int c,int max,int mid,int min);
void cin(int a[],int n);
void cout(int a[],int n);
void bubble(int a[],int n);
int primeNumber(int N);
int gcd(int a, int b);
int matrix(int a[][100],int n);
int add(int a,int b);
int fibonacci(int n);
void swap(int *x, int *y);
void add(char a[],char b[]);
int Substring(char str1[],char str2[],int index);



int main(){
	return 0;
}

float average(float a,float b,float c)
{
	float d=(a+b+c)/3;
	return d;
}

int DecompositionOfThreeDigitNumbers(int a)
{
	int b=a/100,c=(a%100)/10,d=a%10,e=b+c+d;
	return e;
}

int lowercase(char a)
{
	char b=a+32;
	return b;
}

void rootsOfEquation(float a,float b,float c,float x1,float x2)
{
	float delt,d,e;
	delt=b*b-4*a*c;
	if(a==0){x1=-b/c;printf("x=%.3f",x1); 
	}
	else{
	switch(delt>=0){
	case 1:
		x1=(-b+sqrt(delt))/(2*a);
		x2=(-b-sqrt(delt))/(2*a);
		printf("x1=%.3f x2=%.3f",x1,x2);break;

	case 0:
		d=-b/2/a;
		e=sqrt(-delt)/(2*a);
		printf("x1=%.3f+%.3fi x2=%.3f-%.3fi",d,e,d,e);break;
			}}
}

void compareSize(int a,int b,int c,int max,int mid,int min)
{
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
}

void cin(int a[],int n){
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}

void cout(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}

void bubble(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int primeNumber(int N){
	int sum;
	for(int i=2;i<=N;i++){
		if(i==2){
			sum+=1;
		}
		else if(i%2!=0){
			int a=1;
			for(int j=2;j<=(sqrt(i));j++){
				if(i%j==0){
				a=0;	
				break;}
			}
			if(a){
				sum+=1;
			}
		}
	}
	return sum;
}   

int gcd(int a, int b)
{
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int matrix(int a[][100],int n)
{
	int sum=0;
	for(int j=0;j<n;j++){
			int max=a[0][j];
			int num=0,sum=0;
			for(int i=0;i<n;i++){
				if(a[i][j]>max){
					max=a[i][j];
					num=i;
				}
				sum+=a[i][j];
			}
	}
	return sum;
}

int add(int a,int b){
	int c=a+b;
	return c;
}

int fibonacci(int n)
{
	int a=0,b=1,c=0;
	for(int i=1;i<n-2;i++)
	{
		c=add(a,b);
		a=b;
		b=c;
	}
	return c;
}

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(int a[], int n){
	for(int i=0;i<(n/2);i++){
		int temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
}

void add(char a[],char b[]){
	int len=strlen(a);
	int i;
	for(i=0;b[i]!='\0';i++){
		a[len+i]=b[i];
	}
	a[len+i+1]='\0';
}

int Substring(char str1[],char str2[],int index){
	int len=strlen(str1);
	int j=0;
	if(index<0||index>=len){
		return 0;
	}
	else{
		for(j=0;j<(len-index);j++){
			str2[j]=str1[index+j];
		}
		str2[j] = '\0';
    	return 1;
	}
} 
