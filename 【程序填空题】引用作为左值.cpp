// 根据主函数，补齐input,output,find_ele函数和头文件
/********** Write your code here! **********/
#include<iostream>
using namespace std;
void input(int num[],int m){
	for(int i=0;i<m;i++){
		cin>>num[i];
	}
}
void output(int num[],int m){
	for(int i=0;i<m;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
}
int &find_ele(int num[],int m){
	for(int i=0;i<m;i++){
		if(num[i]%2==0){
			return num[i];
		}
	}
	return num[m-1];
}
/*******************************************/
int main()
{
    int *num, m, t;

    cin >> t;
    while (t--)
    {
        cin >> m;
        // 为数组num动态分配m个整数空间
/********** Write your code here! **********/
		num=new int[m];
		
/*******************************************/
		input(num, m); // 输入m个数组元素
        find_ele(num, m) *= 2;
        output(num, m); // 输出m个数组元素
        delete[] num;
    }
    return 0;
}
