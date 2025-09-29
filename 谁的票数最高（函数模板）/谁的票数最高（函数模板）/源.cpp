#include <iostream>
#include<cstring>
using namespace std;
template <class T>
void check(int n)
{
	T* a = new T[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; 
	}
	int max = 0; 
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i] == a[j])
			{
				count++;
			}
		}
		if (count > max)
		{
			max = count;
			index = i;
		}
	}
	cout << a[index] << ' ' << max << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char x;
		cin >> x;
		int num;
		cin >> num;
		if (x == 'I') check<int>(num);
		else if (x == 'C') check<char>(num);
		else if (x == 'S') check<string>(num);
		
	}
	return 0;
}