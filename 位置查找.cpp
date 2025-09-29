#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int L, K;
        scanf("%d %d", &L, &K);
        int arr[1000];
        for (int i = 0; i < L; i++) {
            scanf("%d", &arr[i]); 
        }
        int a = -1;
        for (int i = 0; i < L; i++) {
            if (arr[i] == K) {
                a = i + 1;
                break;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}
