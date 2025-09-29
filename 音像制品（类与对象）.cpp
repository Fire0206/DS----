#include<iostream>
#include<string>
using namespace std;
class Video{
private:
	int type;
	string name;
	int fee;
	int condition;
public:
	void initialize(){
		cin>>type>>name>>fee>>condition;
	}
	int getType(){
		return type;
	}
	string getName(){
		return name;
	}
	string getCondition(){
		if(condition==1){
			return "rented";
		}
		else{
			return "not rented";
		}
	}
	int getFee(){
		return fee;
	}
};
int main(){
	int n,order;
	cin>>n;
	Video video;
	while(n--){
		video.initialize();
		string arr[]={"BF","CD","VCD","DVD"};
		cout<<arr[video.getType()-1]<<"["<<video.getName()<<"]"
		<<video.getCondition()<<endl;
		cin>>order;
		if(order!=0){
			if(video.getCondition()=="not rented"){
				cout<<"No rental"<<endl;
			}
			else{
				cout<<"Rental: "<<(video.getFee())*order<<endl;
			}
		}
	}
	return 0;
}

