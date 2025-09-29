#include <stdio.h>
float fact(int n) 
{
    float a = 1;
    for (int i = 1; i <= n; i++) {
        a *= i;
    }
    return a;
}
int main() 
{
    int n;
    scanf("%d", &n);
    float sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / fact(i);
    }
    printf("%.4f\n", sum);
    return 0;
}
