#include<iostream>
#include<string>
using namespace std;
class Cat {
private:
	string name;
	int weight;
public:
	Cat(){}
	Cat(string n,int w):name(n),weight(w){}
	string getName() {
		return name;
	}
	string getWeight()
	{
		return weight;
	}
	
};
int main() {
	int t;
	cin >> t;
	string name;
	int weight;
	Cat* cats = new Cat[t];
	for (int i = 0;i < t;i++) {
		cin >> name >> weight;
		cats[i] = Cat(name, weight);
	}

	for (int i = 0;i < t;i++) {
		cout << cats[i].getName();
		if (i != t - 1) {
			cout << " ";
		}
	}
	return 0;
}