#include<iostream>
using namespace std;
class CVehicle {
protected:
	int max_speed, speed, weight;
public:
	CVehicle(int m,int s, int w):max_speed(m),speed(s),weight(w){}
	void display() {
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:"<<weight << endl;
	}
};

class CBicycle :virtual public CVehicle {
protected:
	int height;
public:
	CBicycle(int m, int s, int w,int h):CVehicle(m,s,w),height(h){}
	void display1() {
		cout << "Bicycle:" << endl;
		CVehicle::display();
		cout << "height:" << height << endl;
	}
};

class CMotocar :virtual public CVehicle {
protected:
	int seat_num;
public:
	CMotocar (int m, int s, int w, int seat) :CVehicle(m, s, w), seat_num(seat){}
	void display2() {
		cout << "Motocar:" << endl;
		CVehicle::display();
		cout << "seat_num:" << seat_num << endl;
	}
};

class CMotocycle :public CBicycle, public CMotocar {
public:
	CMotocycle(int m, int s, int w, int h,int seat):CVehicle(m, s, w),CBicycle(m,s,w,h),CMotocar(m,s,w,seat){}
	void display3() {
		cout << "Motocycle:" << endl;
		CVehicle::display();
		cout << "height:" << height << endl;
		cout << "seat_num:" << seat_num << endl;
	}
};
int main() {
	int max_speed, speed, weight,height, seat_num;
	cin>>max_speed>> speed>>weight>> height>> seat_num;
	CVehicle v(max_speed, speed, weight);
	cout << "Vehicle:" << endl;
	v.display();
	cout << endl;

	CBicycle b(max_speed, speed, weight, height);
	b.display1();
	cout << endl;

	CMotocar m(max_speed, speed, weight, seat_num);
	m.display2();
	cout << endl;
	
	CMotocycle c(max_speed, speed, weight, height, seat_num);
	c.display3();
	cout << endl;
	return 0;
}