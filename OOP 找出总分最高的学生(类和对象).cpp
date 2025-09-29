#include<iostream>
#include<string>
using namespace std;
class Stu{
public:
	string id;
	string name;
	int sco1;
	int sco2;
	int sco3;
	int sum;
};
int main(){
	int n;
	cin>>n;
	Stu maxStu;
	maxStu.sum=-1;
	for(int i=0;i<n;i++){
		Stu currentStu;
		cin>>currentStu.id>>currentStu.name
		>>currentStu.sco1>>currentStu.sco2
		>>currentStu.sco3;
		currentStu.sum=currentStu.sco1+currentStu.sco2+currentStu.sco3;
		if(currentStu.sum>maxStu.sum){
			maxStu=currentStu;
		}
	}
	cout<<maxStu.name<<" "<<maxStu.id<<" "<<maxStu.sum;
	return 0;
}
