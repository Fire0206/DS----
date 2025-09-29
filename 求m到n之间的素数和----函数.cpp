#include <stdio.h>
int isprime(int x) 
{
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() 
{
    int m, n;
    scanf("%d %d", &m, &n);
    int sum = 0;
    for (int i = m; i <= n; i++) {
        if (isprime(i)) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
