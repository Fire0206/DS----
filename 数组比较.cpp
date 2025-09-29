#include <stdio.h>
int main() {
    int a[10];
    int b[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] > b[i]) {
            count1++;
        } else if (b[i] > a[i]) {
            count2++;
        }
    }
    if (count1 > count2) {
        printf("a>b\n");
    } else if (count2 > count1) {
        printf("a<b\n");
    } else {
        printf("a=b\n");
    }
    return 0;
}
