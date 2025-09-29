#include<iostream>
using namespace std;
class Mental {
private:
	int hardness, weight, volume;
public:
	Mental(int h,int w,int v):hardness(h),weight(w),volume(v){}
	Mental operator+(const Mental& m) {
		Mental temp = *this;
		temp.hardness += m.hardness;
		temp.weight += m.weight;
		temp.volume += m.volume;
		return temp;
	}
	Mental operator*(int n) {
		Mental temp = *this;
		temp.volume *= n;
		return temp;
	}
	Mental operator++() {
		++hardness;
		weight = (int)weight * 1.1;
		volume= (int)volume * 1.1;
		return *this;
	}
	Mental operator--(int) {
		hardness--;
		weight = (int)weight * 0.9;
		volume = (int)volume * 0.9;
		return *this;
	}
	void print() {
		cout << "硬度" << hardness << "--重量" << weight << "--体积" << volume << endl;
	}
};
int main() {
	int hardness, weight, volume;
	cin >> hardness >> weight >> volume;
	Mental m1(hardness, weight, volume);
	cin >> hardness >> weight >> volume;
	Mental m2(hardness, weight, volume);
	Mental m3 = m1 + m2;
	m3.print();
	int n;
	cin >> n;
	Mental m4 =m1*n;
	m4.print();
	Mental m5=++m1;
	m5.print();
	Mental m6 = m2--;
	m6.print();
	return 0;
}