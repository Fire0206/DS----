#include<iostream>
using namespace std;
class Complex{
private:
	int a;
	int b;
	
public:
	Complex(){
		a=1;
		b=1;
	}
	Complex(int a1,int b1){
		a=a1;
		b=b1;
	}
	Complex add(const Complex& p) {
        return Complex(a + p.a, b + p.b);
    }
    Complex dif(const Complex& p) {
        return Complex(a - p.a, b - p.b);
    }
    void print() {
        if (a == 0 && b == 0) {
            cout << 0 << endl;
        } else if (a == 0) {
            if (b == 1) {
                cout << "i" << endl;
            } else if (b == -1) {
                cout << "-i" << endl;
            } else {
                cout << b << "i" << endl;
            }
        } else if (b == 0) {
            cout << a << endl;
        } else {
            cout << a;
            if (b > 0) {
                if (b == 1) {
                    cout << "+i" << endl;
                } else {
                    cout << "+" << b << "i" << endl;
                }
            } else {
                if (b == -1) {
                    cout << "-i" << endl;
                } else {
                    cout << b << "i" << endl;
                }
            }
        }
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--){
		int a1,a2,b1,b2;
		cin>>a1>>b1>>a2>>b2;
		Complex p1(a1,b1);
		Complex p2(a2,b2);
		Complex sum=p1.add(p2);
		Complex dif=p1.dif(p2);
		cout<<"sum:";
		sum.print();
		cout<<"remainder:";
		dif.print();
	}
	return 0;
} 
