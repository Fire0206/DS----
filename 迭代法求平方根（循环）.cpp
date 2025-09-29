#include <stdio.h>
#include <math.h>
int main() {
    double a;
    scanf("%lf", &a);
    double x0 = 1;
    double x1 = 0.5 * (x0 + a / x0);
    while (fabs(x1 - x0) >= 0.00001){
        x0 = x1;
		x1 = 0.5 * (x0 + a / x0);
    }
    printf("%.3lf\n", x1);
    return 0;
}
