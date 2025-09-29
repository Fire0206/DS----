#include <stdio.h>
void ans(int num, int money) 
{
    int count = 0;
    int solutions[100][3];
    for (int x = 1; x <= num; x++) {
        for (int y = 1; y <= num - x; y++) {
            int z = num - x - y;
            if (5 * x + 3 * y + z / 3 == money && z % 3 == 0) {
                solutions[count][0] = x;
                solutions[count][1] = y;
                solutions[count][2] = z;
                count++;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", solutions[i][0], solutions[i][1], solutions[i][2]);
    }
}
int main() 
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int num, money;
        scanf("%d %d", &num, &money);
        ans(num, money);
    }
    return 0;
}
