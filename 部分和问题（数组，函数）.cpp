#include <stdio.h>

void in(int a[], int n, int vis[]);
void dfs(int index, int sum, int a[], int vis[], int n, int k, int *found);

int main() {
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[1000];
        int vis[1000];
        in(a, n, vis);
        int found = 0;  
        dfs(0, 0, a, vis, n, k, &found);
        if (!found) { 
            printf("NO\n");
        }
    }
    return 0;
}

void in(int a[], int n, int vis[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        vis[i] = 0;
    }
}

void dfs(int index, int sum, int a[], int vis[], int n, int k, int *found) {
    if (index == n || sum == k) {
        if (sum == k) {
            *found = 1; 
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                if (vis[i]) {
                    printf("%d", a[i]);
                    if(i!=n-1){
                    	printf(" ");
					}
                }
            }
            printf("\n");
            return;
        }
        return;
    }

    vis[index] = 1;
    dfs(index + 1, sum + a[index], a, vis, n, k, found);
 
    vis[index] = 0;
    dfs(index + 1, sum, a, vis, n, k, found);
}
