#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
template<class T>
void mysort(T* a, int beg, int end)
{
	sort(a + beg, a + end);
}
int main()
{
	int t, n, beg, end, i;
	string code[3] = { "int","string","float" }, instru;
	cin >> t;
	while (t--)
	{
		cin >> instru >> n;
		cin.ignore(2);
		cin >> beg;
		cin.ignore();
		cin >> end;
		cin.ignore(4);
		if (beg >= end)
			end = beg = 0;
		if (beg < 0)
			beg = 0;
		if (end > n)
			end = n;
		if (instru == code[0])
		{
			int* a = new int[n];
			for (i = 0; i < n; i++)
				cin >> a[i];
			mysort(a, beg, end);
			cout << '[';
			for (i = 0; i < n; i++)
			{

				if (i == 0)
					cout << a[0];
				else if (i == n - 1)
					cout << ", " << a[i];
				else
					cout << ", " << a[i];
			}
			cout << ']' << endl;
			delete[] a;
		}
		else if (instru == code[1])
		{
			string* a = new string[n];
			for (i = 0; i < n; i++)
				cin >> a[i];
			mysort(a, beg, end);
			cout << '[';
			for (i = 0; i < n; i++)
			{

				if (i == 0)
					cout << a[0];
				else if (i == n - 1)
					cout << ", " << a[i];
				else
					cout << ", " << a[i];
			}
			cout << ']' << endl;
			delete[] a;
		}
		else
		{
			float* a = new float[n];
			for (i = 0; i < n; i++)
				cin >> a[i];
			mysort(a, beg, end);
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << '[';
			for (i = 0; i < n; i++)
			{

				if (i == 0)
					cout << a[0];
				else if (i == n - 1)
					cout << ", " << a[i];
				else
					cout << ", " << a[i];
			}
			cout << ']' << endl;
			delete[] a;
		}
	}
	return 0;
}