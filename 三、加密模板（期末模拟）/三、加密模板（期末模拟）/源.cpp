#include<iostream>
using namespace std;

// 函数模板：返回数组中的最大值 (您的实现是正确的)
template<class T>
T Max(T arr[], int len) {
	T max = arr[0];
	for (int i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

// 类模板：加密类
template<class T>
class Cryption {
private: // 根据题目要求，属性都不是public
	T ptxt[100]; //明文
	T ctxt[100]; //密文
	T key;       //密钥
	int len;     //长度

public:
	Cryption(T tk, T tt[], int tl); //参数依次对应密钥、明文、长度
	void Encrypt(); //加密
	void Print() //打印，无需改造
	{
		int i;
		for (i = 0; i < len - 1; i++)
			cout << ctxt[i] << " ";
		cout << ctxt[i] << endl;
	}
};

// 构造函数的类外实现 (您的实现是正确的)
template<class T>
Cryption<T>::Cryption(T tk, T tt[], int tl) {
	len = tl;
	key = tk;
	for (int i = 0; i < len; i++) {
		ptxt[i] = tt[i];
	}
	// 这部分初始化是好习惯，但对于当前题目不是必须的
	for (int i = len; i < 100; i++) {
		ptxt[i] = 0;
	}
}

// 加密函数的类外实现 (修正后)
template<class T>
void Cryption<T>::Encrypt() {
	// 1. 在明文 ptxt 中找出最大值
	T max = Max(ptxt, len);

	// 2. 计算偏离值并加上密钥，将结果存入密文数组 ctxt
	for (int i = 0; i < len; i++) {
		ctxt[i] = (max - ptxt[i]) + key;
	}
}

// 主函数 (根据题目要求，不能修改)
int main()
{
	int i;
	int length; //长度
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];

	//整数加密
	cin >> ik >> length;
	for (i = 0; i < length; i++)
		cin >> itxt[i];
	Cryption<int> ic(ik, itxt, length);
	ic.Encrypt();
	ic.Print();

	//浮点数加密
	cin >> dk >> length;
	for (i = 0; i < length; i++)
		cin >> dtxt[i];
	Cryption<double> dc(dk, dtxt, length);
	dc.Encrypt();
	dc.Print();

	//字符加密
	cin >> ck >> length;
	for (i = 0; i < length; i++)
		cin >> ctxt[i];
	Cryption<char> cc(ck, ctxt, length);
	cc.Encrypt();
	cc.Print();

	return 0;
}