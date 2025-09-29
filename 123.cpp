#include <stdio.h>

void checkCombination(int arr[], int n, int k) {
 
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum == k) {
            printf("YES\n");
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    printf("%d", arr[j]);
                    if(j!=n-1){
                    	printf(" ");
					}
                }
            }
            printf("\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        checkCombination(arr, n, k);
    }
    return 0;
}
