#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a;
	scanf("%c",&a);
	switch(a)
	{case'A': printf("Menu:A(dd) D(elete) S(ort) Q(uit),select one:\ndata is added");
            break;
    case'D': printf("Menu:A(dd) D(elete) S(ort) Q(uit),select one:\ndata is deleted");
            break;      
    case'S': printf("Menu:A(dd) D(elete) S(ort) Q(uit),select one:\ndata is sorted");
            break;       
    case 'Q':
            exit(0);      
	}
	return 0;
}
/*输入A 输出Menu:A(dd) D(elete) S(ort) Q(uit),select one：
data is added 
输入D 输出Menu:A(dd) D(elete) S(ort) Q(uit),select one:
data is deleted
输入S 输出Menu:A(dd) D(elete) S(ort) Q(uit),select one: 
data is sorted
输入Q 程序结束 */
