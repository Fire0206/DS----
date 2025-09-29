#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int arr[10];
        for (int j = 0; j < 10; j++) {
            scanf("%d", &arr[j]); 
        }
        int a = 0;
        for (int k = 0; k < 10; k++) {
            if (arr[k] < 0) {
                a++;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}
