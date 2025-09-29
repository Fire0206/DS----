#include <stdio.h>

int main() {
    float a, sum;
    int i;

    sum = 0;
    a = 1;

    // 设定循环执行次数，根据多项式的项数确定，这里共11项（从1到1/1024）
    for (i = 0; i < 11; i++) {
        sum += a;
        a *= -0.5;
    }

    printf("%f", sum);

    return 0;
}
