#include <stdio.h>
int gys(int a, int b) 
{
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int gbs(int a, int b)
 {
    return a * b / gys(a, b);
}
int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        int max = gys(num1, num2);
        int min = gbs(num1, num2);
        printf("%d %d\n", max, min);
    }
    printf("\n");
    return 0;
}
