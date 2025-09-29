#include<iostream>
using namespace std;

class Appliance {
protected:
	int id, power;
public:
	Appliance(int i,int p):id(i),power(p){}
	void print(){}
};

class Fan :virtual public Appliance {
protected:
	int direction, windPower;
public:
	Fan(int i, int p,int d,int w):Appliance(i,p),direction(d),windPower(w){}
	void Direction(int m) {
		direction = m;
	}
	void Wind(int m) {
		windPower = m;
	}
};

class Humidifier :virtual public Appliance {
protected:
	double currentVol, maxVol;
public:
	Humidifier(int i, int p,double c,double m) :Appliance(i, p), currentVol(c),maxVol(m) {}
	int Warning() {
		if (currentVol >= maxVol * 0.5) {
			return 1;
		}
		else if (currentVol < maxVol * 0.5 && currentVol >= maxVol * 0.1) {
			return 2;
		}
		else{
			return 3;
		}
	}
};

class SuperFan :public Fan, public Humidifier {
protected:
	int gears;
public:
	SuperFan(int i, int p, int d, int w, double c, double m, int g) :Appliance(i, p),
		Fan(i, p, d, w), Humidifier(i, p, c, m), gears(g){ }
	void Gears(int m) {
		gears = m;
		if (m == 0) {
			
		}
		else if (m == 1) {
			Direction(0);
			Wind(1);
		}
		else if (m == 2) {
			Direction(1);
			Wind(2);
		}
		else if (m == 3) {
			Direction(1);
			Wind(3);
		}
	}
	void print (){
		cout << "加湿风扇--档位" << gears << endl;
		cout << "编号" << id << "--功率" << power << "W" << endl;
		if (direction == 0) {
			cout << "定向吹风";
		}
		else if(direction == 1){
			cout << "旋转吹风";
		}
		cout << "--风力" << windPower << "级" << endl;
		cout << "实际水容量" << currentVol << "升--";
		if (Warning() == 1) {
			cout << "水量正常" << endl;
		}
		else if (Warning() == 2) {
			cout << "水量偏低" << endl;
		}
		else if (Warning() == 3) {
			cout << "水量不足" << endl;
		}
		cout << endl;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		int id, power;
		int direction, windPower;
		double currentVol, maxVol;
		int gears;
		int m;
		cin >> id >> power >> direction >> windPower >> currentVol >> maxVol >> gears;
		cin >> m;
		SuperFan fan(id, power, direction, windPower, currentVol, maxVol, gears);
		fan.Gears(m);
		fan.print();
	}
	return 0;
}