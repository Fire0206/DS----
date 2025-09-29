#include <stdio.h>
#define N 100


int ReadScore(int a[N]) 
{
    int i = 0, score = 0;
    while (1) 
    {
        scanf_s("%d", &a[i]);
        if (a[i] == -1) 
        {// 读取学生成绩，输入 -1 结束输入，返回有效成绩数量
            break;
        }
        i++;
        score++;
    }
    return score;
}

double Average(int a[N], int score) 
{
    int sum = 0;
    for (int i = 0; i < score; i++)
    {
        sum += a[i];
    }
    return (double)sum / score;
}

int check(int a[N], int score, double average) 
{

    int count = 0;
    for (int i = 0; i < score; i++) 
    {
        if (a[i] > average) 
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int a[N];
    int score = ReadScore(a);
    if (score > 0)
    {
        double average = Average(a, score);
        printf("平均分为%.2f\n", average);
        int result = check(a, score, average);
        printf("高于平均分的学生人数为%d\n", result);
    }
    else
    {
        printf("没有有效成绩输入。\n");
    }
    return 0;
}