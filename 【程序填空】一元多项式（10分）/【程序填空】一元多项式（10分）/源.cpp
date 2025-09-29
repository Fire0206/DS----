#include <iostream>
#include<cstdlib>
using namespace std;
const int MaxExp = 32;//多项式所有项的指数不大于MaxExp
class Poly
{
	int poly[MaxExp + 1];
public:
	Poly();//将poly的所有（MaxExp+1个）存储空间置0
	Poly operator+(Poly&);
	Poly& operator*=(Poly&);//测试数据保证相乘后的最大指数仍<=MaxExp
	double operator()(double x);
	/*有Poly对象p，p(x1)求x为x1时多项式p(x)的值。
	例如，当p是5-1.png时，p(1)为-3
	数学函数pow(a, b)用于求a的b次方，其参数和返回值均为double型
	*/
	friend istream& operator>>(istream&, Poly&);

	/*多项式输入。首先是项数，然后是每项的系数、指数
	例如多项式5-1.png，输入4 3 5 1 3 -1 1 -6 0
	*/
	friend ostream& operator<<(ostream&, const Poly&);

	/*多项式输出。符合数学上多项式的书写习惯。
	指数降序。指数(>1时)紧跟x输出
	系数全为0时输出0
	例如多项式5-1.png，输出3X5+X3-X-6
	*/

};
/********** Write your code here! **********/
Poly::Poly() {
	for (int i = 0;i < MaxExp + 1;i++) {
		poly[i] = 0;
	}
}
Poly Poly::operator+(Poly& p) {
	Poly temp = *this;
	for (int i = 0;i < MaxExp + 1;i++) {
		temp.poly[i] += p.poly[i];
	}
	return temp;
}
Poly& Poly::operator*=(Poly& p) {
	Poly temp;
	for (int i = 0;i < MaxExp + 1;i++) {
		for (int j = 0;j < MaxExp + 1;j++) {
			temp.poly[i + j] += poly[i] * p.poly[j];
		}
	}
	*this = temp;
	return *this;
}
double Poly::operator()(double x) {
	double sum = 0;
	for (int i = 0;i < MaxExp + 1;i++) {
		sum += poly[i] * pow(x, i);
	}
	return sum;
}
istream& operator>>(istream & is, Poly & p){
	int n;
	is >> n;
	int rank, number;
	for (int i = 0;i < n;i++) {
		cin >> number >> rank;
		p.poly[rank] = number;
	}
	return is;
}
ostream& operator<<(ostream& os, const Poly& p) {
	bool is_zero_poly = true; // 标志是否为零多项式
	// 检查是否为零多项式
	for (int i = 0; i <= MaxExp; i++) {
		if (p.poly[i] != 0) {
			is_zero_poly = false;
			break;
		}
	}

	if (is_zero_poly) {
		os << "0"; // 如果是零多项式，直接输出 "0"
		return os;
	}

	bool first_term_printed = false; // 标志是否已经打印了第一个非零项

	// 从最高指数开始遍历到最低指数
	for (int i = MaxExp; i >= 0; i--) {
		int coeff = p.poly[i]; // 获取当前项的系数

		if (coeff == 0) {
			continue; // 如果系数为0，跳过该项
		}

		// 处理项之间的符号
		if (first_term_printed) { // 如果已经打印过至少一个项
			if (coeff > 0) {
				os << "+"; // 正系数项前加 '+'
			}
			// 负系数项前面已经在下面处理了 '-'
		}
		else { // 如果是第一个要打印的项
			if (coeff < 0) {
				os << "-"; // 第一个负系数项前加 '-'
			}
		}

		// 处理系数的输出
		// 规则：当系数为 1 或 -1 且指数不是 0 时，不输出 1 或 -1
		if (abs(coeff) != 1 || i == 0) { // 如果系数绝对值不为1，或者它是常数项（指数为0）
			os << abs(coeff); // 输出系数的绝对值
		}

		// 处理 X 和指数的输出
		if (i > 0) { // 如果不是常数项
			os << "X"; // 输出 'X'
			if (i > 1) { // 如果指数大于1
				os  << i; // 输出 '^' 和指数
			}
			// 如果指数为1，只输出 'X'，不需要 'X^1'
		}
		first_term_printed = true; // 设置标志，表示已经有项被打印
	}
	return os; // 返回输出流
}
/*******************************************/
int main()
{
	Poly p, q, r;
	double x;
	int T, N;
	char type;
	cin >> T;
	while (T--)
	{
		cin >> p >> q;
		cin >> N;
		while (N--)
		{
			cin >> type;
			switch (type) {
			case'+':
				r = p + q;
				cout << "(" << p << ")+(" << q << ")=" << r << endl;
				break;
			case'x':
				cin >> x;
				cout << p(x) << endl;
				break;
			case'*':
				p *= q;
				cout << p << endl;
				break;
			default:
				N++;
				cout << "error! pls input again!" << endl;
			}
		}
	}
	return 0;
}
