#include <stdio.h>
int main() {
    double a, b, c, d;
    double max1, max2, max3, min;
    double average; 
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if (a >= b && a >= c && a >= d) {
        max1 = a;
        if (b >= c && b >= d) {
            max2 = b;
            if (c >= d) {
                max3 = c;
                min = d;
            } else {
                max3 = d;
                min = c;
            }
        } else if (c >= b && c >= d) {
            max2 = c;
            if (b >= d) {
                max3 = b;
                min = d;
            } else {
                max3 = d;
                min = b;
            }
        } else {
            max2 = d;
            if (b >= c) {
                max3 = b;
                min = c;
            } else {
                max3 = c;
                min = b;
            }
        }
    } else if (b >= a && b >= c && b >= d) {
        max1 = b;
        if (a >= c && a >= d) {
            max2 = a;
            if (c >= d) {
                max3 = c;
                min = d;
            } else {
                max3 = d;
                min = c;
            }
        } else if (c >= a && c >= d) {
            max2 = c;
            if (a >= d) {
                max3 = a;
                min = d;
            } else {
                max3 = d;
                min = a;
            }
        } else {
            max2 = d;
            if (a >= c) {
                max3 = a;
                min = c;
            } else {
                max3 = c;
                min = a;
            }
        }
    } else if (c >= a && c >= b && c >= d) {
        max1 = c;
        if (a >= b && a >= d) {
            max2 = a;
            if (b >= d) {
                max3 = b;
                min = d;
            } else {
                max3 = d;
                min = b;
            }
        } else if (b >= a && b >= d) {
            max2 = b;
            if (a >= d) {
                max3 = a;
                min = d;
            } else {
                max3 = d;
                min = a;
            }
        } else {
            max2 = d;
            if (a >= b) {
                max3 = a;
                min = b;
            } else {
                max3 = b;
                min = a;
            }
        }
    } else {
        max1 = d;
        if (a >= b && a >= c) {
            max2 = a;
            if (b >= c) {
                max3 = b;
                min = c;
            } else {
                max3 = c;
                min = b;
            }
        } else if (b >= a && b >= c) {
            max2 = b;
            if (a >= c) {
                max3 = a;
                min = c;
            } else {
                max3 = c;
                min = a;
            }
        } else {
            max2 = c;
            if (a >= b) {
                max3 = a;
                min = b;
            } else {
                max3 = b;
                min = a;
            }
        }
    }

    // 按由大到小的顺序输出四个数
    printf("按由大到小的顺序输出：%.2lf %.2lf %.2lf %.2lf\n", max1, max2, max3, min);

    // 计算并输出四个数的均值
    average = (max1 + max2 + max3 + min) / 4;
    printf("这四个数的均值为：%.2lf\n", average);

    return 0;
}
