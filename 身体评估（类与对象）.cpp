#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Body{
private:
	string name;
	double height;
	double weight;
	double waistline;
	
public:
	Body(string n, double h, double w, double wl) : name(n), height(h), weight(w), waistline(wl) {}
	string getName(){
		return name;
	}
	int getBMI(){
		return (weight/(height*height)+0.5);
	}
	double getBFR(){
		return (waistline*0.74-(weight*0.082+34.89))/weight;
	}
};
int main(){
	int t;
	cin>>t;
	//Body *bodys=new Body[t];
	for(int i=0;i<t;i++){
		string name;
        double height, weight, waistline;
        cin >> name >> height >> weight >> waistline;
        Body body(name, height, weight, waistline);
        cout << body.getName() << "'s BMI: " << body.getBMI() << "--BFR: "
                  << fixed << setprecision(2) << body.getBFR() << endl;
	}
	return 0;
}
