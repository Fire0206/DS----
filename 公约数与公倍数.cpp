#include<stdio.h>
int gcd(int a, int b) {
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{	int m,n;
	scanf("%d %d",&m,&n);
    int max=gcd(m,n);
    int min=m*n/max;
    printf("%d %d",max,min);
    return 0;
}
