#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for(int v=0;v<T;v++){
        char str[1000];
        fgets(str,1000,stdin);
        int i = 0;
        while (str[i]!= '\0') {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32; 
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
            i++;
        }
		if (str[i - 1] == '\n') {
            str[i - 1] = '\0';
        }
        printf("%s\n", str);
    }
    return 0;
}
