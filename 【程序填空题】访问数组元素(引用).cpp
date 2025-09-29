#include <iostream>
using namespace std;

#define N 1000

// 补齐put函数
/********** Write your code here! **********/
int& put(int num[],int i){
	return num[i];
} 
/*******************************************/
int main()
{
    int num[N];
    int t, n, sum, i;

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> put(num, i); // 输入num[i]的值
        }
        for (sum = 0, i = 0; i < n; i++)
            sum += num[i];
        cout << "sum=" << sum << endl;
    }
    return 0;
}

