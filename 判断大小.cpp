#include <stdio.h>
int main() {
    int a, b;
    int min, max;
    float average;
    scanf("%d %d", &a, &b);
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
    printf("按数值由小到大的顺序输出：%d %d\n", min, max);
    average = (float)(a + b) / 2;
    printf("这两个数的均值为：%.2f\n", average);
    if (max % min == 0) {
        printf("Getit!\n");
    } else {
        printf("Good Luck!\n");
    }

    return 0;
}
