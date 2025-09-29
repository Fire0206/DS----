#include <stdio.h>
int main()
{
    int A,B;  
    scanf("%d %d", &A, &B);
    if (A%B==0&&B%A!=0){printf("1");} 
	else if (A%B!=0&&B%A==0) 
	{printf("2\n");} 
	else if (A%B==0&&B%A==0) 
	{printf("3");} 
	else {printf("4");}
    return 0;
}
//输入6 3 输出1
//输入3 6 输出2
//输入6 6 输出3
//输入3 5 输出4 
