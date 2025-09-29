#include<iostream>
using namespace std;
class Tree{
public:
    Tree(){
    	ages = 1;
	}
    Tree(int age){
    	ages = age;
	}
    void grow(int years){
    	ages += years;
	}
    void age(){
    	cout<<ages<<endl;
	}
    
private:
    int ages;//Ê÷Áä
};
int main()
{
	int years,ages;
	Tree t;
	cin>>years;
	t.grow(years);
	t.age();
	cin>>ages>>years;
	Tree t2(ages);
	t2.grow(years);
	t2.age();
	return 0;
}
