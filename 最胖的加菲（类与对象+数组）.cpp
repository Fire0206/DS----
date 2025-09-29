#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Cat{
private:
	string name;
	int weight;
public:
	void getName(){
		cin>>name;
	}
	void getWeight(){
		cin>>weight;
	}
	string coutName() const {
    return name;
	}
	int coutWeight() const {
    return weight;
	}
};

bool compare(const Cat& a,const Cat& b){
	return (a.coutWeight()<b.coutWeight());
}
int main(){
	int n;
	cin>>n;
	Cat *cats = new Cat[n];
	for(int i=0;i<n;i++){
		cats[i].getName();
		cats[i].getWeight();
	}
	sort(cats,cats+n,compare);
	for(int i=0;i<n;i++){
		cout<<cats[i].coutName();
		if(i!=n-1){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
	delete[] cats;
	return 0;
}
