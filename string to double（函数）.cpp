#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double strToDouble(char str[]) {
    int i, j, flag = 0, decimalPlace = 0;
    double number, sum = 0;
    char a[30]; 

    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if ((i == 0 && str[i] == '-') || (isdigit(str[i]))) {
            a[j] = str[i];
            j++;
        }

        if (str[i] == '.' && flag == 0) {
            if (j == 0 || a[j - 1] == '-') {
                a[j] = '0';
                a[j + 1] = '.';
                decimalPlace = j + 1;
                j += 2;
            }
            else {
                a[j] = '.';
                decimalPlace = j;
                j++;
            }
            flag++;
        }
    }

    if (decimalPlace == 0)
        decimalPlace = j;

    for (i = 0; i < j; i++) {
        if (isdigit(a[i]))
            a[i] -= '0';
    }

    for (i = 0; i < j; i++) {
        if (a[i] == '-')
            continue;
        if (i < decimalPlace) {
            number = pow(10, decimalPlace - i - 1) * a[i];
            sum += number;
        }
        else if (i > decimalPlace) {
            number = pow(10, decimalPlace - i) * a[i];
            sum += number;
        }
    }

    if (j == 0)
        return 0;

    if (a[0] == '-')
        sum *= -1;

    return sum;
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); 
    while (t--) {
        char str[20]; 
        fgets(str, 20, stdin);
        str[strcspn(str, "\n")] = '\0'; 
        double result = strToDouble(str);
        printf("%.6g\n", result);
    }
    return 0;
}
